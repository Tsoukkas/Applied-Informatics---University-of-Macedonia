#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define StackLimit 200   // το όριο μεγέθους της στοίβας, ενδεικτικά ίσο με 50


typedef char StackElementType;   // ο τύπος των στοιχείων  της στοίβας
                                //ενδεικτικά τύπος int
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται: Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος: Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:  Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

int main(){
StackType s;
CreateStack(&s);   //dimiurgi stiva
boolean valid;
int flag;
char ch;
char item;

flag=0;
valid=TRUE;

printf("Enter a string\n");
scanf("%c",&ch);getchar();  //dini ton proto xaraktira
if(ch=='#'){
return 0;
}  // an ine o # telioni to programa
while(ch != '#' && valid==TRUE){
if(flag==0){    //dld an den edose C akoma
if(ch=='C'){
flag=1;
scanf("%c",&ch);getchar();            //an to edose kai pai ston epomeno xaraktira
}
else{
Push(&s,ch);
scanf("%c",&ch);getchar();
} }
else{
if(!EmptyStack(s)){
   Pop(&s,&item);
     if(item!=ch){
    valid=FALSE;}
     else{
  scanf("%c",&ch);getchar();}
}
else{
   valid=FALSE;
}} }
if(valid==TRUE && EmptyStack(s)){
printf("TRUE");
}
else{
printf("FALSE");
}
return 0;
}
