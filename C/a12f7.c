#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
char names[100][20];
for(int i=1;i<=100;i++){
printf("Passenger in seat %d :",i);
scanf("%s",&names[i]);
if(names[i]==names[i-1]) {
printf("Passenger %s already exists.",names[i]);
scanf("%s",&names[i]);
}
if(names[i]=="----"){
    break;
} }
printf("--------------\n");
for(int i=1;i<=100;i++){
printf("In seat %d:%s\n",i,names[i]);
}
return 0;
}
