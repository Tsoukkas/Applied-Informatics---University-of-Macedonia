#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int amka;
    int afm;
    int age;
} BinTreeElementType;                   /*ο τύπος των στοιχείων του ΔΔΑ είναι
                                        τύπου struct */
typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;

void Login(BinTreeElementType *UserRec,boolean *MoreUsers);
void BuildTree(FILE *UsersFile,BinTreePointer *UserTree, boolean *stop);
void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);

int main(){
BinTreePointer Root1,Root2,LockPtr;
BinTreeElementType Person;
boolean found;
char ch;

CreateBST(&Root1);
CreateBST(&Root2);

do{
    printf("Give AMKA?");
    scanf("%d",&Person.amka);
    printf("Give AFM?");
    scanf("%d",&Person.afm);
    printf("Give age?");
    scanf("%d",&Person.age);
    printf("\n");
if(Person.age<=60){
    BSTInsert(&Root1,Person); }
else{
    BSTInsert(&Root2,Person); }
printf("Continue Y/N:");
do{
    scanf("%c",&ch);
  }while(toupper(ch)!= 'N' && toupper(ch)!= 'Y');
}while(toupper(ch)!= 'N');

printf("People with age less-equal 60\n");
InorderTraversal(Root1);
printf("\n");
printf("People with age greater than 60\n");
InorderTraversal(Root2);
printf("\n");

for(int i=0;i<3;i++){
    printf("Give AMKA:");
    scanf("%d",&Person.amka);
    printf("Give age:");
    scanf("%d",&Person.age);
    if(Person.age<=60){
        BSTSearch(Root1,Person,&found,&LockPtr);
    }
    else{
        BSTSearch(Root2,Person,&found,&LockPtr);
    }
if(found)
{
    if(Person.age == LockPtr->Data.age)
        printf("The person with AMKA %d, AFM %d and age %d is the catalogue\n",LockPtr->Data.amka,LockPtr->Data.afm,LockPtr->Data.age);
    else
        printf("The person with AMKA %d has age %d different from the person you are looking for\n",LockPtr->Data.amka,LockPtr->Data.age);
}
else
{
    printf("The person with AMKA %d and age %d is Unknown\n",Person.amka,Person.age);
}

}
return 0;
}





void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item.amka < LocPtr ->Data.amka)
            LocPtr = LocPtr ->LChild;
        else if (Item.amka > LocPtr ->Data.amka)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %d EINAI HDH STO DDA\n", Item.age);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
 //       LocPtr ->Data = Item;
        LocPtr ->Data.amka = Item.amka;
       LocPtr->Data.afm =Item.afm;
       LocPtr->Data.age =Item.age;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item.amka < Parent ->Data.amka)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{
    boolean stop;

    *LocPtr = Root;
    stop = FALSE;
    while (!stop && *LocPtr != NULL)
    {
        if (KeyValue.amka < (*LocPtr)->Data.amka)
            *LocPtr = (*LocPtr)->LChild;
        else
            if (KeyValue.amka > (*LocPtr)->Data.amka)
                *LocPtr = (*LocPtr)->RChild;
            else stop = TRUE;
    }
   *Found=stop;
}


void InorderTraversal(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("(%d,%d,%d) ",Root->Data.amka,Root->Data.afm,Root->Data.age);        //(62, 62, 62) (65, 65, 65) (70, 70, 70)
        InorderTraversal(Root->RChild);
    }
}

