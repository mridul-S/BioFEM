
#include "declearation.h"
#include "gauss_elim.h"
#include "spatial_heating.h"
#include "add_eliminated_portion.h"
#include "row_colume_elimination.h"
#include "boundary_matrix_right.h"
#include "boundary_vector_right.h"
#include "vector_triangle_multimaterial.h"
#include "matrix_triangle_multimaterial.h"


void main()
{

   FILE *out=fopen("tempoutput.txt","w+");
   FILE *out1=fopen("qm.txt","w+");
   FILE *f1=fopen("Unsteady Result.txt","w+");
   FILE *f2=fopen("main.txt","w+");
   FILE *f3=fopen("Steady Result.txt","w+");
   FILE *f4=fopen("Element.txt","a+");
   FILE *burn=fopen("burn.txt","w+");
   FILE *burn1=fopen("burn1st.txt","w+");
   FILE *burn2=fopen("burn2nd.txt","w+");
   FILE *burn3=fopen("burn3rd.txt","w+");
   FILE *burns=fopen("burn_stsrt.txt","w+");
   FILE *d=fopen("data.txt","w+");
   FILE *d1=fopen("data1.txt","w+");
   FILE *m=fopen("record.txt","w+");
   FILE *coo=fopen("coordinate.txt","w+");
   FILE *coor=fopen("cooR.txt","w+");
   FILE *burn_p=fopen("burn_parameter.txt","w+");



   printf("Enter the 1st boundary condition type\n");
   //scanf("%d",&dec[1]);
   printf("Enter the 2nd boundary condition type\n");
   //scanf("%d",&dec[2]);
   dec[1]=2;
   dec[2]=1;


   int start,end;
   float qm[size];   //internal heat
   float qr[size];   //external heat
   float qb[size];   // boundary heat
   float qf[size];   // heat flux
   float fm[size];
   float constant[size];
   float internal_heat[size];
   float bv[size][4];
   float bf[size][4];


   xl=0.005235;       // Total length of the problem along X-axis
   yl=0.007;       // Total length of the problem along Y-axis

   type=1;
   //Type 1: Steady state Problem
   //Type 2: Unsteady problem
   t1=0;
   t2=0;
   t3=37;
   t4=0;
   //         4
   //    ...........
   //    !         !
   //  1 !         ! 3
   //    !         !
   //    !.........!
   //         2
   //
   //

   //bp=0.0005;                 //Blood Perfusion
   cb=1100;                   //Density
   sh=3300;                   //   Specific Heat
   et1=25,et2=0,et3=0,et4=0;
   bt1=7,bt2=0,bt3=0,bt4=0;

   //
   // eti = Environmental Temperature at side i
   // bti = Convection heat transfer coefficient at side i
   //


   no1=72;                  //Number of node in X-direction [nnx/no1]
   nnx=no1;                 //Number of node in y-direction [nny/no2]
   no2=29;//15;
   nny=no2;


///***************************** Parameters for Triangle *****************************///

t_ney=(nny-1)*2;
t_nex=(nnx-1)*2;
nex=t_nex;
ney=t_ney;
t_ne=t_nex*(t_ney/2);
ne=t_ne;

///*****************************INPUT OF PARAMETERS***************************************//
for(i=0;i<ne;i++)
{a[i]=xl/(no1-1);
b[i]=yl/(no2-1);
}


int ee,ed,ef;
ef=2800;//1400;
ed=3920;//1960;



   for(i=0;i<ef;i++)
        {bp[i]=0.00125;}
    for(i=ef;i<ed;i++)
        {bp[i]=0.00125;}
    for(i=ed;i<ne;i++)
         {bp[i]=0;}


    for(i=0;i<ef;i++)
        {pt[i]=1000;}
    for(i=ef;i<ed;i++)
        {pt[i]=1200;}
    for(i=ed;i<ne;i++)
         {pt[i]=1200;}

    for(i=0;i<ef;i++)
        {ct[i]=2760;}
    for(i=ef;i<ed;i++)
        {ct[i]=3222;}
    for(i=ed;i<ne;i++)
         {ct[i]=3598;}



    for(i=0;i<ef;i++)
        {tc[i]=0.16;}
    for(i=ef;i<ed;i++)
        {tc[i]=0.37;}
    for(i=ed;i<ne;i++)
        {tc[i]=0.21;}




///*****************************INPUT OF PARAMETERS***************************************//

    ta=34;                         //Temperature of the artery
    n=no1*no2;                    //Total Node Number



/// *********************************************PARAMETER FOR UNSTEADY********************************** ///
    ti=1;                            //time interval
    ts=3000;                        //time step


for(i=0;i<ne;i++)
{heat_capacity[i]=pt[i]*ct[i];}    //Density*Specific heat




for(i=0;i<ne;i++)
{
    c[i]=bp[i]*cb*sh;                  //Blood perfusion * Density * Specific Heat

}

    //conductivity matrix element
    for(i=0;i<t_ne;i++)
   {

    k_t[i][1][1]=tc[i]*(a[i]*a[i]+b[i]*b[i])/(2*a[i]*b[i])+c[i]*a[i]*b[i]/12;
    k_t[i][1][2]=-tc[i]*b[i]/(2*a[i])+c[i]*a[i]*b[i]/24;
    k_t[i][1][3]=-tc[i]*a[i]/(2*b[i])+c[i]*a[i]*b[i]/24;
    k_t[i][2][3]=c[i]*a[i]*b[i]/24;
    k_t[i][2][2]= tc[i]*b[i]/(2*a[i])+(a[i]*b[i]*c[i])/12;
    k_t[i][3][3]=tc[i]*a[i]/(2*b[i])+(a[i]*b[i]*c[i])/12;



    k_t[i][2][1]= k_t[i][1][2];
    k_t[i][3][1]= k_t[i][1][3];
    k_t[i][3][2]= k_t[i][2][3];
    }
  conductivity_matrix_triangle_multimaterial(k_t,em1);





    //Element for CONVECTION boundary conditions
    for(i=ne-ney;i<ne-ney;i++)
   {h[i][1][1]=bt1*b[i]/3;             h[i][1][2]=0;             h[i][1][3]=bt1*b[i]/6;
    h[i][2][1]=h[i][1][2];             h[i][2][2]=0;             h[i][2][3]=0;
    h[i][3][1]=h[i][1][3];             h[i][3][2]=h[i][2][3];    h[i][3][3]=h[i][1][1];
  }

   //CALLING THE FUNCTION FOR BOUNDARY MATRIX ASSEMBLY (CONVECTION BOUNDARY CONDITION)
    boundary_matrix(h,hm);


  // FORMATTING VALUES OF RIGHT SIDE VECTOR

  for(i=0;i<t_ne;i++)
   {
    constant[i]=ta*bp[i]*cb*sh;
    f_t[i][1]=(constant[i])*a[i]*b[i]/6;
    f_t[i][2]=(constant[i])*a[i]*b[i]/6;
    f_t[i][3]=(constant[i])*a[i]*a[i]/6;
   }


    float bvp[size][3],evp[size][3];


    //FORMATING VALUES FOR RIGHT SIDE VECTOR [CONVECTION BOUNDARY CONDITION]
    for(i=ne-ney;i<ne-ney;i++)
    {
    bvp[i][1]=b[i]*bt1*et1/2;
    bvp[i][2]=0;
    bvp[i][3]=b[i]*bt3*et1/2;
    }


    //FORMATING VALUES FOR RIGHT SIDE VECTOR [HEAT FLUX BOUNDARY CONDITION BOUNDARY CONDITION]
    for(i=0;i<nex;i++)
    {
    bf[i][1]=0;
    bf[i][2]=0;
    bf[i][3]=0;
    bf[i][4]=0;
    }

   // float bvp[size];
     for(i=ne-ney;i<ne-ney;i++)
    {
        evp[i][1]=-10*b[i]/2;
        evp[i][2]=0;
        evp[i][3]=-10*b[i]/2;
    }


   //CALLING THE FUNCTION FOR FORMATTING RIGHT SIDE VECTOR
    vector_triangle_multimaterial(f_t,fm);


   //CALLING THE FUNCTION FOR BOUNDARY VECTOR ASSEMBLY [CONVECTION BOUNDARY CONDITION]
    bc_vector(bvp,qb);
    bc_vector(evp,qf);


   //CALLING THE FUNCTION FOR BOUNDARY VECTOR ASSEMBLY [HEAT FLUX BOUNDARY CONDITION]
    //bc_vector(qf,bf);


   for (i=0;i<n;i++)
   {
      fm[i]=fm[i]+qb[i]+qf[i];
   }


   //ADDING BOUNDARY MATRIX WITH CONDUCTIVITY MATRIX
    //if(dec[1]==2)
   {
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
        em1[i][j]=em1[i][j]+hm[i][j];
         }
     }

   }



 ///  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^   STEADY BIO HEAT TRANSFER PROBLEM   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^   ///

 if(type==1)  //TYPE 1: STEADY PROBLEM
 {


///******************************* Temperature BC ************************************///
add_eliminated_portion();



 for(i=0;i<n;i++)
    {
       fm[i]=fm[i]-ns[i];
    }

{
  for(i=0; i<n; i++)
        {
                fm[i]=fm[i+no2];
        }

}


//Row and colume elimination for Temperature boundary conditions
row_column_elimination();
n=n-no2;


///*******************************END*************************************///

//Temperature Boundary Condition

    {for(i=n-no2+7;i<n;i++)
        {
            bm[i]=90;
        }
    }

    for(i=0; i<n; i++)
    {
        em1[i][n]=fm[i];
    }

//Gaussian Elimination
gauss_elim();

///************************************* post processing *******************************///
float bmn[size];
for(i=no2;i<n+no2;i++)
{
    bmn[i]=bm[i-no2];
}

  for(i=0; i<no2; i++)
        {
                bmn[i]=37;
        }
n=n+no2;
///**************************************END***************************************///
             int m1;
             k1=0;
            for(i = 0 ; i < no1 ; i++)
            {   k1=k1+1;
                start=i*no2;
                end=(i+1)*no2;
             fprintf(f3,"\n");
             fprintf(burn,"\n");
                 m1=0;
                for(j=start;j<end;j++)
                {m1=m1+1;
                    fprintf(f3,"%.4f\t",bmn[j]);
                    cox[j]=(k1-1)*a[1];
                    coy[j]=(m1-1)*b[1];
                }

            }

             for(j=0;j<n;j++)
                {
                fprintf(d,"%d\t %.4f\t %.4f\t %.4f\n",j+1,cox[j],coy[j],bm[j]);

                }

 }



 ///  ^^^^^^^^^^^^^^^^^^^^^^^^^   UNSTEADY BIO HEAT TRANSFER PROBLEM   ^^^^^^^^^^^^^^^^^^^^^^^^^^ //


 //
 //  THE FINAL EQUATION IS
 //        [(1/DEL T)C + aK]T(n+1) = [(1/DEL T)C - a K]T(n)+Q+q
 //  SIMPLIFYING THIS HT(n+1) = F(n)
 //  WHERE,
 //       H =  [(1/DEL T)C + aK]   AND
 //       F =  [(1/DEL T)C - a K]
 //



 if(type==2) //Type 2: Unsteady problem
 {
    for(i=0;i<ne;i++)
    {c1[i][1][1]=heat_capacity[i]*a[i]*b[i]/9;
    c1[i][1][2]=heat_capacity[i]*a[i]*b[i]/18;
    c1[i][1][3]=heat_capacity[i]*a[i]*b[i]/36;
    c1[i][1][4]=heat_capacity[i]*a[i]*b[i]/18;
    c1[i][2][1]=c1[i][1][2];
    c1[i][2][2]=c1[i][1][1];
    c1[i][2][3]=heat_capacity[i]*a[i]*b[i]/18;
    c1[i][2][4]=heat_capacity[i]*a[i]*b[i]/36;
    c1[i][3][1]=c1[i][1][3];
    c1[i][3][2]=c1[i][2][3];
    c1[i][3][3]=c1[i][1][1];
    c1[i][3][4]=heat_capacity[i]*a[i]*b[i]/18;
    c1[i][4][1]=c1[i][1][4];
    c1[i][4][2]=c1[i][2][4];
    c1[i][4][3]=c1[i][3][4];
    c1[i][4][4]=c1[i][1][1];}




    //conductivity_matrix(c1,cm1);

         //FORMATING H MATRIX
          for(i=0;i<n;i++)
           {
             for(j=0;j<n;j++)
               {
                  em5[i][j]=(cm1[i][j]/ti+em1[i][j]*(0.5));  //0.5  is the value of alpha
               }
           }


           //FORMATING F MATRIX
            for(i=0; i<n; i++)
              {
               for(j=0; j<n; j++)
                 {
                fmu[i][j]=((cm1[i][j]/ti)-(em1[i][j]*(1-0.5)));  //[1-0.5] = 1-a, [a= VALUE OF ALPHA]
                 }
              }


if(dec[1]==2)

   {
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
             em5[i][j]=em5[i][j]+hm[i][j];
         }
     }

   }
 float burn_time[size];
 float burn_1st[size];
 float burn_2nd[size];
 float burn_3rd[size];

