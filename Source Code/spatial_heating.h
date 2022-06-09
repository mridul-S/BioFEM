#include "declearation.h"

float spatial_heating()
{float dx,dy,l,r,ur,ul,dr,dl,qr[size];
     for (i=0;i<n;i++)
       {


          if(i==0)
               { dx=0;
                 dy=0;
                 qr[i]=h_power*eta*exp(-eta*dx);
               }

           else if (i==(no2-1))               ///     4
              {dx=0;
               dy=yl;
                m=i-(ney+nex);
                  qr[i]=h_power*eta*exp(-eta*dx);
              }

         else if(i==((no1-1)*no2))           //   20 or 7
              {dx=xl;
               dy=0;
               m=i-(ney+nex);
               qr[i]=h_power*eta*exp(-eta*dx);
              }
        else if(i==n-1)
           {   dx=xl;
               dy=yl;
               m=i-nex-ney;
               qr[i]=h_power*eta*exp(-eta*dx);

           }


       }

      //printf("Left\n");
       for(i=1;i<no2-1;i++)              //1-3
            {
                dx=0;
                dy=i*b[i];
                qr[i]=h_power*eta*exp(-eta*dx);
            }

        //printf("Right\n");
           for(i=((no1-1)*no2+1);i<((n-1));i++) //21-23 right
           {e++;
            dx=(no1-1)*a[i];
            dy=e*b[i];
            m=i-nny-nex;
            qr[i]=h_power*eta*exp(-eta*dx);
           }

//printf("Bottom\n");
for(i=1;i<no1-1;i++)                     //5 10 15 bottom
{
           k1=i*no2;

            { dx=i*a[i];
              dy=0;
              l=k1-(nny+i-1);
              r=l+nex;
             qr[k1]=h_power*eta*exp(-eta*dx);
            }
}

 //printf("Top\n");
for(i=1;i<no1-1;i++)
{           k1=(no2*i-1+no2);                         //9 14 19 top

            {dx=i*a[i];
             dy=(no2-1)*b[i];
             l=k1-(nny+i);
             r=l+nex;
             qr[k1]=h_power*eta*exp(-eta*dx);
            }
}


//printf("Midpoints\n");
 for(j=1;j<(no1-1);j++)
       {dx=j*a[j];                                //midpoints
        e=0;
           for(i=j*no2+1;i<(no2*(j+1)-1);i++)
           { e=e+1;
             dy=e*b[i];
             ur=i-j-1; ul=ur-nex; dl=ul-1; dr=ur-1;
             qr[i]=h_power*eta*exp(-eta*dx);
           }
       }

}
