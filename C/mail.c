#include<stdio.h>
#include<string.h>
int main(){
char name[15],server[15];
char mail[30];
printf("Give us your mail address\n");
gets(mail);
int index=0;
for(int i=0;mail[i] != '@';i++){
index++;
}
strncpy(name,mail,index);
name[index]='\0';
strcpy(server,mail+index+1);
printf("name:%s\n",name);
printf("server:%s\n",server);
return 0;
}
