#include<stdio.h>
#include<string.h>
void convert(char protasi[]){
    int i=0;
while(1){
if (protasi[i] >= 'a' && protasi[i] <='z') {
if(protasi[i]='\0'){ break; }
 protasi[i]=protasi[i] - ('a'-'A');}

} }
int main(){
char protasi[30];
printf("Dwse protasi:");
gets(protasi);
char caps[30];
convert(protasi);
printf("%s",protasi[30]);
return 0;
}
