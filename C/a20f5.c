#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
int main(){
int array[5];
int temp;
for(int i=0;i<5;i++){
printf("Enter number:");
array[i]=GetInteger();
}

temp=array[4];
for(int i=4;i>0;i--)
{
array[i]=array[i-1];
}
array[0]=temp;
for(int i=0;i<5;i++){
printf("%d",array[i]);
}
return 0;
}
