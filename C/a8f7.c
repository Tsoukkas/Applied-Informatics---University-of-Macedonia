#include<stdio.h>
#include<string.h>
#include<ctype.h>
void Capitalize(char lexi[20]){
for(int i=0;lexi[i]!= '\0';i++){
if((lexi[i])>='A' && 'Z'<=lexi[i]){
tolower(lexi[i]); } }
printf("%s",lexi);
}


int main(){
char lexi[20];
printf("Dwse lexi pou na arxizi me kefaleo:");
scanf("%s",lexi);
Capitalize(lexi);
return 0;
}
