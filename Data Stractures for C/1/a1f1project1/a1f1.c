#include <stdio.h>
#include <stdlib.h>

#define megisto_plithos 199

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];  //gia kapio agnosto logo otan kanume sinolo apo edo den vazume thesis
typedef int stoixeio_synolou;

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


boolean isPrime(stoixeio_synolou n)
{
   stoixeio_synolou i;
    boolean flag;
    flag=TRUE;

    for(i=2;i<=n/2;++i){ //stin usia i kaliteri tis periptosi ine otan o arithmos ine artios ektos an ine to 2
        if(n%i==0){
            flag=FALSE;
            break;
        }
    }

    return flag;
}                       //vriski tus protus arithmus tu sinolu

void Dimiourgia(typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}


void createPrimeSet(typos_synolou s,stoixeio_synolou first,stoixeio_synolou last){
 stoixeio_synolou i;
 Dimiourgia(s);          //dimiurgi ena keno sinolo
 for(i=first;i<=last;i++){
    if(isPrime(i)){
    Eisagogi(i,s);  //an to i einai protos arithmos tha mpi sto keno sinolo stin siggekrimeni thesi true
    }

 }
} //opios arithmos ine protos kataxorite sto sinolo

void displayset(typos_synolou set,stoixeio_synolou first,stoixeio_synolou last)
{
	stoixeio_synolou i;

	for (i=first;i <last;i++)
	{
		if(Melos(i,set))     //an to i aniki sto sinolo p dimiurgisame stin proigumeni sinartisi tha emfanisti alios oxi
			printf(" %d",i);
	}
	printf("\n");
}                         //an aniki sto sinolo o arithmos emfanizete

int main()
{
 stoixeio_synolou first,last;   //einai stoixeia sinolu gia afto exun afto ton tipo
 printf("Give us the first number :");
 scanf("%d",&first);
 if(first>=200 || first<2){
    printf("Gibe us the first number :");
    scanf("%d",&first);
 }

 printf("Give us the last number :");
 scanf("%d",&last);
 if(last>200 || last<2){
 printf("Give us the last number :");
    scanf("%d",&last);
 }                         //ta kataxorume
 typos_synolou synolo;  //den vazume thesis //dilosi sinolu metaksi twn arithmon pou dosame
createPrimeSet(synolo,first,last);
 displayset(synolo,first,last);
  return 0;

}






