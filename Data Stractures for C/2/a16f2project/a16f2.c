#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define StackLimit 200   // �� ���� �������� ��� �������, ���������� ��� �� 50


typedef struct{
int price;
char size;
}StackElementType;   // � ����� ��� ���������  ��� �������
                                //���������� ����� int
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack)
/* ����������: ���������� ��� ���� ������.
   ����������: ���� ������.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ����.
   ����������: True �� � Stack ����� ����, False �����������
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ������.
   ����������: True �� � Stack ����� ������, False �����������
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* �������: ��� ������ Stack ��� ��� �������� Item.
   ����������: ������� �� �������� Item ���� ������ Stack �� � Stack ��� ����� ������.
   ����������: ��� ������������� Stack.
   ������: ������ ������� �������, �� � ������ Stack ����� ������
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* �������: ��� ������ Stack.
   ����������: ��������� �� �������� Item ��� ��� ������ ��� ������� �� � ������ ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� Stack.
   ������:  ������ ����� ������� �� � Stack ����� ����
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
        printf("%c, %d\n",Stack.Element[i].size,Stack.Element[i].price);
    }
    printf("\n");
}


int main(){
int n,i=1;
boolean found;
char size1;
StackType itemsStack,tempsStack;   //again without size of array....   //dilosi stivas
CreateStack(&itemsStack);
CreateStack(&tempsStack);          //dimiurgia stivas
printf("Give number of items ");
scanf("%d",&n);           //dini posa pragmata tha exi to katastima
printf("Give the items to store\n");
StackElementType AnItem;          //den vazo megethos etsi oste oti vgali na to vazi apefthias,epd ine tipu stack element type den xani kati epd exi stin usia thesis..eso tus
while(i<=n){
  printf("Give price ");
  scanf("%d",&AnItem.price);
  printf("Give size ");
  scanf(" %c",&AnItem.size);
   Push(&itemsStack,AnItem);    //meta tin kataxorisi ta vazi stin stiva
  i++;
}               //  kataxori tis times tus kai ta size tus
printf("Items in the box");
TraverseStack(itemsStack);
printf("What size do you want? ");
scanf(" %c",&size1);
found=FALSE;                    //parusiazi ta pragmata kai rota ti size theli o pelatis
while(!EmptyStack(itemsStack)) {
     Pop(&itemsStack,&AnItem);
    if(AnItem.size==size1){
    found=TRUE;
    break;
    }
else{
        Push(&tempsStack,AnItem); //an den ine iso to vazi stin ali stiva kai pai sto epomeno
}
i--;
}                //oso den ine adia i stiva vgazi ena ena ta items kai elexi an iparxi to size tu pelati an iparxi aferi afto to anitkimeno
if(found==FALSE){
    printf("Not Found the size %c\n",size1);
}
else if (found==TRUE){
    printf("Found the size %c\n",size1);
}                                       //lei an to vrike i oxi
printf("\n");
printf("Items in the box");
TraverseStack(itemsStack);
printf("\n");
printf("Items out of the box");
TraverseStack(tempsStack);
while(!EmptyStack(tempsStack)){
    Pop(&tempsStack,&AnItem);
    Push(&itemsStack,AnItem);
}
printf("Items in the box");
TraverseStack(itemsStack);
printf("\n");
printf("Items out of the box");
TraverseStack(tempsStack);
return 0;
}
