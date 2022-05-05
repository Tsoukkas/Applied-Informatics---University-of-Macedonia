#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
int main (){
int kafedes;
int resta;
printf("dwse kafedes :");
kafedes=GetInteger();

if(kafedes>7){
printf("den ftanun ta xrimata gia tus kafedes");
}
else {
resta=500-(kafedes*70);
printf("Resta\n");
printf("Kermata 2E:%d\n",(resta/200));
printf("Kermata 1E:%d\n",(resta%200)/100);
printf("Kermata 50L:%d\n",(((resta%200)%100)/50));
printf("Kermata 20L:%d\n",((((resta%200)%100)%50)/20));
printf("Kermata 10L:%d\n",(((((resta%200)%100)%50)%20)/10));

}
return 0;
}




