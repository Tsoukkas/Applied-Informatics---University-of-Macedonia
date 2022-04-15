#include<stdio.h>
#include<math.h>
#include"simpio.h"
#include"genlib.h"
long encode(long start_c){
start_c=start_c*100+((98 - (start_c*100) % 97) % 97);
return start_c;
}
bool check(long start_c){
    if((start_c)%97==1){
        return 1 ;
    }
    else
        return 0 ;
}

int main(){
long lower,upper;
long i;
printf("Lower limit:");
lower=GetLong();
printf("Upper limit:");
upper=GetLong();
for(i=lower;i<=upper;i++)
printf("Code:%d Encoding:%ld IsValid:%s\n",i,encode(i),check(encode(i))?"yes":"no");
return 0;
}
