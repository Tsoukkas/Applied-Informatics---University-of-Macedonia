#include<stdio.h>
typedef struct{
char name[10];
char surname[10];
int hour_pay;
int hours;
double mixtes;
double kratisis;
double foros;
double kathares;
}kathigites;
void  get_data(kathigites a[],int num){
for(int i=0;i<num;i++){
printf("Dwse ta stoixeia tou kathigiti %d\n",i);
printf("Dwse onoma:");
scanf("%s",&a[i].name);
printf("Dwse eponimo:");
scanf("%s",&a[i].surname);
printf("Dwse mistho oras:");
scanf("%d",&a[i].hour_pay);
printf("Dwse ores ergasias:");
scanf("%d",&a[i].hours);
printf("\n");
}}
void  calc_salaries(kathigites a[],int num){
for(int i=0;i<num;i++){
a[i].mixtes=(a[i].hour_pay)*(a[i].hours);
a[i].kratisis=(a[i].mixtes)*0.15;
a[i].foros=((a[i].mixtes)*0.7)-a[i].kratisis;
}}
void print(kathigites a[],int num){
for(int i=0;i<num;i++){
printf("%-10s%-10s%-20s%-20s%-20s%-20s%-10s%-10s","Name","Surname","Hourly rate","Hours worked","Gross","Deductions","Tax","Net");
printf("--------------------------------------------------------------------------------------------------------------\n");
printf("%-10s%-10s%-20d%-20d%-20lf%-20lf%-10lf%-10lf",a[i].name,a[i].surname,a[i].hour_pay,a[i].hours,a[i].mixtes,a[i].kratisis,a[i].foros);
}
printf("---------------------------------------------------------------------------------------\n"); }


int main(){
int num;
printf("Dwse ton arithmo twn kathigitwn:");
scanf("%d",&num);
kathigites a[num];
printf("\n");
get_data(a,num);
calc_salaries(a,num);
print(a,num);
return 0;
}
