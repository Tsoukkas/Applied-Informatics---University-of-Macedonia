#include<stdio.h>
#include<string.h>
#include"genlib.h"
#include"simpio.h"
typedef struct {
int code;
char surname[16];
long poso;
int area;
}worker;

void jobs(int n,worker workers[n]){
int i;
for(i=0;i<n;i++){
workers[i].code=GetInteger();
scanf("%s",workers[i].surname);
workers[i].poso=GetLong();
workers[i].area=GetInteger();
}}


void Data(int n,worker workers[n],int *total,int *total1,int *total2,int *total3){
int i;
for(i=0;i<n;i++){
if(workers[i].area==1){
(*total)+=workers[i].poso;}
if(workers[i].area==2){
(*total1)+=workers[i].poso;}
if(workers[i].area==3){
(*total2)+=workers[i].poso;}
else{
(*total3)+=workers[i].poso;}} }



void print_it(int n,worker workers[n],int *total,int *total1,int *total2,int *total3){
printf("%-10s%-12s\n", "PERIOXI", "SYN.APOUSIWN");
printf("------------------------------------------------\n");
for(int i=0;i<n;i++){
if(workers[i].area==1)
printf("%s  %d\n",workers[i].surname,*total);
else if(workers[i].area==2){
printf("%s  %d\n",workers[i].surname,*total1);}
else if(workers[i].area==3){
printf("%s  %d\n",workers[i].surname,*total2);}
else{
printf("%s  %d\n",workers[i].surname,*total3);}
}}


int main(){
int n;
int *total;
int *total1;
int *total2;
int *total3;
printf("Dwse to plithow twn politwn:");
n=GetInteger();
worker workers[n];
jobs(n,workers);
Data(n,workers,&total,&total1,&total2,&total3);
print_it(n,workers,&total,&total1,&total2,&total3);
return 0;
}
