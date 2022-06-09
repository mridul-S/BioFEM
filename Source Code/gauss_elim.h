#include "declearation.h"


float gauss_elim()
{
   float fact, sum=0;
    for(k1=0; k1<n-1; k1++)
    {
        for(i=k1+1; i<n; i++)
        {
            fact=em1[i][k1]/em1[k1][k1];
            for(j=k1; j<n+1; j++)
                em1[i][j]=em1[i][j]-fact*em1[k1][j];
        }
    }
    if(bm[n-1]==0)
    {bm[n-1]=em1[n-1][n]/em1[n-1][n-1];}
    else
       bm[n-1]=bm[n-1];

    for(i=n-2; i>=0; i--)
    {if(bm[i]==0)
        {sum=0;
        //printf("Calculate i=%d\n",i);
        for(j=0; j<n; j++)
        {
            sum +=(em1[i][j]*bm[j]);

        }
        bm[i]=(em1[i][n]-sum)/em1[i][i];
        }
    else
        {bm[i]=bm[i];
       // printf("P i=%d\n",i);
       }
    }
}
