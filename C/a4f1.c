#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
int main()
{
double SaleAmount,Profit;
int rate;
long PuchaseAmount;
printf("Dose kathari axia :");
PuchaseAmount=GetLong();
printf("Dose pososto kerdous:");
rate=GetInteger();
Profit=PuchaseAmount*rate/100.0;
printf("to kerdos ine %g\n",Profit);
SaleAmount=PuchaseAmount+Profit;
printf("To sinoliko poso ine %g\n",SaleAmount);
return 0;
}
