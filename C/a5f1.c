#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
int main (){
int whours;
long  antimisthia;
double pososto,kratisis;
double akipodoxes;
double kathipodoxes;
printf("dose ton arithmo twn wrwn:");
whours=GetInteger();
printf("dose tin wriaia antimisthia:");
antimisthia=GetLong();
printf("dose to pososto twn kratisewn:");
pososto=GetReal();
kathipodoxes=whours*antimisthia;
printf("oi kathares apodoxes ine:%g\n",kathipodoxes);
kratisis=kathipodoxes*pososto;
printf("oi kratisis ine:%g\n",kratisis);
akipodoxes=kathipodoxes+kratisis;
printf("oi akatharistes ipodoxes ine:%g\n",akipodoxes);
return 0;
}
