  #include "declearation.h"


float conductivity_matrix_triangle_multimaterial(float x[size][3][3],double y[size][size])
{int df,df1,l,r,ul,ur,dl,dr,ml,mr,mn;


printf("\n..........................ENDPOINTS...............................\n");

for(i=0; i<n; i++)

    {
        {
            if(i==0)
            {
                y[i][i]=x[i][1][1];
                y[i][i+1]=x[i][3][1];
                y[i][i+no2]=x[i][1][2];
                printf("ELEMENT[%d]\n",i);
            }

          else if (i==(no2-1))               ///     4
               {m=t_ney-2;
               y[i][i-1]=x[m][1][3];
               y[i][i]=x[m+1][2][2]+x[m][3][3];
               y[i][i+no2-1]=x[m][3][2]+x[m+1][2][3];
               y[i][i+no2]=x[m+1][2][1];
               printf("ELEMENT[%d %d]\n",i,m);
               }

         else if(i==((no1-1)*no2))           ///   20 or 7
              {m=t_ney*(nnx-2);
               y[i][i-no2]=x[m][1][2];
               y[i][i-no2+1]=x[m][3][2]+x[m+1][2][3];
               y[i][i]=x[m][2][2]+x[m+1][3][3];
               y[i][i+1]=x[m+1][3][1];
               //printf("ELEMENT[%d %f]\n",m,x[m][1][2]);
               //printf("ELEMENT[%d]\n",i);
               printf("Problem[%d %d]\n",i,m);

              }
        else if(i==n-1)
           {
            m=t_ne-1;
            y[i][i-no2]=x[m][1][2];
            y[i][i-1]=x[m][1][3];
            y[i][i]=x[m][1][1];
            //printf("ELEMENT[%d, %f]\n",m,x[1][1][2]);
            //printf("ELEMENT[%d]\n",i);
            printf("ELEMENT[%d %d]\n",i,m);

           }

        }
    }



printf("\n..........................LEFTPOINTSnnnnnnnnn...............................\n");
            for(i=1;i<no2-1;i++)              ///Left
            {if (i==1) m=i;
                else m=m+2;
            y[i][i-1]=x[m-1][3][1];
            y[i][i]=x[m-1][3][3]+x[m][2][2]+x[m+1][1][1];
            y[i][i+1]=x[m+1][3][1];
            y[i][i+no2]=x[m][1][2]+x[m+1][1][2];
            y[i][i+no2-1]=x[m][2][3]+x[m-1][3][2];
            printf("ELEMENT[%d %d]\n",i,m);
            }

printf("\n..........................RIGHTPOINTS...............................\n");
          mn=0;
           for(i=((no1-1)*no2+1);i<((n-1));i++)  ///Right
           {mn=mn+1;
               if (mn==1)  m=t_ne+2-t_ney;
               else m=m+2;
            y[i][i-1]=x[m-1][3][1];
            y[i][i]=x[m-1][1][1]+x[m][2][2]+x[m+1][3][3];
            y[i][i+1]=x[m+1][3][1];
            y[i][i-no2]=x[m][1][2]+x[m-1][1][2];
            y[i][i-no2+1]=x[m][2][3]+x[m+1][3][2];
            printf("ELEMENT[%d %d]\n",i,m);

           }


printf("\n..........................BOTTOM POINTS...............................\n");
//m=t_nny-t_ney;
for(i=1;i<no1-1;i++)                     ///Bottom
{
           k1=i*no2;

           if (i==1) ul=1;
           else ul=ul+t_ney;
           l=ul-1;
           r=l+t_ney;
          // printf("ELEMENT[%d][%d][%d]\n",l,ul,r);
            y[k1][k1+1]=x[ul][3][1]+x[r][3][1];
            y[k1][k1]=x[l][2][2]+x[ul][3][3]+x[r][1][1];
            y[k1][k1+no2]=x[r][1][2];

            y[k1][k1-no2]=x[l][1][2];
            y[k1][k1-no2+1]=x[l][2][3]+x[ul][3][2];
            //printf("ELEMENT[%d]\n",k1);
            printf("ELEMENT[%d %d %d %d]\n",k1,l,ul,r);
}

printf("\n..........................TOP...............................");

for(i=1;i<no1-1;i++)
{ k1=(no2*i+no2-1);
     if (i==1) l=t_ney-1;
    else l=l+t_ney;
   ur=l+t_ney;
   r=ur-1;                         ///Top
   //printf("ELEMENT[%d][%d][%d]\n",l,r,ur);
            y[k1][k1-1]=x[l][3][1]+x[r][3][1];
            y[k1][k1]=x[l][1][1]+x[ur][2][2]+x[r][3][3];
            y[k1][k1-no2]=x[l][1][2];
            y[k1][k1+no2]=x[ur][1][2];
            y[k1][k1+no2-1]=x[ur][2][3]+x[r][3][2];
            //printf("ELEMENT[%d]\n",k1);
            printf("ELEMENT[%d %d %d %d]\n",k1,l,ur,r);
}


printf("\n..........................MIDPOINTS...............................");
     m=0;
    mn=0;
    for(j=1;j<no1-1;j++)
    {
        m=m+1;
    if(m==1) ml=1;
    else ml=ml+2;
    for(i=j*no2+1;i<(no2*(j+1)-1);i++)

           { mn=mn+1;
               if (i==no2+1) ml=2;
               else ml=ml+2;

         l=ml-1;  ul=ml+1;
         r=l+t_ney-1; mr=r+1; ur=r+2;

         //printf("ELEMENT[%d] [%d][%d] [%d][%d] [%d]\n",l,ml,ul,r,mr,ur);
         y[i][i-1]=x[l][1][3]+x[r][1][3];
         y[i][i]=x[l][1][1]+x[ml][2][2]+x[ul][3][3]+x[ur][1][1]+x[mr][2][2]+x[r][3][3];
         y[i][i+1]=x[ul][1][3]+x[ur][1][3];
         y[i][i+no2-1]=x[r][2][3]+x[mr][3][2];
         y[i][i+no2]=x[ur][2][1]+x[mr][2][1];
         y[i][i-no2]=x[l][1][2]+x[ml][2][1];
         y[i][i-no2+1]=x[ul][3][2]+x[ml][2][3];
         //printf("ELEMENT[%d]\n",i);
         printf("ELEMENT[%d %d %d %d %d %d %d]\n",i,l,ml,ul,r,mr,ur);

           }
    }

}

