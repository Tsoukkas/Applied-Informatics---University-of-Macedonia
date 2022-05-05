#include<stdio.h>
#include"genlib.h"
#include"simpio.h"
#define plithos 23

 void hours(string celebrities[],double afiksi[],double anaxorisi[],double s[]){
for(int i=0;i<plithos;i++){
printf("Dwse onoma diasimotitas:");
celebrities[i]=GetLine();
printf("Dwse tin ora afiksis tis diasimotitas:");
afiksi[i]=GetReal();
if(afiksi[i]<18.00){
printf("To festival ksekinai stis 18,Dwse tin ora afiksis ksana:");
afiksi[i]=GetReal();
}

printf("Dwse tin ora anaxorisis tis diasimotitas:");
anaxorisi[i]=GetReal();
if(anaxorisi[i]>24.00){
printf("Mexri tis 24 einai to festival,Dwse tin ora anaxorisis ksana:");
anaxorisi[i]=GetReal();
}
anaxorisi[i]=anaxorisi[i]-00.01;
} for(int i=0;i<7;i++){
    s[i]=i+18.00; } }

void BestTime(double afiksi[],double anaxorisi[],double x[],int *max1){
int i,j;
for(i=0;i<7;i++){

    for(j=0;j<plithos;j++){
   if((x[i]>=afiksi[j]) && (x[i]<anaxorisi[j])){
    x[i]=x[i]+1.00;
   }
    }
if(x[i]>*max1){
        *max1=x[i];
}
 } }
int main(){
int max1=0;
string celebrities[plithos];
double afiksi[plithos],anaxorisi[plithos];
double s[6],x[6];
hours(celebrities,afiksi,anaxorisi,s);
BestTime(afiksi,anaxorisi,x,&max1);
printf("I kaliteri ora na pai o stathis stin sinavlia ine %.2lf-%.2lf",s[max1+1],s[max1+2]);
return 0;
}
