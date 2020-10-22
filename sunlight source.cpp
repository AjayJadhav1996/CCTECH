#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
    struct Point
    {
        float x;
        float y;

    };

    float distCal(Point p, Point q)
    {
        float val = sqrt(((q.x - p.x) * (q.x - p.x)) + ((q.y - p.y) * (q.y - p.y)));
        return val;
    }

    int find_case(Point building_co[], Point p,int num)
    {
 
      for (int j=0;j<num;j++) 
    {   Point i= building_co[j];
            if (p.y > i.y)
                return 1;

       else
                return 2;
        }

        return 0;
    }


   float find_surface(Point building_co[], Point p,int n)
    {
        
        int case1 = find_case(building_co, p,n);
        if (case1 == 1)
        {

           float val[n];

            for (int dist = 0; dist < n; dist++)
            {
                if (dist == 0)
                {

                    val[dist] = distCal(building_co[dist], building_co[dist + 1]) + distCal(building_co[dist], building_co[n - 1]);

                }
                else if (dist == n - 1)
                {
                    val[dist] = distCal(building_co[dist], building_co[dist - 1]) + distCal(building_co[dist], building_co[0]);

                }
                else
                {
                    val[dist] = distCal(building_co[dist], building_co[dist + 1]) + distCal(building_co[dist], building_co[dist - 1]);

                }
            }

            float d_array[n]; 
            int i = 0;
            while (i < n)
            {

                d_array[i] = distCal(building_co[i], p);

                i++;
            }

            float min = d_array[0];
            int arr_index = 0;
            for (int k = 0; k < n; k++)
            {

                if (min > d_array[k])
                {
                    min = d_array[k];
                    arr_index = k;
                }

            }
            cout<<val[arr_index];
        }
        return 0;
    }
 

    int main()
    {
        cout<<"Enter number of Building "<<endl;
        int n;
        cin>>n;
        Point Buildings[4*n];
       cout<<"Enter vertices of Buildings"<<endl;
       for(int i=0;i<4*n;i++) 
       {
       	 cin>>Buildings[i].x>>Buildings[i].y;
	   }
	   
	    Point sun;
	    cout<<"Enter coordinates of Sunlight source"<<endl;
	    cin>>sun.x>>sun.y;
	    cout<<"Length of building exposed to sunlight"<<endl;
        find_surface(Buildings,sun,4*n);                    
		return 0;				 
        }
