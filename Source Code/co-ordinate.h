#include "declearation.h"
#include<stdio.h>


float insert_co_ordinate()
{
     for (i=0;i<n;i++)
       {


          if(i==0)
               { dx=0;
                 dy=0;
                 con[i]=i;
                 cox[i]=dx;
                 coy[i]=dy;
               }


        else if (i==(no2-1))               ///     4
              {dx=0;
               dy=yl;
               con[i]=i;
               cox[i]=dx;
               coy[i]=dy;
              }

         else if(i==((no1-1)*no2))           //   20 or 7
              {dx=xl;
               dy=0;
               con[i]=i;
               cox[i]=dx;
               coy[i]=dy;
              }
        else if(i==n-1)
           {   dx=xl;
               dy=yl;
               con[i]=i;
                 cox[i]=dx;
                 coy[i]=dy;

           }


       }

      //printf("Left\n");
       for(i=1;i<no2-8;i++)              //1-3
            {
                dx=0;
                dy=i*b[i];
                con[i]=i;
                 cox[i]=dx;
                 coy[i]=dy;


            }
            //HEating with hot plate
            for(i=no2-8;i<no2-1;i++)
            {
                 dx=0;
                dy=i*b[i];
                con[i]=i;
                 cox[i]=dx;
                 coy[i]=dy;
            }


       // printf("Right\n");
           for(i=((no1-1)*no2+1);i<((n-1));i++) //21-23 right
           {e++;
            dx=(no1-1)*a[i];
            dy=e*b[i];
                 con[i]=i;
                 cox[i]=dx;
                 coy[i]=dy;
           }

//printf("Bottom\n");
for(i=1;i<no1-1;i++)                     //5 10 15 bottom
{
           k1=i*no2;

            { dx=i*a[i];
              dy=0;
              con[k1]=i;
              cox[k1]=dx;
              coy[k1]=dy;

            }
}

 //printf("Top\n");
for(i=1;i<no1-1;i++)
{           k1=(no2*i-1+no2);                         //9 14 19 top

            {dx=i*a[i];
             dy=(no2-1)*b[i];
              con[k1]=i;
              cox[k1]=dx;
              coy[k1]=dy;
            }
}


//printf("Midpoints\n");
 for(j=1;j<(no1-1);j++)
       {dx=j*a[i];                                //midpoints
        e=0;
           for(i=j*no2+1;i<(no2*(j+1)-1);i++)
           {e=e+1;
             dy=e*b[i];
                 con[i]=i;
                 cox[i]=dx;
                 coy[i]=dy;
           }
       }
e=0;
}
