#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>

#define M 100

typedef struct{
    char name[30];
    int apousies;
} studentT;

void readInput(FILE* infile, studentT students[], int *pApontes, int *pStudents);
void writeOutput(FILE* outfile, studentT students[], int apontes, int totalStudents);

int main(){

    FILE* infile;
    FILE* outfile;

    char inputFileName[30];
    char outputFileName[30];

    studentT students[M];
    int apontes, totalStudents;
    printf("Dwste onoma gia to arxeio eisodou: ");
    gets(inputFileName);
    printf("Dwste onoma gia to arxeio exodou: ");
    gets(outputFileName);

    infile = fopen(inputFileName, "r");
    if(infile == NULL){
        printf("Cannot open input file");
        exit(1);
    }

    outfile = fopen(outputFileName, "w");

    readInput(infile, students, &apontes, &totalStudents);
    writeOutput(outfile, students, apontes, totalStudents);

    fclose(infile);
    fclose(outfile);

    return 0;
}

void readInput(FILE* infile, studentT students[], int *pApontes, int *pStudents){

    int nscan, apousies;
    char name[30], comments[68], termch;
    int line=0;

    *pApontes = 0;
    *pStudents = 0;

    while(TRUE){

        nscan = fscanf(infile, "%30[^,], %d, %68[^\n]%c",
                                name, &apousies, comments, &termch);

        if(nscan == EOF)
            break;

        line++;

        if(nscan != 4 || termch != '\n'){
            printf("Error in line %d. Program termination\n", line);
            exit(1);
        }

        if(apousies > 100){
            strcpy(students[*pApontes].name, name);
            students[*pApontes].apousies = apousies;
            (*pApontes)++;
        }

        (*pStudents)++;
    }

}

void writeOutput(FILE* outfile, studentT students[], int apontes, int totalStudents){

    int i;

    fprintf(outfile, "%-30s%-9s\n", "ONOMATEPWNYMO", "APOYSIES");

    for(i=1; i<39; i++)
        fputc('-', outfile);
    fputc('\n', outfile);

    for(i=0; i<apontes; i++)
        fprintf(outfile, "%-30s%9d\n", students[i].name, students[i].apousies);

    for(i=1; i<39; i++)
        fputc('-', outfile);
    fputc('\n', outfile);

    fprintf(outfile, "%-30s%-9d\n", "SYNOLO MATHITWN:", totalStudents);
    fprintf(outfile, "%-30s%-9d\n", "SYNOLO APONTWN:", apontes);

}


