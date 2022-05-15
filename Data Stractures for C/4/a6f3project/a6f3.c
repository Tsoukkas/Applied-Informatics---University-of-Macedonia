#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define QueueLimit 10

typedef int QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος int */

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
	int Count;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
    Queue->Count= 0;
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Count == 0);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return (Queue.Count) == (QueueLimit) ;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
		(Queue->Count)--;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullQ(*Queue))
	{
	    (Queue->Count)++;
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue\n");
}

void TraverseQ(QueueType Queue) {
	QueueElementType current=0;
	QueueElementType i;
	if(EmptyQ(Queue)) {
        printf("Empty queue\n"); }
        else{
    current=Queue.Front;
    for(i=0;i<Queue.Count;i++){
        printf("%d ",Queue.Element[current]);
        current=(current+1)% QueueLimit; }

	printf("\n");
} }

int main(){
QueueType s;             //dilosi uras
QueueElementType item;
CreateQ(&s);           //dimiurgia uras
printf("---a---\n");
for(int i=0;i<10;i++){
    AddQ(&s,i);
}              //prosthiki stixiu stin ura
printf("Queue: ");
TraverseQ(s);                 //emfanisi stixion uras
printf("Front=%d Rear=%d Count=%d",s.Front,s.Rear,s.Count);        //sti sinexia kai ton vatmo tu front rear kai count
printf("\n");
printf("---b---\n");
AddQ(&s,77);
printf("Queue: ");
TraverseQ(s);
printf("Front=%d Rear=%d Count=%d",s.Front,s.Rear,s.Count);
printf("\n");
printf("---c---\n");
RemoveQ(&s,&item);
printf("Queue: ");
TraverseQ(s);
printf("Removed item=%d Front=%d Rear=%d Count=%d",item,s.Front,s.Rear,s.Count);
printf("\n");
printf("---d---\n");
AddQ(&s,77777);
printf("Queue: ");
TraverseQ(s);
printf("Front=%d Rear=%d Count=%d",s.Front,s.Rear,s.Count);
printf("\n");
printf("---e---\n");
AddQ(&s,7777);
printf("Queue: ");
TraverseQ(s);
printf("Front=%d Rear=%d Count=%d",s.Front,s.Rear,s.Count);
printf("\n");
printf("---f---\n");
while(!EmptyQ(s)){
    RemoveQ(&s,&item);
    printf("Queue: ");
    TraverseQ(s);
    printf("Remove item=%d Front=%d Rear=%d Count=%d",item,s.Front,s.Rear,s.Count);
    printf("\n");
}
return 0;
}
