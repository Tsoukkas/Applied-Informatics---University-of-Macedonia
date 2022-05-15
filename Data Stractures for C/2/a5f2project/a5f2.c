#include <stdio.h>
#include <stdlib.h>
#define StackLimit 50

typedef int StackElementType;   // ο τύπος των στοιχείων  της στοίβας
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

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}


int main(){
StackElementType x,i,n,temp;   //dilosi stixion stivas
StackType AStack,AStack1;  //ksana den vazume thesis   //dilosi stivvn
CreateStack(&AStack);  //dimiurgia stivas
for(i=0;i<150;i+=10){
    Push(&AStack,i);  //kataxorisi stixion stivas
}
TraverseStack(AStack);    //emfanisi stixiwn
printf("Give nth element (n<=6) ");
scanf("%d",&n);
printf("\n");    //dinoume ena arithmo
Pop(&AStack,&x);
Pop(&AStack,&x);
printf("Question a: x=%d ",x);  //exei tin timi tu telefteu arithmu p kaname pop
TraverseStack(AStack);
printf("\n");                   //a
Pop(&AStack,&temp);
Pop(&AStack,&x);
Push(&AStack,x);
Push(&AStack,temp);
printf("Question b: x=%d ",x);
TraverseStack(AStack);
printf("\n");        //b
for(i=1;i<=n;i++){
Pop(&AStack,&x);
}
printf("Question c: x=%d ",x);
TraverseStack(AStack);
printf("\n");       //c
CreateStack(&AStack1);
for(i=1;i<=n;i++){
    Pop(&AStack,&x);
    Push(&AStack1,x);
}
printf("Question d: x=%d ",x);
while((!EmptyStack(AStack1))){
    Pop(&AStack1,&temp);
    Push(&AStack,temp);
}
TraverseStack(AStack);
printf("\n");      //d
while(!EmptyStack(AStack)){
    Pop(&AStack,&x);
    Push(&AStack1,x);
}
printf("Question e: x=%d ",x);
while(!EmptyStack(AStack1)){
    Pop(&AStack1,&x);
    Push(&AStack,x);
}
TraverseStack(AStack);
printf("\n");    //e
while(x != AStack.Element[2]){
    Pop(&AStack,&x);
    Push(&AStack1,x);
}
printf("Question f: x=%d ",x);
while(!EmptyStack(AStack1)){
    Pop(&AStack1,&x);
    Push(&AStack,x);
 }
TraverseStack(AStack);
printf("\n");    //f
while(!EmptyStack(AStack)){
    Pop(&AStack,&x);
}
printf("Question g: x=%d ",x);
TraverseStack(AStack);
return 0;

}
