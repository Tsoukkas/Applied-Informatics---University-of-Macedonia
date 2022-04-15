#include<stdio.h>
#include<string.h>
typedef struct {
int entasi;
int thermokrasia;
int igrasia;
int batery;
int liturgia;
}client;

int main(){
int e,t,i,b,l;
printf("Dwse entasi anemu:");
scanf("%d",&e);
printf("Dwse thermokrasia:");
scanf("%d",&t);
printf("Dwse igrasia:");
scanf("%d",&i);
printf("Dwse katastasi mpatarias:");
scanf("%d",&b);
printf("Dwse liturgia:");
scanf("%d",&l);
client s1;
s1.entasi=e;
s1.thermokrasia=t;
s1.igrasia=i;
s1.batery=b;
s1.liturgia=l;
}
