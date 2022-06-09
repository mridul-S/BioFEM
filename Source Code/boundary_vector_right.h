#include "declearation.h"
#include <stdio.h>

float bc_vector(float x[size][3], float y[size])
{int l,r,ul,ur,dl,dr,mn;

     for (i=0;i<n;i++)
       {



       if(i==((no1-1)*no2))           //   20 or 7
              {   m=ne-ney;
                  y[i]=x[m][2]+x[m+1][3];

              }
       }



            mn=0;
         for(i=((no1-1)*no2+1);i<((no1-1)*no2+6);i++) //21-23 right
           {mn=mn+1;
            if (mn==1)  m=t_ne+2-t_ney;
            else m=m+2;
            //printf("VECTOR  i=[%d]  and [%d]\n",i,m);
            y[i]=x[m][1]+x[m+1][3];

           }





}
