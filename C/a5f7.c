#include<stdio.h>
#include<string.h>
#include<ctype.h>
bool IsConsonant(char ch){
char a;
switch (a){
case ‘a’:
case ‘e’:
case ‘i’:
case ‘o’:
case ‘u’:
case 'A':
case 'E':
case 'I':
case 'O':
case 'U':
 return (FALSE);
default:
return TRUE;
}}

void print(){
char b;
for(b='a';b<='z';b++){
if(b=='a' || b=='e' || b=='i' || b=='o' || b=='u'){
exit(1);}
else{
printf("%c ",b);
}
}
for(b='A';b<='Z';b++){
if(b=='A' || b=='E' || b=='I' || b=='O' || b=='U'){
exit(1);}
else{
printf("%c ",b);
}
}
}


int main(){
char ch;
printf("Dwse ena xaraktira");
scanf("%c",&ch);
bool c;
c=Isconsonant(ch);
print();
return 0;
}
