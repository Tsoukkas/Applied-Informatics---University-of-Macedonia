#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int amka;
    int afm;
    int age;
} BinTreeElementType;                   /*� ����� ��� ��������� ��� ��� �����
                                        ����� struct */
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
/* ����������: ���������� ��� ���� ���.
   ����������:  ��� �������� ������(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* �������:   ��� ��� �� �� Root �� ������� ��� ���� ���.
  ����������: ������� �� �� ��� ����� ����.
  ����������: TRUE �� �� ��� ����� ���� ��� FALSE �����������
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* �������:     ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� �������� Item.
   ����������:  ������� �� �������� Item ��� ���.
   ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���
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
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���.
   ����������: � Found ���� ���� TRUE ��� � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE
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
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("(%d,%d,%d) ",Root->Data.amka,Root->Data.afm,Root->Data.age);        //(62, 62, 62) (65, 65, 65) (70, 70, 70)
        InorderTraversal(Root->RChild);
    }
}