for(i=0; i<n; i++)
{
bm1[i]=37;
burn_fact[i]=0;
burn_time[i]=0;
burn_1st[i]=0;
burn_2nd[2]=0;
burn_3rd[3]=0;
}


///******************************************** TIME LOOP STARTS  ******************************///
for(s=0;s<ts;s++)
{time=(s+1)*ti;


// FORMATTING VALUES OF RIGHT SIDE VECTOR
    for(i=0;i<ne;i++)
    {
        constant[i]=ta*bp[i]*cb*sh;
        qm[i]=(constant[i]+0)*(a[i]*b[i]/4);
        qb[i]=0;
        qf[i]=0;
        fm[i]=0;
    }


   ///***************************************************************************************//
   //INPUT FOR SPATIAL HEATING
   //Qr = eta * P(t) * [-eta*x*y]
   //P(t) = HEATING POWER [H_POWER]
   //eta  = SCATTERING COEFFICIENT

    h_power=0;
    eta=0;
    ///***************************************************************************************//


    //FORMATING VALUES FOR RIGHT SIDE VECTOR [CONVECTION BOUNDARY CONDITION]
    for(i=0;i<nex;i++)
    {
    bv[i][1]=b[i]*bt1*et1/2;
    bv[i][2]=a[i]*bt2*et2/2;
    bv[i][3]=b[i]*bt3*et3/2;
    bv[i][4]=a[i]*bt4*et4/2;
    }

    for(i=ne-ney;i<ne-ney+3;i++)
    {
        bvp[i][3]=b[i]*bt1*et1/2;
        //evp[i]=10;
    }

    //FORMATING VALUES FOR RIGHT SIDE VECTOR [HEAT FLUX BOUNDARY CONDITION BOUNDARY CONDITION]
    for(i=0;i<nex;i++)
    {
    bf[i][1]=0;
    bf[i][2]=0;
    bf[i][3]=0;
    bf[i][4]=0;
    }


   //CALLING THE FUNCTION FOR FORMATTING RIGHT SIDE VECTOR
    //heat_generation_vector(qm,fm);
      vector_triangle_multimaterial(f_t,fm);



   //CALLING THE FUNCTION FOR BOUNDARY VECTOR ASSEMBLY [CONVECTION BOUNDARY CONDITION]
    bc_vector(bvp,qb);
    bc_vector(evp,qf);
    for(i=n-nny;i<n-nny+3;i++)
    {   //fprintf(out,"bvp[%d]=%.6f\n",i,bvp[i]);
        fprintf(out,"qf[%d]=%.6f\n",i,qf[i]);


    }

   //CALLING THE FUNCTION FOR BOUNDARY VECTOR ASSEMBLY [HEAT FLUX BOUNDARY CONDITION]
    //bc_vector(qf,bf);

   //CALLING THE SPATIAL HEATING FUNCTION
   //spatial_heating();



   for (i=0;i<n;i++)
   {
       //fm[i]=fm[i]+qb[i];//-qf[i];//+qb[i]+qf[i]+qr[i];
   }


       for(i=0;i<n;i++)
           {
             for(j=0;j<n;j++)
               {
                  em1[i][j]=em5[i][j];  //0.5  is the value of alpha
               }
           }

    //Point Heat  (Step)
    /*if(time<=240  && time >0)
        p_heat=25;
    else if (time<=480  && time >240)
        p_heat=0;
    else if (time <=720  && time >480)
        p_heat=25;
    else p_heat=0;


                     // Point heat double
                           for(i=0; i<n; i++)
                                 {if(i==220)
                                fm[i]=fm[i]+p_heat;
                                }/*
                              for(i=0; i<n; i++)
                                 {if(i==283)
                                fm[i]=fm[i]+p_heat;
                                }*/

                            ///  Adding point heat source to the right side vector
                             /*for(i=0; i<n; i++)
                                 {if(i==136)
                                fm[i]=fm[i]+p_heat;
                                }*/




       {
        for(i=0; i<n; i++)
            {
                qm[i]=0;
                for(j=0; j<n; j++)
                {
                    qm[i]=qm[i]+fmu[i][j]*bm1[j];
                }
            }
        }



        for(i=0; i<n; i++)
            {
                qm[i]=qm[i]+fm[i];
            }



///******************************* Temperature BC ************************************///
add_eliminated_portion();





 for(i=0;i<n;i++)
    {
       qm[i]=qm[i]-ns[i];
    }



    //Eliminating right side vector
    //right_side_vector_elimination();

{
  for(i=0; i<n; i++)
        {
                qm[i]=qm[i+no2];
        }

}


    //Row and colume elimination for dirxhileate boundary conditions
    row_column_elimination();




      n=n-no2;


///*******************************END*************************************///


         for(i=0; i<n; i++)
          {
          em1[i][n]=qm[i];
          }




         for(i=0;i<n;i++)
             {
              bm[i]=0;
             }

          {
          for(i=n-no2;i<n;i++)
               {
              bm[i]=37;
               }
          }

           //Gaussian Elimination
            gauss_elim();


///************************************* post processing *******************************///
float bmn[size];
for(i=no2;i<n+no2;i++)
{
    bmn[i]=bm[i-no2];
}
n=n+no2;

  for(i=0; i<no2; i++)
        {
                bmn[i]=45;
        }

///**************************************END***************************************///

           /// CONTROLLED HEATING
           /* for(i = 0 ; i < n ; i++)
            {
               if((i>175 && i<181) || (i>196 && i<202) || (i>217 && i<223) || (i>238 && i<244)|| (i>259 && i<265))
               k1=1;
                  else
                    {if(bm[i]>42)                          //Maximum prescribed value
                        {
                        if(p_heat !=0)
                         {  p_heat=0;
                         fprintf(m,"\npoint heat=%.2f",p_heat);
                             fprintf(m,"\nBreak time=%f",time);
                             }
                        }
                    if (bm[i]<=34)                       //Minimum prescribed value
                    {
                        if(p_heat==0)
                        {p_heat=25;
                        fprintf(m,"\npoint heat=%.2f",p_heat);
                        fprintf(m,"\nStart time=%f",time);
                        }
                    }
                    }


            }*/








         /// DETERMINING THE BURNING POINT CALCULATION
         /*for(i=0;i<n;i++)
            {

                if(bm[i]>=43)
                    {//fprintf(f4,"Yes We Reached The Burning Point");
                    fprintf(f4,"%.2f \t %.2f\t %.4f",sum_factor1,time,bm[i]);
                    fprintf(f4,"\n");

                      exit(0);

                      }
                      else
                        continue;
            }*/




            ///BURN CALCULATION

            for(i = 0 ; i < n ; i++)
            {
            p_fact=226.7847;
            t_fact=log(ti*(s+1));
            e_fact=6.27*pow(10,8);
            if(bm[i]>44 && bm[i]<53)
            {
            e_fact=-(6.27*pow(10,8)/(8314*(bm[i]+273)));
            burn_fact[i]=burn_fact[i]+exp(226.7847+t_fact+e_fact);
            }
            else if(bm[i]>53)
            {
            e_fact=-(6.27*pow(10,8)/(8314*(bm[i]+273)));
            burn_fact[i]=burn_fact[i]+exp(226.7847+t_fact+e_fact);
            }
            else  burn_fact[i]=burn_fact[i];

            // Degree of burn calculation
               {
                    if (burn_fact[i]<0.53) burn_fact[i]=0;
                        else if (burn_fact[i]>0.53 && burn_fact[i]<1)
                        burn_fact[i]=1;
                    else if(burn_fact[i]==1)
                        burn_fact[i]=2;
                    else
                        burn_fact[i]=3;

                }
            }



           ///****************  TIME TO START BURN *****************///

           for(i=0;i<n;i++)
            {

                if(burn_time[i]==0)
                {
                    if(bm[i]>=43)
                    {
                        burn_time[i]=time;
                    }
                }

            }


              for(i=0;i<n;i++)
            {

                if(burn_fact[i]==1)
                {
                        burn_1st[i]=time;
                }
                if(burn_fact[i]==2)
                {
                        burn_2nd[i]=time;
                }
                if(burn_fact[i]==3)
                {
                        burn_3rd[i]=time;
                }



            }

         ///******************** END *************************///



            ///Result printing with related co-ordinate value
             for(j=0;j<n;j++)
                {
                //printf("\nx[%d] = %.4f",i+1,bm[i]) ;
                  fprintf(d,"%d\t %.4f\t %.4f\t %.2f\t %.4f\n",j,cox[j],coy[j],time,bmn[j]);
                //fprintf(d,"%.4f\t %.4f\t %.2f\t %.4f\n",cox[j],coy[j],time,1-exp(-burn_fact[j]));

                }


             /// RESULT PRINTING

              for(i = 0 ; i < no1 ; i++)
            {   start=i*no2;
                end=(i+1)*no2;
             fprintf(f3,"\n");
             fprintf(burn,"\n");
                for(j=start;j<end;j++)
                {
                   fprintf(f3,"%.4f\t",bmn[j]);
                   fprintf(burn,"%.0f\t",burn_fact[j]);
                   //fprintf(burns,"%.0f\t",burn_time[j]);

                }
            }
            fprintf(f3,"\n\n\n\n");
            fprintf(burn,"\n\n\n\n");




              /// RESULT PRINTING
            fprintf(f1,"\n");
            for(i=0;i<n;i++)
            {
                fprintf(f1,"%.4f\t",bm[i]);
            }



        // INPUT FOR NEXT ITERATION
        {
            for(i=0;i<n;i++)
                bm1[i]=bmn[i];            ///GET INPUT FOR NEXT TIME STEP change bm to bmn
        }



       }

           for(i = 0 ; i < no1 ; i++)
            {   start=i*no2;
                end=(i+1)*no2;
             fprintf(burns,"\n");
             fprintf(burn1,"\n");
             fprintf(burn2,"\n");
             fprintf(burn3,"\n");
                for(j=start;j<end;j++)
                {
                   fprintf(burns,"%.0f\t",burn_time[j]);
                   fprintf(burn1,"%.0f\t",burn_1st[j]);
                      fprintf(burn2,"%.0f\t",burn_2nd[j]);
                         fprintf(burn3,"%.0f\t",burn_3rd[j]);

                }
            }

            fprintf(burns,"\n\n\n\n");
            fprintf(burn1,"\n\n\n\n");
            fprintf(burn2,"\n\n\n\n");
            fprintf(burn3,"\n\n\n\n");
 }

 }



