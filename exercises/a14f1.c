#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
int main (){
double varos,ipsos;
double BMR;
int ilikia;
printf("dose varos se kila:");
varos=GetReal();
printf("dose ipsos se cm:");
ipsos=GetReal();
printf("dose ilikia se xronia:");
ilikia=GetInteger();
BMR=655+(9.6*varos)+(1.8*ipsos)-(4.7*(ilikia));
printf("To BMR Ine:%g",BMR);
return 0;
}
