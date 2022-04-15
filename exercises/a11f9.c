#include<stdio.h>
#include"genlib.h"
#include"simpio.h"
#include<string.h>
typedef struct{
int number;
char name[28];
int points;
}players;

void readFromFile(FILE* infile,int *atoma,int *players10,players pextes[],int *sinolo){
int num,nscan,i=0;
char name1[28],termch;
int points22;
while(1){
nscan=fscanf(infile,"%d,%28[^,],%d,%c",&num,name1,&points22,&termch);
pextes[*atoma].number=num;
strcpy(pextes[*atoma].name,name1);
pextes[*atoma].points=points22;
(*atoma)++;
(*sinolo)+=num;
if(num>10){ (*players10)++;}
if(nscan == EOF){
break;
}
if(nscan !=4 || termch != '\n' ){
printf("something is wrong with %d line ",i);
}
i++;}
}

void writeToFile(FILE* outfile,int *atoma,int *players10,players pextes[],int *sinolo){
int i=0;
fprintf(outfile,"%-28s%-9s","ONOMATEPWNIMO","PONTOI");
fprintf(outfile,"-----------------------------------\n");
while((*atoma)>=1){
fprintf(outfile,"%-28s%-9s",pextes[*atoma].name,pextes[*atoma].number);
fprintf(outfile,"-----------------------------------\n");
(*atoma)--;
fprintf(outfile,"%-28s%-9d","SYNOLO PONTWN",*sinolo);
fprintf(outfile,"%-28s%-9d","SYNOLO PAIKTVN >= 10",*players10);
} }



int main(){
FILE* infile;
FILE* outfile;
int *atoma,*players10;
players pextes[100];
int *sinolo;
printf("Dwse onoma arxiou isodou:");
puts(infile);
printf("Dwse onoma arxiou exodou:");
puts(outfile);
if(infile==NULL){
printf("The file doesn't exists");
exit(1);
}
readFromFile(infile,&atoma,&players10,pextes,&sinolo);
writeToFile(outfile,&atoma,&players10,pextes,&sinolo);
fclose(infile);
fclose(outfile);
return 0;
}
