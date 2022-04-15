#include<stdio.h>
int main(){
FILE *infile,*outfile;
char name[20],name1[20];
int code;
char ch;
double imer;
printf("Dwse onoma arxiou pros anagnosi:");
scanf("%s",&name);
printf("Dwse onoma arxiou gia egrafi:");
scanf("%s",&name1);
infile=fopen("name","r");
outfile=fopen("name1","w");
if(infile==NULL){
printf("This file doesnt exists");}
int nscan,i=0;
while(1){
nscan=fscanf(infile,"%d%c%lf",&code,&ch,&imer);
if(nscan==EOF){
break;
}
else{
imer+=imer*(1+0.20);
fprintf(outfile, "%7d%13.1lf\n", code, imer);
i++;}
}
fclose(infile);
fclose(outfile);
return 0;
}
