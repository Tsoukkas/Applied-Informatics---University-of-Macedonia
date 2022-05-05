#include<stdio.h>
#include"genlib.h"
#include"simpio.h"
int main ()
{
long code;
double misthos;
double eamivi;
int hours;
double amivihours;
printf("Dwse ton kwdiko:");
code=GetLong();
if(code>=1000){
printf("Dwse ton ethsio mistho:");
misthos=GetReal();
eamivi=misthos/52 ;
}
else {
  printf("Dwse tis wres ebdomadiaias ergasias:");
  hours=GetInteger();
  printf("Dwse thn amivi ana wra:");
  amivihours=GetReal();
  eamivi=hours*amivihours;
  if (hours>40){
  eamivi+=(hours-40) * (amivihours*0.5);
  }
}
printf("I evdomadiaia amivi einai:%g",eamivi);
return 0;
}
