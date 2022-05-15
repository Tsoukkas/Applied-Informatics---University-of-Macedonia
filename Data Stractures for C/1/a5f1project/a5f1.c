#define megisto_plithos 1001
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];

typedef int stoixeio_synolou;

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);

void Dimiourgia(typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void displayset(typos_synolou set,stoixeio_synolou max)
{
	stoixeio_synolou i;

	for (i=0;i < max;i++)
	{
		if(Melos(i,set))
			printf(" %d",i);     //an ine melos tin emfanizi
	}
	printf("\n");
}

boolean isFibonacci(stoixeio_synolou n,typos_synolou synolo) {
 if(Melos(n,synolo)){
    return TRUE; }     //an ine melos epistrefi true
else {
    return FALSE;
}
}

void createFibonacciSet(stoixeio_synolou threshold,typos_synolou synolo){
  Dimiourgia(synolo);     //dimiurgi keno sinolo
  stoixeio_synolou f1,f2,tmp;
     f1=0;
     Eisagogi(f1,synolo);
    f2=1;
    for(stoixeio_synolou k=2;k<=threshold;k++){
    Eisagogi(f2,synolo);
    tmp=f1+f2;
    if(tmp>threshold){ break;}
    f1=f2;
    f2=tmp; }      //athroizi ta dio proigumena an ine megalitera tu max telioni alios ta isagi sto sinolo,kataxorite taftoxrona kai true stin siggekrimeni thesi tu sinolou
}

int main(){
stoixeio_synolou max,tmp;  //integers vasika
typos_synolou Fibonacci;   //pale en valume thesis..eso tus..  //dilosi sinolu
printf("Dwse to megistoarithmo.");
scanf("%d",&max);
if(max<2 || max>1000){
printf("Dwse to megistoarithmo.");
scanf("%d",&max);
}           //dilosi max timis
createFibonacciSet(max,Fibonacci);   //dimiurgi to sinolo fibonacci
displayset(Fibonacci,max);     //emfanisi stixion sinolu
while(1){
    printf("Dwse arithmo:");
    scanf("%d",&tmp);
    if(tmp<0){ break;}
   if(tmp>=0 || tmp<=1000){
    if(isFibonacci(tmp,Fibonacci)){
        printf("%s\n","Fibonacci!");
    }
    else {
        printf("%s\n","Not Fibonacci...");
    }
}
else{
     printf("Dwse arithmo:");
    scanf("%d",&tmp);
} }                                     //elexos an enas arithmos iparxi sto sinolo

        return 0;
        system("PAUSE");
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Εισάγει το στοιχείο στο σύνολο.
   Επιστρέφει: Το τροποποιημένο σύνολο
*/
{
    synolo[stoixeio] = TRUE;
}


boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Ελέγχει αν το στοιχείο είναι μέλος του συνόλου.
   Επιστρέφει: Επιστρέφει TRUE αν το στοιχείο είναι μέλος του και FALSE διαφορετικά
*/
{
    return synolo[stoixeio];
}



