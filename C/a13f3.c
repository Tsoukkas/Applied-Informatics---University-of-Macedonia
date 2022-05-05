#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
int main (){
int orio;
int i;
float sum=0.0;
float apotelesma;
printf("Dwse orio:");
orio=GetInteger();
for( i=1;i<=orio;i++){
apotelesma=1.0/i;
sum+=apotelesma;;
}
printf("To athroisma ine:%.2f",sum);
return 0;
}
