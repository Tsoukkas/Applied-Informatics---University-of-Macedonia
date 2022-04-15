#include<stdio.h>
#include<string.h>
#include"simpio.h"
#include"genlib.h"
typedef struct {
int lines;
int lexis;
int kena;
}myne;
void read_it(FILE *infile,myne d){
int nscan,i;
char termch;
char a[10];
while(nscan != EOF){
nscan=fscanf(infile,"%10[^,],%c",a,&termch);
d.lines++;
if(nscan != 2 || termch != '\n'){
printf("something went wrong with the line %d",d.lines);
exit(1);}
if(a[i] != ' '){
d.lexis++; }
else {
d.kena++;
} } }
void write_it_down(FILE *outfile,myne d){
fprintf(outfile,"the lines are %d",d.lines);
fprintf(outfile,"the words are %d",d.lexis);
fprintf(outfile,"the spaces are %d",d.kena);
}
void print_it(myne d){
printf("lines:",d.lines);
printf("lexis:",d.lexis);
printf("spaces:",d.kena);
}
int main(){
myne d;
FILE *infile,*outfile;
infile=fopen("i5f9.dat","r");
if(infile==NULL){
printf("cant open the file..");
exit(1);
}
outfile=fopen("outfie.dat","w");
read_it(infile,d);
write_it_down(outfile,d);
print_it(d);
return 0;
}
