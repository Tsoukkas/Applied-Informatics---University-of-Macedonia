#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define YEARS    4
#define SUBJECTS 8
typedef struct{
int etos;
int afkson_num;
} five_to_sevenT;
int analyze_table(int grades_table[YEARS][SUBJECTS],  five_to_sevenT five_to_seven_table[],int *plithos,int *plithos10){
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++){
            if(grades_table[i][j]>=5 && grades_table[i][j]<=7){
                five_to_seven_table[i].etos=grades_table[i][j];
                five_to_seven_table[i].afkson_num=grades_table[i][j];
                (*plithos)++;
            }
            if(grades_table[i][j]==10){
                (*plithos10)++;
            }
        }
    }
}
void print_data(five_to_sevenT five_to_seven_table[],int plithos10,float pososto){
printf("5 to 7 grades:\n");
for(int i=0;i<32;i++){
printf("Year: %d, Subject: %d\n",five_to_seven_table[i].etos,five_to_seven_table[i].afkson_num); }
printf("Count of 10s:%d\n",plithos10);
printf("Percentage of 10s:%.2f\n",pososto);
}
int read_data(char alpha[],int x,int y){
    printf("%s",alpha);
    scanf("%d",&x);
    if(x>=0 || x<=10){
        return x;
    }
    else{
        printf("Try again:");
        scanf("%d",&x);

    }
}
void update_data(five_to_sevenT five_to_seven_table[],int grades_table[YEARS][SUBJECTS]){
   int year[32],sub[32],grade[32];
int j=0;
for(int i=0;i<32;i++){

    printf("Year (0-3):");
    scanf("%d",&year[i]);
    printf("Subject (0-7):");
    scanf("%d",&sub[i]);
    if(sub[i]<0 || sub[i]>7){
    printf("Subject (0-7):");
    scanf("%d",&sub[i]);  }
    printf("Grade (0-10):");
    scanf("%d",&grade[i]);
    if(grade[i]<0 || grade[i]>10){
    printf("Grade (0-10):");
    scanf("%d",&grade[i]);
    }
    grades_table[i][j]=grade[i];
    j++;
    }
}
int main() {
    int plithos=0,x,y,n;
    float pososto;
     int a;
    char alpha[32]="Grade (0-10):";
    int plithos10=0;
     five_to_sevenT five_to_seven_table[32];
    int grades_table[YEARS][SUBJECTS] = {
        {5, 6, 6, 2, 8, 7, 10, 7},
        {6, 2, 3, 3, 9, 8,  3, 9},
        {6, 7, 5, 8, 6, 7, 10, 5},
        {1, 3, 3, 8, 9, 4,  3, 6}
    };
   analyze_table(grades_table,five_to_seven_table,&plithos,&plithos10);
   pososto=(32/plithos10)*0.100;
   print_data(five_to_seven_table,plithos10,pososto);
    n=read_data(alpha,x,y);
     printf("Do you want to update a grade? (1 for YES / 0 for NO):");
    scanf("%d",&a);
    if(a!=0 || a!=1){
    printf("Do you want to update a grade? (1 for YES / 0 for NO):%d",a);
    scanf("%d",&a);}
    else{
    update_data(five_to_seven_table,grades_table);
    analyze_table(grades_table,five_to_seven_table,&plithos,&plithos10);
    pososto=(32/plithos10)*0.100;
    print_data(five_to_seven_table,plithos10,pososto);
    }
    return 0;
}

