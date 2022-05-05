#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
int main ()
{
int mera;
printf("dose ena arithmo apo to 1 eos to 7: ");
mera=GetInteger();
switch (mera)
 {
 case 1:
 printf("The day is Monday");
 break;
 break;
 case 2:
 printf("The day is Tuesday");
 break;
 case 3:
 printf("The day is Wednesday");
 break;
 case 4:
 printf("The day is Thursday");
 break;
 case 5:
 printf("The day is friday");
 break;
 case 6 :
 printf("The day is Saturday");
 break;
 case 7 :
 printf("The day is Sunday");
 break;
 default :
 printf("ERROR");
}
return 0;
}
