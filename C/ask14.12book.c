#include<stdio.h>
#include<string.h>
#include"genlib.h"
#include"simpio.h"
char Read(FILE *infile){
double num1,num2,num3;
int max=0;
double mo=0;
int nscan;
char name1[20],name2[20];
while(1){
nscan=fscanf(infile,"%20[^" "],%lf,%lf,%lf",name1,&num1,&num2,&num3);
mo=(num1+num2+num3)/3;
if(mo>max){
max=mo;
strcpy(name2,name1);
}
}
return name2[20];
}


int main(){
FILE *infile;
char name[20],high[20];
scanf("%s",&name[20]);
infile=fopen("name","r");
high[20]=Read(infile);
printf("ton megalitero meso oro ton exi o %s",high[20]);
return 0;
}
