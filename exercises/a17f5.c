#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
int main(){
int a[10][3],x,c;
int sum[10];
double avg[10];
for(int i=1;i<=10;i++){
printf("Mathitis %d\n",i);
printf("---------------\n");
for(int j=1;j<=3;j++){
printf("Mathima %d:",j);
a[i][j]=GetInteger();
}}
for(int i=1;i<=10;i++){
for(int j=1;j<=3;j++){
 sum[i]+=a[i][j];
}
}
for(int i=1;i<=10;i++){
    avg[i]=sum[i]/3;
    if(avg[i]<9.5){
        x++;
    }
    if(avg[i]>18.5){
        c++;
    }
}
printf("Plithos apotyxonton: %d %.2f%\n",x,(x*10));
printf("Plithos aristoyxon:  %d %.2f%\n",c,(c*10));
return 0;
}
