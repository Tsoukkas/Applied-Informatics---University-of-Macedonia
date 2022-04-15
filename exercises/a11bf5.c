#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

#define CTS 10
#define S 3
void ReadData(int rows,int coloumns,double table[CTS][S]);
double calculateaverage(int rows,int coloumns,double table[rows][coloumns]);
void calculateavcity(int rows,int columns,double table[rows][columns],double table2[rows]);
void calculatemaxdeviation(int rows,int columns,double table[rows][columns],double md[rows],double natavg);
void Print_Results(int rows,double avg,double average[rows],double md[rows]);
int main()
{
    double temper[CTS][S];
    double average[CTS], mdeviation[CTS];
    double natavg;
      /*Read all Temperatures*/
    ReadData(CTS,S,temper);
    /*Calculating The Average of all Cities&Temps*/
    calculateaverage(CTS,S,temper);
    /*Calculating Average temp on each City*/
    calculateavcity(CTS,S,temper,average);
    calculatemaxdeviation(CTS,S,temper,mdeviation,natavg);
    /*Printing results*/
   Print_Results(CTS, natavg, average, mdeviation);
    return 0;
}
void ReadData(int rows,int columns,double table[rows][columns]){
    /*Read all Temperatures*/
	for (int i=0; i<CTS; i++)
		for (int j=0; j<S; j++)
		  	{ printf("Temp of City %d During %d 8-hour period: ",i,j);
              table[i][j] = GetReal();
              }
}
double calculateaverage(int rows,int coloumns,double table[rows][coloumns]){
/*Calculating The Average of all Cities&Temps*/
  int   natavg = 0;
    for (int i=0; i<rows; i++)
      for (int j=0; j<coloumns; j+=1)
         natavg += table[i][j];
    natavg = natavg/(rows*coloumns);
return natavg;
}
void calculateavcity(int rows,int columns,double table[rows][columns],double average[rows]){
 /*Calculating Average temp on each City*/
for (int i=0; i<rows; i++)
    {
    average[i] = 0;
        for (int j=0; j<columns; j++)
        {
           average[i] += table[i][j];
        }
        average[i] = average[i]/columns;
    }
}
void calculatemaxdeviation(int rows,int columns,double table[rows][columns],double md[rows],double natavg){
double devnat[rows][columns];
/*Calculating Standard Deviation*/
    for (int i=0; i<rows; i++)
        for (int j=0; j<columns; j++)
            devnat[i][j] = fabs(natavg-table[i][j]);

	/*Calculating max Deviation*/
    for (int i=0; i<rows; i++)
    {
        md[i] = devnat[i][0];
        for(int j=1; j<columns; j++)
            if (md[i]<devnat[i][j]) md[i] = devnat[i][j];
    }
}
void Print_Results(int rows,double avg,double average[rows],double md[rows]){
 printf("%3.1f\n",avg);
    for (int i=0; i<rows; i+=1)
		printf("City %d  %.1f  %.1f\n",i, average[i], md[i]);
}
