#include<stdio.h>
#include "simpio.h"
#include "genlib.h"
void mo(int a[5][3],float *mo1,float *mo2,float *mo3,float *mo4,float *mo5,float *m1,float *m2,float *m3,float *m4,float *m5){
int sum1=0,sum2=0,sum3=0,sum4=0,sum5=0;
for(int i=1;i<=5;i++){
for(int j=1;j<=3;j++){
sum1+=a[1][j];
sum2+=a[2][j];
sum3+=a[3][j];
sum4+=a[4][j];
sum5+=a[5][j];}
}
*mo1=sum1/5;
*mo2=sum2/5;
*mo3=sum3/5;
*mo4=sum4/5;
*mo5=sum5/5;
*m1=sum1/3;
*m2=sum2/3;
*m3=sum3/3;
*m4=sum4/3;
*m5=sum5/3;
}
int main(){
int a[5][3];
float mo1,mo2,mo3,mo4,mo5,m1,m2,m3,m4,m5;
for(int i=1;i<=5;i++){
for(int j=1;j<=3;j++){
printf("Dwse ispraksi gia tin %d poli ton %d mina:",i,j);
a[i][j]=GetInteger(); }}
mo(a,&mo1,&mo2,&mo3,&mo4,&mo5,&m1,&m2,&m3,&m4,&m5);
printf("o mesi miniaia ispraksi gia tin proti aithusa ine %.2f\n",mo1);
printf("o mesi miniaia ispraksi gia tin defteri aithusa ine %.2f\n",mo2);
printf("o mesi miniaia ispraksi gia tin triti aithusa ine %.2f\n",mo3);
printf("o mesi miniaia ispraksi gia tin tetarti aithusa ine %.2f\n",mo4);
printf("o mesi miniaia ispraksi gia tin pempti aithusa ine %.2f\n",mo5);
printf("o mesi miniaia ispraksi gia tin proti aithusa ine %.2f\n",mo1);
printf("o mesi miniaia ispraksi gia tin defteri aithusa ine %.2f\n",mo2);
printf("o mesi miniaia ispraksi gia tin triti aithusa ine %.2f\n",mo3);
printf("o mesi miniaia ispraksi gia tin tetarti aithusa ine %.2f\n",mo4);
printf("o mesi miniaia ispraksi gia tin pempti aithusa ine %.2f\n",mo5);
return 0;
}
