#include"simpio.h"
#include<stdio.h>
#include<math.h>
#include"genlib.h"
int main (){
long Arithmo_Aytok,Orio;
long eti=0;
double rythmos;
printf("Dwse ton arxiko arithmo autokimhtwn:");
Arithmo_Aytok=GetLong();
printf("Dwse ton ethsio rythmo ayxhshs:");
rythmos=GetReal();
printf("Dwse to orio:");
Orio=GetLong();
while(Arithmo_Aytok<=Orio){
Arithmo_Aytok=ceil(Arithmo_Aytok*(1+rythmos));
eti+=1;
}
printf("%ld\n",eti);
printf("%ld\n",Arithmo_Aytok);
return 0;
}
