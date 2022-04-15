#include<stdio.h>
#include<string.h>
int main(){
int count=0;
char lexi[20];
printf("Dwse tin lexi:");
scanf("%s",&lexi[20]);
for(int i=0;i<=20;i++){
if(lexi[i]=='A' || lexi[i]=='a'){
count++;
}}
printf("o xaraktiras A emfanizete stin lexi %d fores",count);
return 0;
}
