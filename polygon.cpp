// A C++ program to check for given point lies inside a given polygon or not
#include <iostream>
using namespace std; 
// Define Infinite (Using INT_MAX caused overflow problems) 
#define INF 10000 
struct Point 
{ 

	int x; 
	int y; 
}; 
// Function checks if point q lies on line segment 'pr' for three colinear points p, q, r
bool onSeg(Point p, Point q, Point r) 
{ 
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
			q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
		return true; 
	return false; 
} 
//  To find orientation of ordered triplet (p, q, r),
//  The orient function returns following values as 0 for p, q and r are colinear, 1-Clockwise 2-Counterclockwise 
int orient(Point p, Point q, Point r) 
{ 
	int val = (q.y - p.y) * (r.x - q.x) - 
			(q.x - p.x) * (r.y - q.y); 

	if (val == 0) return 0;
	return (val > 0)? 1: 2;
} 
// The function areIntersect returns true if line segment 'p1q1' and 'p2q2' intersect. 
bool areIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
	// Find the four orients needed for general and special cases 
	int o1 = orient(p1, q1, p2); 
	int o2 = orient(p1, q1, q2); 
	int o3 = orient(p2, q2, p1); 
	int o4 = orient(p2, q2, q1); 

	// General case 
	if (o1 != o2 && o3 != o4) 
		return true; 

	// Special Cases 
	// case- p1, q1 and p2 are colinear and p2 lies on segment p1q1 
	if (o1 == 0 && onSeg(p1, p2, q1)) return true; 

	// case- p1, q1 and p2 are colinear and q2 lies on segment p1q1 
	if (o2 == 0 && onSeg(p1, q2, q1)) return true; 

	// case- p2, q2 and p1 are colinear and p1 lies on segment p2q2 
	if (o3 == 0 && onSeg(p2, p1, q2)) return true; 

	// case- p2, q2 and q1 are colinear and q1 lies on segment p2q2 
	if (o4 == 0 && onSeg(p2, q1, q2)) return true; 

	return false; // Doesn't fall in any of the above cases 
} 

// isInside function returns true if the point p lies inside the polygon[] with n vertices 
bool isInside(Point polygon[], int n, Point p) 
{ 
	// There must be at least 3 vertices in polygon
	if (n < 3) return false; 
	// Create a point for line segment from p to infinite i.e extreme
	Point ext = {INF, p.y}; 
	// Count intersections of the above line with sides of polygon 
	int count = 0, i = 0; 
	do
	{ 
		int nxt = (i+1)%n; 
		// Check if the line segment from 'p' to 'ext' intersects with the line segment from 'polygon[i]' to 'polygon[nxt]' 
		if (areIntersect(polygon[i], polygon[nxt], p, ext)) 
		{ 
			// If the point 'p' is colinear with line segment 'i-nxt', and check if it lies on segment. If it lies, return true, 
			// otherwise false 
			if (orient(polygon[i], p, polygon[nxt]) == 0) 
			return onSeg(polygon[i], p, polygon[nxt]); 
			count++; 
		} 
		i = nxt; 
	} while (i != 0); 
	// Return true if count is odd, false otherwise 
	return count&1; // Same as (count%2 == 1) 
} 
// Main program to run above functions 
int main() 
{ 
    cout<<"Enter number of polygon vertices"<<endl;
    int numofcor;//number of polygon vertices
    cin>>numofcor;
    Point polygon1[numofcor];
    cout<<"Enter polygon vertices"<<endl;
    for(int j=0;j<numofcor;j++)
    {
    	float u,v;
    	cin>>u>>v;
    	polygon1[j]={u,v};
	}
	int n = sizeof(polygon1)/sizeof(polygon1[0]); 
	cout<<"Enter point p coordinate to check"<<endl;
	float p1,p2;
	cin>>p1>>p2;
	Point p={p1,p2};
	isInside(polygon1, n, p)? cout << "True \n": cout << "False \n"; 
	return 0; 
}

