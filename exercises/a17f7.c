#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int main(){
char onoma[10],eponimo[10],onomatepwnimo[20];
printf("Dwse onoma:");
gets(onoma);
printf("Dwse eponimo:");
gets(eponimo);
printf("\n");
strcpy(onomatepwnimo,onoma);
strcat(onomatepwnimo,eponimo);
for(int i=0;onomatepwnimo[i] != '\0';i++){
 if(onomatepwnimo[i] >= 'a' && onomatepwnimo[i] <= 'z') {
         onomatepwnimo[i] = onomatepwnimo[i] - 32;
} }
printf("Onoma = %s\n",onoma);
printf("Eponimo = %s\n",eponimo);
printf("onomatepwnimo = %s",onomatepwnimo);
return 0;
}
