#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define size 4000
#define npE 3 //Node per element
#define size_t 4000
#include "omp.h"


///****************************TRIANGULAR ELEMENT************************//

int t_nnx;
int t_nny;
int t_nex;
int t_ney;
int t_n;
int t_ne;
float k_t[size_t][3][3];
float f_t[size][3];
///****************************END************************//


int i,j,no1,no2,n,tn,ts,ne,nnx,nny,nex,ney;
float xl,yl;
int con[size];
float cox[size];
float coy[size];

 //double uem1[1000][1000],ufm[1000][1000];
 //float eh,sc;  //External Teating power
 float h_power,eta,time,p_heat;
 float t1,t2,t3,t4,dx,dy;
int e;//e=midpoint co-ordinate
float t_fact,p_fact,e_fact,burn_fact[size];

 //float k[1000][1000];
 double h[size][npE][npE];
 double k[size][npE][npE];
 //float h[1000][1000];
 double c1[size][npE][npE];
 double cm1[size][size];
 double hm[size][size];
 double fmu[size][size],qm[size],bm[size],bm1[size];  //For unsteady calculation
 double c[size],ta,bp[size],cb,complex,sh,heat_generation[size];                                 //for heat generation matrix
 double fm[size],em[size][size],em1[size][size],em5[size][size];
 double fact, sum;
 int s,bt,btn;
 double bt1,bt2,bt3,bt4;
 double et1,et2,et3,et4;  //Environmental Temperature.
 //int btl;         //convection coefficient
 double tc[size];
 //n=no1*no2;   //total node=node along with(x*y) axis
 //float a;      //nodal distance along x axis
 double a[size],b[size];      //nodal distance alond y axis
 int k1;         //instead of k as k denoted as capacitance matrix
 int m,dec[size]; //For boundary conditions
 double type,pt[size],ct[size]; //density and specific heat of tissue
 double heat_capacity[size]; //product of pt and ct
 double ti;    //TIME INTERVAL
 //int s;
 int time_step;

///**********************************************************///
float ns[size];
