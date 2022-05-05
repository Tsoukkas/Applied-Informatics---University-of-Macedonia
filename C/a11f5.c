#include<stdio.h>
#include<math.h>
#include"simpio.h"
#include"genlib.h"
#define CTS 10
#define S 3
int main(){
double temper[CTS][S];
double devnat[CTS][S];
double sum=0;
double average[CTS];
double avg;
double mdeviasion[CTS];
for(int i=0;i<CTS;i++){
for(int j=0;j<S;j++){
printf("Temp of City %d During %d slot:",i,j);
temper[i][j]=GetReal();
sum+=temper[i][j];
}}
avg=sum/30.0;
for(int i=0;i<CTS;i++){
    average[i]=0;
for(int j=0;j<S;j++){
    average[i]+=temper[i][j];
}
average[i]=average[i]/S;
}
for(int i=0;i<CTS;i++){
for(int j=0;j<S;j++){
    devnat[i][j]=fabs(avg-temper[i][j]);
}
}
for(int i=0;i<CTS;i++){
    mdeviasion[i]=devnat[i][0];
    for(int j=1;j<S;j++){
            if(mdeviasion[i]<devnat[i][j]){
                mdeviasion[i]=devnat[i][j];
            }
        }
}
printf("%.1f\n",avg);
for(int i=0;i<CTS;i++){
    printf("City %d %.1f %.1f\n",i,average[i],mdeviasion[i]);
}
return 0;
}
