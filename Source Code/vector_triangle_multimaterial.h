 #include "declearation.h"


float vector_triangle_multimaterial(float x[size][3],float y[size])
{int df,df1,l,r,ul,ur,dl,dr,ml,mr,mn;


printf("\n.......................... Vector ENDPOINTS...............................\n");

for(i=0; i<n; i++)

    {
        {
            if(i==0)
            {
                y[i]=x[i][1];
                 //printf("ELEMENT[%d]\n",i);
            }

          else if (i==(no2-1))               ///     4
               {m=t_ney-2;

               y[i]=x[m+1][2]+x[m][3];

               //printf("ELEMENT[%d]\n",m);
               }

         else if(i==((no1-1)*no2))           ///   20 or 7
              {m=ne-ney;

               y[i]=x[m][2]+x[m+1][3];

              // printf("ELEMENT [%d ]\n",m);

              }
        else if(i==n-1)
           {
            m=t_ne-1;

            y[i]=x[m][1];
            //printf("ELEMENT[%d, %f]\n",m,y[m]);

           }

        }
    }



printf("\n..........................LEFTPOINTS...............................\n");

            for(i=1;i<no2-1;i++)              ///Left
            {if (i==1) m=i;
                else m=m+2;

            //printf("ELEMENT[%d]\n",m);

            y[i]=x[m-1][3]+x[m][2]+x[m+1][1];
            //printf("ELEMENT[%d, %f]\n",i,y[i]);

            }

printf("\n..........................RIGHTPOINTS TRIANGLE...............................\n");

           for(i=((no1-1)*no2+1);i<((n-1));i++)  ///Right
           {
               if (i==((no1-1)*no2+1))  m=t_ne+2-t_ney;
               else m=m+2;

            y[i]=x[m-1][1]+x[m][2]+x[m+1][3];
            //printf("ELEMENT[%d, %f];%d\n",i,y[i],m);

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

            y[k1]=x[l][2]+x[ul][3]+x[r][1];
   //printf("ELEMENT[%d, %f]\n",k1,y[k1]);
}

printf("\n..........................TOP...............................");

for(i=1;i<nnx-1;i++)
{  k1=(no2*i+no2-1);
     if (i==1) l=t_ney-1;
    else l=l+t_ney;
   ur=l+t_ney;
   r=ur-1;                       ///Top

            y[k1]=x[l][1]+x[ur][2]+x[r][3];
            // printf("ELEMENT[%d,%d %d %d %f %f %f]\n",k1,l,ur,r,x[l][1],x[l][2],x[l][3]);

}


printf("\n\n\n\n..........................MIDPOINTS...............................");


    m=0;
    mn=0;
    for(j=1;j<no1-1;j++)
    {m=m+1;
    if(m==1) ml=1;
    else ml=ml+2;
    for(i=j*no2+1;i<(no2*(j+1)-1);i++)
           {   mn=mn+1;
               if (i==no2+1) ml=2;
               else ml=ml+2;

         l=ml-1;  ul=ml+1;
         r=l+t_ney-1; mr=r+1; ur=r+2;


         y[i]=x[l][1]+x[ml][2]+x[ul][3]+x[ur][1]+x[mr][2]+x[r][3];



           }
    }

}

