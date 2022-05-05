#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
int main(){
int co2;
float tkikl;
printf("dose gram co2/khm:");
co2=GetInteger();
if (co2<=120){
tkikl=co2*0.9;
}
else if(co2<140){
tkikl=co2*1.1;
}
  else{
  tkikl=co2*1.7;
  }
printf("To poso pliromis einai:%f",tkikl);
return 0;
}
