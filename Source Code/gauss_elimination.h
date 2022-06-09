#include "declearation.h"


float gauss(int m,float y[][1000],float z[])
{
    float fact,sum=0;
    for(k1=0; k1<m-1; k1++)
    {
        for(i=k1+1; i<m; i++)
        {
            fact=y[i][k1]/y[k1][k1];
            for(j=k1; j<m+1; j++)
                y[i][j]=y[i][j]-fact*y[k1][j];
        }
    }

    z[m-1]=y[m-1][m]/y[m-1][m-1];
    for(i=n-2; i>=0; i--)
    {
        sum=0;
        for(j=i+1; j<m; j++)
        {
            sum +=(y[i][j]*z[j]);
            z[i]=(y[i][m]-sum)/y[i][i];
        }
    }
}
