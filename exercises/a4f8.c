#include<stdio.h>
#include<string.h>
typedef struct{
char onomatepwnimo[26];
char diefthinsi[26];
long zip;
char poli[26];
char country[16];
int type;
int varos;
}d;
void read(d demata[],int n){
for(int i=0;i<n;i++){
printf("Name:");
scanf("%s",&demata[i].onomatepwnimo);
printf("Address:");
scanf("%s",&demata[i].diefthinsi);
printf("Zip:");
scanf("%ld",&demata[i].zip);
printf("City:");
scanf("%s",&demata[i].poli);
printf("Country:");
scanf("%s",&demata[i].country);
printf("Type <1 or 2>:");
scanf("%d",&demata[i].type);
printf("Weight:");
scanf("%d",&demata[i].varos);
}}
void calculate(d demata[],int n,int *value,int *value1,int *a,int *b){
for(int i=0;i<n;i++){
if(demata[i].type==1){
(*value)+=(demata[i].varos)*0.40;
(*a)++;
}
else{
(*value1)+=(demata[i].varos)*0.84;
(*b)++;
}}}
int main(){
int n,value=0,value1=0,a=0,b=0;
printf("Dwse arithmo paraggeliwn:");
scanf("%d",&n);
d demata[n];
read(demata,n);
calculate(demata,n,&value,&value1,&a,&b);
printf("%d %d\n",a,value);
printf("%d %d\n",b,value1);
return 0;
}
