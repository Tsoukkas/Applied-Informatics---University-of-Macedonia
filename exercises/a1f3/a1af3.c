#include<stdio.h>
#include"simpio.h"
#include<math.h>
#include"genlib.h"
#define Arithmos_Aytok 80000
#define Orio 160000
#define Rythmos 0.07
int main(){
long years=0;
long finalnum;
finalnum= Arithmos_Aytok;
while(finalnum<=Orio)
    {
years+=1;
finalnum=ceil(finalnum*(1+Rythmos));
}
printf("%ld\n",years);
printf("%ld\n",finalnum);
return 0;
}
