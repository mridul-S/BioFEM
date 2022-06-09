#include "declearation.h"


float boundary_matrix(double x[size][npE][npE],double y[size][size])
{int l,r,ur,ul,dl,dr,mn;
for(i=0; i<n; i++)

    {
             if(i==((no1-1)*no2))           ///   20 or 7
              {m=t_ney*(nnx-2);
               y[i][i-no2]=x[m][1][2];
               y[i][i-no2+1]=x[m][3][2]+x[m+1][2][3];
               y[i][i]=x[m][2][2]+x[m+1][3][3];
               y[i][i+1]=x[m+1][3][1];
              }
    }



           mn=0;
           for(i=((no1-1)*no2+1);i<((no1-1)*no2+6);i++)  ///Right
           {mn=mn+1;
               if (mn==1)  m=t_ne+2-t_ney;
               else m=m+2;
              // printf("MATRIXN i=[%d]  and [%d]\n",i,m);
            y[i][i-1]=x[m-1][3][1];
            y[i][i]=x[m-1][1][1]+x[m][2][2]+x[m+1][3][3];
            y[i][i+1]=x[m+1][3][1];
            y[i][i-no2]=x[m][1][2]+x[m-1][1][2];
            y[i][i-no2+1]=x[m][2][3]+x[m+1][3][2];
           }



}

