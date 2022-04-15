#include<stdio.h>
int main(){
FILE *infile,*outfile;
infile=fopen("i12f9.dat","r");
outfile=fopen("Foro12f9.dat","w");
if(infile==NULL){
printf("Afto to arxio den iparxi");
}
int nscan,i=0;
double foros=0;
long afm;
char termch;
char onomatepwnimo[26];
float etisies;
while(1){
nscan=fscanf(infile,"%ld[^,],%26[^,],%f,%c",&afm,onomatepwnimo,&etisies,&termch);
if(nscan==EOF){
break;
}
else{
if(etisies<=10000){
foros=etisies*0.14; }
else if(etisies>10000 && 283000<=etisies){
foros=etisies*0.19; }
else if(etisies>23000 && 55000<=etisies ){
foros=etisies*0.23;
}
else{
foros=etisies*0.28;}
fprintf(outfile,"%-20s%-20s%-20s","AFM","ONOMATEPWNIMO","FOROS");
fprintf(outfile,"%-20ld%-20s%-20lf",afm,onomatepwnimo,foros);
i++;
}}
fclose(infile);
fclose(outfile);
return 0;
}
