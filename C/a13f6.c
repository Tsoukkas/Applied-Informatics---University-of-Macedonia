#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
void decompose(long num,int *Digits,double *avg,int *max){
*Digits=0;
*avg=0;
int r;
double sum=0;
while(num>0) {
        sum+=num%10;
      if(num%10>*max){
        *max=num%10;}
        num/=10;
        *Digits+=1;
}
*avg=sum/ *Digits;
}
int main(){
long num;
int max=0,Digits;
double avg;
printf("Please insert non-negative number:");
scanf("%ld",&num);
decompose(num,&Digits,&avg,&max);
printf("Digits: %d\n",Digits);
printf("Average: %.3f\n",avg);
printf("Max: %d\n",max);
return 0;
}
