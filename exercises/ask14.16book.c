#include<stdio.h>
#include<string.h>
#include"genlib.h"
#include"simpio.h"
struct stoixeia{
char onoma[30];
char mhtroo[5];
float vathmoi[10];
int ilikia;
} foitites[100];
void write(FILE *outfile){
int i=0;
while(i<100){
fprintf(outfile,"%-30s%-5s%-10f%d",foitites[i].onoma,foitites[i].mhtroo,foitites[i].vathmoi,foitites[i].ilikia);
i++;
}}

int main(){
FILE *outfile;
printf("Dwse onoma arxiou:");
char name[20];
gets(name);
outfile=fopen("name","w");
write(outfile);
fclose(outfile);
return 0;
}
