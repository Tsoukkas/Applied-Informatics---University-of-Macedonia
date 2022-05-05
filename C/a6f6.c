#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
#define N 5
void ReadData(int table[][N]){
int j=1;
while(j!=6){
printf("Dwse filo:");
table[0][j]=GetInteger();
printf("Dwse baros:");
table[1][j]=GetInteger();
printf("Dwse ypsos:");
table[2][j]=GetInteger();
printf("Dwse ilikia:");
table[3][j]=GetInteger();
printf("-----\n");
j++;
}}
void FindMean (int table [4][N],double *mo1_varos, double *mo11_varos,double *mo2_ipsos,double *mo22_ipsos,double *mo3_ilikia,double *mo33_ilikia) {
 int i,j;
 double x=0,y=0;
 double sum_varos=0,sum_varos1=0,sum2_ipsos=0,sum22_ipsos=0,sum3_ilikia=0,sum33_ilikia=0;
for(i=1;i<=4;i++){
for(j=1;j<=N;j++){
        if (table[0][j]==0){  x+=1;
        sum_varos+=table[1][j];
         sum2_ipsos+=table[2][j];
          sum3_ilikia+=table[3][j]; } /* athroisma varus,ipsus,ilikia ginekwn */
     else if(table[0][j]==1) { y+=1;
      sum_varos1+=table[1][j];
       sum22_ipsos+=table[2][j];
        sum33_ilikia+=table[3][j]; /* athroisma varus,ipsus antrwn */
    }
 } }
 *mo1_varos = sum_varos/x ;
 *mo11_varos = sum_varos1/y ;
 *mo2_ipsos = sum2_ipsos/x ;
 *mo22_ipsos = sum22_ipsos/y ;
 *mo33_ilikia = sum3_ilikia/x ;
 *mo3_ilikia = sum33_ilikia/y ;
 }



int main(){
double mo1_varos=0,mo11_varos=0,mo2_ipsos=0,mo22_ipsos=0,mo3_ilikia=0,mo33_ilikia=0;
int array[4][N];
ReadData(array);
FindMean(array,&mo1_varos,&mo11_varos,&mo2_ipsos,&mo22_ipsos,&mo3_ilikia,&mo33_ilikia);
printf("Mesos oros barous andrwn:%.1lf\n",mo1_varos);
printf("Mesos oros barous gynaikwn:%.1lf\n",mo11_varos);
printf("\n");
printf("Mesos oros ypsous andrwn:%.1lf\n",mo2_ipsos);
printf("Mesos oros ypsous gynaikwn:%.1lf\n",mo22_ipsos);
printf("\n");
printf("Mesos oros hlikias andrwn:%.1lf\n",mo33_ilikia);
printf("Mesos oros hlikias gynaikwn:%.1lf\n",mo3_ilikia);
printf("\n");
return 0;}
