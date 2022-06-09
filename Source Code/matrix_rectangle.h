#include "declearation.h"


float conductivity_matrix(double x[size][npE][npE],double y[size][size])
{int l,r,ur,ul,dl,dr,mn;
//printf("\n..........................Matrix...............................\n");
//printf("\n..........................ENDPOINTS...............................\n");
for(i=0; i<n; i++)

    {
        {
            if(i==0)
                {// printf("i=%d\n",i);
                y[i][i]=x[i][1][1];
                y[i][i+1]=x[i][4][1];
                y[i][i+no2]=x[i][1][2];
                y[i][i+no2+1]=x[i][3][1];}
           else if (i==(no2-1))               ///     4
               {
                     m=ney-1;
                     //printf("i=%d\n",m);
               y[i][i-1]=x[m][1][4];
               y[i][i]=x[m][4][4];
               y[i][i+no2-1]=x[m][2][4];
               y[i][i+no2]=x[m][4][3];}

         else if(i==((no1-1)*no2))           ///   20 or 7
              {
                  m=(nex-1)*ney;
                 // printf("i=%d\n",m);
               // m=i-(ney+nex);
               y[i][i-no2]=x[m][1][2];
               y[i][i-no2+1]=x[m][4][2];
               y[i][i]=x[m][2][2];
               y[i][i+1]=x[m][3][2];
                //printf("Matrix[%d][%d]=%.2f\n",i,i,em[i][i]);
              }
        else if(i==n-1)
           {
               //m=i-nex-ney;
                m=ne-1;
                //printf("i=%d\n",m);
            y[i][i-no2-1]=x[m][1][3];
            y[i][i-no2]=x[m][4][3];
            y[i][i-1]=x[m][2][3];
            y[i][i]=x[m][3][3];

           }

        }
    }


//printf("\n..........................LEFTPOINTS...............................\n");
            for(i=1;i<no2-1;i++)              ///Left
            {
            y[i][i-1]=x[i-1][4][1];
            y[i][i]=x[i][1][1]+x[i-1][4][4];
            y[i][i+1]=x[i][4][1];
            y[i][i+no2]=x[i][1][2]+x[i-1][4][3];
            y[i][i+no2+1]=x[i][3][1];
            y[i][i+no2-1]=x[i-1][4][2];
            }

 //printf("\nem[1][0]=%.2f",em[1][0]);
//printf("\n..........................RIGHTPOINTS...............................\n");
           mn=0;
           for(i=((no1-1)*no2+1);i<((n-1));i++)  ///Right
           {mn=mn+1;
           if(mn==1) m=ney*(nex-1);
                 else m=m+1;
              // printf("i= %d %d\n",m,m+1);
            y[i][i-1]=x[m][3][2];
            y[i][i]=x[m+1][2][2]+x[m][3][3];
            y[i][i+1]=x[m+1][3][2];
            y[i][i-no2]=x[m+1][1][2]+x[m][4][3];
            y[i][i-no2+1]=x[m+1][4][2];
            y[i][i-no2-1]=x[m][1][3];
           }
 //printf("\nem[1][0]=%.2f",em[1][0]);

//printf("\n..........................BOTTOM POINTS...............................\n");
l=-ney;
for(i=1;i<no1-1;i++)                     ///Bottom
{
           k1=i*no2;
              l=l+ney;//k1-(nny+i-1);
              r=l+ney;
             // printf("RIGHT=%d %d\n",l,r);
           // printf("3rd line [k]=%d\n",k1);
            y[k1][k1+1]=x[r][4][1]+x[l][3][2];
            y[k1][k1]=x[l][1][1]+x[r][2][2];
            y[k1][k1+no2]=x[r][1][2];
            y[k1][k1+no2+1]=x[r][3][1];
            y[k1][k1-no2]=x[l][1][2];
            y[k1][k1-no2+1]=x[l][4][2];
}

 //printf("\nem[3][3]=%.2f",em[2][2]);
//printf("\n..........................TOP...............................");
l=-1;
for(i=1;i<no1-1;i++)
{           k1=(no2*i+no2-1);                         ///Top
             l=l+ney;//k1-(nny+i);
             r=l+ney;
           // printf("RIGHT=%d %d\n",l,r);
            //printf("upper points=%d\n",k);
            //printf("\ni=%d",k1);
            y[k1][k1-1]=x[r][4][1]+x[l][3][2];
            y[k1][k1]=x[l][3][3]+x[r][4][4];
            y[k1][k1-no2]=x[l][4][3];
            y[k1][k1+no2]=x[r][3][4];
            y[k1][k1-no2-1]=x[l][3][1];
            y[k1][k1+no2-1]=x[r][4][2];
}

 //printf("\nem[1][0]=%.2f",em[1][0]);
//printf("\n..........................MIDPOINTS...............................");
    mn=0;
    for(j=1;j<no1-1;j++)
                                    ///midpoints
    {mn=mn+1;
    if(mn==1) dl=dl;
     else dl=dl+1;
    for(i=j*no2+1;i<(no2*(j+1)-1);i++)
           { mn=mn+1;
           if(mn==2) dl=0;
           else dl=dl+1;

           ul=dl+1;
           ur=ul+ney; dr=ur-1;
       //


     //  printf("RIGHT=%d %d %d %d %d\n",i,ul,dl,ur,dr);
        //printf("\ni=%d",i);
         y[i][i-1]=x[dl][2][3]+x[dr][1][4];
         y[i][i]=x[ur][1][1]+x[ul][2][2]+x[dl][3][3]+x[dr][4][4];
         y[i][i+1]=x[ul][2][3]+x[ur][1][4];
         y[i][i-1+no2]=x[dr][2][4];
         y[i][i+no2]=x[ur][2][1]+x[dr][3][4];
         y[i][i+1+no2]=x[ur][1][3];
         y[i][i-1-no2]=x[dl][1][3];
         y[i][i-no2]=x[ul][1][2]+x[dl][4][3];
         y[i][i+1-no2]=x[dr][4][2];
           }
    }


}

