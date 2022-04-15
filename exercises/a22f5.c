#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
#define size 16
long long GetLongLong(void);
int main(){
long long num,k,a[size];
long long d;
long long sum=0;
printf("Insert card number:");
k=num=GetLongLong();
for(int i=size-1;i>=0;i--){
a[i]=k%10;
k=k/10;
}
if ((a[0]<4 || a[0]>7)||(num>10000000000000000 || num<1000000000000000)) {
printf("%lld is invalid",num);
} else {
for(int i=0;i<size;i+=2){
a[i]=2*a[i];
if(a[i]>=10){
d=(a[i]%10)+(a[i]/10);
a[i]=d;}
}
for(int i=0;i<size;i++){
sum+=a[i];}
if(sum%10==0){
printf("%lld is VALID",num);
}
else{
printf("%lld is invalid",num);
} }
return 0 ;
}
long long GetLongLong(void)
{
 string line;
 long long value;
 char termch;
 while (TRUE) {
 line = GetLine();
 switch (sscanf(line, " %lld %c", &value, &termch)) {
 case 1:
 FreeBlock(line);
 return (value);
 case 2:
 printf("Unexpected character: '%c'\n", termch);
 break;
 default:
 printf("Please enter an integer\n");
 break;
 }
 FreeBlock(line);
 printf("Retry: ");
 }
}
