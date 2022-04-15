#include<stdio.h>
#include<string.h>
#include"simpio.h"
#include"genlib.h"
typedef struct{
char name[60];
int start;
int duration;
}ergasia;
void  ReadWorkpackages(int wp,ergasia a[]){
    int i;
    for(i=0;i<wp;i++){
        printf("WP Name:");
        scanf("%s",a[i].name);
        printf("WP Start Month:");
        scanf("%d",&a[i].start);

        printf("WP Duration:");
        scanf("%d",&a[i].duration);}
}
ergasia FindFirstWp(ergasia first,ergasia a[]){
        strcpy(first.name,a[0].name);
    first.start=a[0].start;
   first.duration=a[0].duration;
   return first;
}
void FindMakespan(int wp,ergasia a[],int *total){
    int index,p;
    p=a[0].duration;
    index=0;
    for(int i=0;i<wp;i++){
        if(a[i].duration>a[0].duration){
            p=a[i].duration;
            index=i;
        }
    }
    *total=a[index].start+p;
}



int main(){
int wp;
ergasia first;
int total;
printf("Total work packages:");
scanf("%d",&wp);
ergasia a[wp];
ReadWorkpackages(wp,a);
first=FindFirstWp(first,a);
printf("FIRST WP: %s start: %d duration: %d\n",first.name,first.start,first.duration);
FindMakespan(wp,a,&total);
printf("Total duration =%d",total);
return 0;
}
