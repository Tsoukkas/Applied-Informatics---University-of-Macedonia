#include<stdio.h>
#include<string.h>
void DateString(int day,int month,int year,char date[]){
strcat(date,day);




}
int main(){
int day,month,year;
char date[10];
printf("Give us a day:");
scanf("%d",&day);
printf("Give us a month:");
scanf("%d",&month);
printf("Give us the year:");
scanf("%d",&year);
DateString(day,month,year,date);
}
