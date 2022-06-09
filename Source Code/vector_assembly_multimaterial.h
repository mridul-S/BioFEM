#include "declearation.h"
#include <stdio.h>

float heat_generation_vector(float qm[size], float fm[size])
{int l,r,ul,ur,dl,dr,mn;

     for (i=0;i<n;i++)
       {


          if(i==0)
               {
                   fm[i]=qm[i];
               }

           else if (i==(no2-1))               //     4
              {   m=ney-1;
                  fm[i]=qm[m];
              }

         else if(i==((no1-1)*no2))           //   20 or 7
              {   m=(nex-1)*ney;
                  fm[i]=qm[m];

              }
        else if(i==n-1)
           {   m=ne-1;
               fm[i]=qm[m];


           }


       }


       for(i=1;i<no2-1;i++)              //1-3
            {
           fm[i]=qm[i]+qm[i-1];

            }

            mn=0;
           for(i=((no1-1)*no2+1);i<((n-1));i++) //21-23 right
           {mn=mn+1;
           if(mn==1) m=ney*(nex-1);
                 else m=m+1;
            fm[i]=qm[m]+qm[m+1];
            //printf(" Vector RIGHT=%d\n",m);
           }

     l=-ney;
     for(i=1;i<no1-1;i++)                     //5 10 15 bottom
       {
           k1=i*no2;

            {
              l=l+ney;//k1-(nny+i-1);
              r=l+ney;
             // printf("bottom=%d %d\n",l,r);
              fm[k1]=qm[l]+qm[r];

            }
        }

    // TOP
       l=-1;
        for(i=1;i<no1-1;i++)
       { k1=(no2*i-1+no2);
         {
             l=l+ney;//k1-(nny+i);
             r=l+ney;
            // printf("top=%d %d\n",l,r);
             fm[k1]=qm[l]+qm[r];

            }
      }

   //midpoints
    mn=0;
   for(j=1;j<(no1-1);j++)
       {mn=mn+1;
      if(mn==1) dl=dl;
      else dl=dl+1;
           for(i=j*no2+1;i<(no2*(j+1)-1);i++)
           {mn=mn+1;
           if(mn==2) dl=0;
           else dl=dl+1;

           ul=dl+1;
           ur=ul+ney; dr=ur-1;
            // printf("RIGHT=%d %d %d %d %d\n",i,ur,dr,ul,dl);
               fm[i]=qm[ul]+qm[ur]+qm[dl]+qm[dr];

           }
       }


}
