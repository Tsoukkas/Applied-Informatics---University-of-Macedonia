#include<stdio.h>
#include<stdlib.h>
void check(int num,int a[],int *small,int *big){
for(int i=0;i<100;i++){
if(a[i]>num){
(*big)++;
}
else{
(*small)++;
}}}
int main(){
int a[100];
int num,small=0,big=0;
printf("Dwse ena arithmo:");
scanf("%d",&num);
for(int i=0;i<100;i++){
a[i]=rand() % 100;
}
check(num,a,&small,&big);
printf("iparxoun %d mikroteri kai %d megaliteroi",small,big);
return 0;
}
