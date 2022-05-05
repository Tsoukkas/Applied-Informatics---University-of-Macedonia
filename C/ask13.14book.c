#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
#include<string.h>

typedef struct{
char onomasia[20];
float bathmos;
char examino;
}mathima;

int main(){
mathima m1,m2;
mathima *p1,*p2;
printf("Dwse onomasia\n");
gets(m1.onomasia);
printf("Dwse vathmo\n");
m1.bathmos=GetReal();
printf("Dwse examino\n");
m1.examino=getchar();
p1=&m1;
printf("onomasia mathiti 1 :%s\n",(*p1).onomasia);
printf("vathmos mathiti 1 :%f\n",(*p1).bathmos);
printf("examino mathiti 1 :%c\n",(*p1).examino);
for(int i=0;i<20;i++){
printf("-");
}
printf("\n");
printf("Dwse onomasia\n");
scanf("%s",(*p2).onomasia);
printf("Dwse vathmo\n");
scanf("%f",(*p2).bathmos);
printf("Dwse examino\n");
scanf("%c",(*p2).examino);
m2=*p2;
printf("onomasia mathiti 1 :%s\n",m2.onomasia);
printf("vathmos mathiti 1 :%f\n",m2.bathmos);
printf("examino mathiti 1 :%c\n",m2.examino);
return 0;
}
