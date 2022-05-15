#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#define QueueLimit 4

typedef struct{
int ora_afiksis,start;
int xronos_anamonis,end;
} QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                ενδεικτικά τύπος int */
typedef enum {FALSE, TRUE} boolean;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
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
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue");
}
void TraverseQ(char a[],QueueType Queue) {
	int current;
	int i=1;
	if(!EmptyQ(Queue)){
        printf("%s\n",a);
	current = Queue.Front;
	printf("Client \t\t\tStart\tEnd\tArrival\tStay\n");     //ta emfanizi stixismena
	while (current != Queue.Rear) {
        printf("Client %d \t\t%d\t%d\t%d\t%d\n",i, Queue.Element[current].start,Queue.Element[current].end,Queue.Element[current].ora_afiksis,Queue.Element[current].xronos_anamonis);
		current = (current + 1) % QueueLimit;
		i++;
	} }
	else{
	printf("%s is empty\n",a);
}
printf("\n"); }

void ReadCustomer(QueueType *Queue){
QueueElementType tmpCustomer;
scanf("%d,%d",&tmpCustomer.ora_afiksis,&tmpCustomer.xronos_anamonis);
tmpCustomer.start=-1;
tmpCustomer.end=-1;
AddQ(Queue,tmpCustomer);
}

QueueType TimesInQueue(QueueType *Queue){
int earliestStart =0; //χρόνος έναρξης εξυπηρέτησης
int currentStart=0; //ώρα έναρξης εξυπηρέτησης για τρέχοντα πελάτη
int currentEnd=0; //ώρα λήξης εξυπηρέτησης για τρέχοντα πελάτη
QueueType QueueServiced; //Ουρά εξυπηρετηθέντων
QueueElementType CurrentCust;
CreateQ(&QueueServiced);
while(!(EmptyQ(*Queue))){
//Αφαίρεσε τον πελάτη από την αρχή της ουράς αναμονής
RemoveQ(&(*Queue),&CurrentCust);
//Αν η ώρα άφιξης του πελάτη είναι μετά τον χρόνο έναρξης
//εξυπηρέτησης
if(CurrentCust.ora_afiksis>earliestStart){
//Θέσε την τρέχουσα ώρα έναρξης ίση με την ώρα άφιξης πελάτη
currentStart=CurrentCust.ora_afiksis;
}
else{
//Θέσε την τρέχουσα ώρα έναρξης ίση με τον χρόνο έναρξης
//εξυπηρέτησης
currentStart=earliestStart; }
//Ενημέρωσε την ώρα λήξης εξυπηρέτησης για τον τρέχοντα πελάτη
 currentEnd=currentStart +CurrentCust.xronos_anamonis;
//Ενημέρωσε τον χρόνο έναρξης εξυπηρέτησης για τον επόμενο πελάτη
earliestStart=currentEnd;
//Ενημέρωσε τον τρέχοντα πελάτη με τα νέα του στοιχεία
CurrentCust.start=currentStart;
CurrentCust.end= currentEnd;
//Εισήγαγε τον τρέχοντα πελάτη στην ουρά εξυπηρετηθέντων
AddQ(&QueueServiced,CurrentCust);
}
//Επέστρεψε την ουρά εξυπηρετηθέντων
return QueueServiced;
}

int main(){
QueueType WaitingQueue,ServiceQueue;
CreateQ(&WaitingQueue);
CreateQ(&ServiceQueue);          //dilosi kai dimiurgia ourwn
for(int i=1;i<QueueLimit;i++){
    printf("Give: arrival time,stay time for client %d:",i);
    ReadCustomer(&WaitingQueue);
}                         //kataxorisi oras p tha pai o pelatis kai poses ores tha mini
TraverseQ("Waiting Queue",WaitingQueue);
ServiceQueue=TimesInQueue(&WaitingQueue);
TraverseQ("Waiting Queue",WaitingQueue);
TraverseQ("Service Queue",ServiceQueue);
return 0;
}
