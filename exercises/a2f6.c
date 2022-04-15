#include<stdio.h>
#include"simpio.h"
#define SIZE 100
void times(int x[SIZE],int *plithos){
int i=0;
printf("Enter the elements of the array, one per line.\n");
printf("Use -1 to signal the end of the list.\n");
do{
printf("? ");
x[i]=GetInteger();
if(x[i]==-1){ break;}
*plithos++;
i++;}while(TRUE);}
void calculatemaxmin(int *max,int *min,int x[SIZE]){
int i;
do{
 if(x[i]==-1){ break;}
if(x[i]>*max){
    *max=x[i];
} else if(*min>x[i]){
*min=x[i];
} i++;
}while(TRUE); }
int main(){
int i,x[SIZE],plithos=0;
int max=0,min=666;
times(x,&plithos);
calculatemaxmin(&max,&min,x);
printf("The range of values is %d-%d",min,max);
return 0;
}
