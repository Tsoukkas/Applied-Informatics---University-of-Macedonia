#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 10    /*όριο μεγέθους της συνδεδεμένης λίστας,
                            ενδεικτικά τέθηκε ίσο με 50*/
#define NilValue -1          // ειδική μεδενικη τιμη δείχνει το τέλος της Συνδ.λίστας

typedef int ListElementType; /*τύπος δεδομένων για τα στοιχεία της συνδεδεμένης λίστας,
                                ενδεικτικά επιλέχθηκε ο τύπος int */
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;


void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr που δείχνει στον
                πρώτο διαθέσιμο κόμβο.
  Λειτουργία: Αρχικοποιεί τον πίνακα Node ως συνδεδεμένη λίστα συνδέοντας μεταξύ
                τους διαδοχικές εγγραφές του πίνακα,
                και αρχικοποιεί τον δείκτη FreePtr .
  Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον
                δείκτη FreePtr του πρώτου διαθέσιμου κόμβου
*/
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=-1;    /* δεν είναι αναγκαίο η απόδοση αρχικής τιμής στο πεδίο των δεδομένων, βοηθάει στην εκτύπωση */
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=-1;
    *FreePtr=0;
}

void CreateList(ListPointer *List)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη λίστα.
   Επιστρέφει: Έναν (μηδενικό) δείκτη που δείχνει σε κενή λίστα
*/
{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
/* Δέχεται:    Έναν δείκτη List που δείχνει σε μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
   Επιστρέφει: True αν η συνδεδεμένη λίστα είναι κενή και false διαφορετικά
*/
{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι γεμάτη.
   Επιστρέφει: True αν η συνδεδεμένηλίστα είναι γεμάτη, false διαφορετικά
*/
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr.
  Λειτουργία: Αποκτά έναν "ελεύθερο" κόμβο που τον δείχνει ο δείκτης P.
  Επιστρέφει: Τον δείκτη P και τον τροποποιημένο  δείκτη FreePtr
                που δεικτοδοτεί στο πρώτο διαθέσιμο κόμβο
*/
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* Δέχεται:    Τον πίνακα Node, που αναπαριστά τη δεξαμενή των διαθέσιμων κόμβων,
                έναν δείκτη TempPtr και τον δείκτη FreePtr.
   Λειτουργία: Επιστρέφει στη δεξαμενή τον κόμβο στον οποίο δείχνει ο TempPtr.
   Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον δείκτη FreePtr
*/
{
  Node[P].Next =*FreePtr;
  Node[P].Data = -1; /* Οχι αναγκαία εντολή, βοηθητική για να φαίνονται στην
                        εκτύπωση οι διαγραμμένοι κόμβοι */
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* Δέχεται:    Μια συνδεδεμένη λίστα, τον πίνακα Node, τον δείκτη PredPtr και
                ένα στοιχείο Item.
  Λειτουργία: Εισάγει στη συνδεδεμένη λίστα, αν δεν είναι γεμάτη, το στοιχείο
                Item μετά από τον κόμβο στον οποίο δείχνει ο δείκτης PredPtr.
  Επιστρέφει: Την τροποποιημένη συνδεδεμένη λίστα, τον τροποποιημένο πίνακα Node
                και τον δείκτη FreePtr.
  Εξοδος:     Μήνυμα γεμάτης λίστας, αν η συνδεδεμένη λίστα είναι γεμάτη
*/
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
/* Δέχεται:   Μια συνδεδεμένη λίστα και τον δείκτη PredPtr που δείχνει
                στον προηγούμενο κόμβο από αυτόν που θα διαγραφεί.
  Λειτουργία: Διαγράφει από τη συνδεδεμένη λίστα, αν δεν είναι κενή,
                τον προηγούμενο κόμβο από αυτόν στον οποίο δείχνει ο PredPtr.
  Επιστρέφει: Την τροποποιημένη λίστα και το δείκτη FreePtr.
  Έξοδος:     Μήνυμα κενής λίστας, αν η συνδεδεμένη λίστα είναι κενή
*/
{
  ListPointer TempPtr ;

  if (!EmptyList(*List))
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
      }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Κάνει διάσχιση της συνδεδεμένης λίστας, αν δεν είναι κενή.
   Έξοδος:     Εξαρτάται από την επεξεργασία
*/
{
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d: %d->%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}
boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item,
ListPointer *PredPtr){
    {
// Δηλώνω τις μεταβλητές
boolean stop; //για τον τερματισμό της διάσχισης της List αν το στοιχείο δεν
//υπάρχει
boolean found;
  ListPointer current;
//Αρχικοποίηση stop και found
found=FALSE;
stop=FALSE;
//Αρχικοποίηση του αριθμοδείκτη *PredPtr να δείχνει το προηγούμενο του 1ο
//κόμβου της λίστας //το ίδιο και όταν η λίστα είναι κενή
 *PredPtr = NilValue;
//Αν η List δεν είναι κενή
if(!EmptyList(List))
 {
 //Αρχικοποίηση του αριθμοδείκτη current να δείχνει το 1ο κόμβο της λίστας
  current = List;   //mpeni stin arxi tis listas gia na arxisi na psaxni
 while(current!=-1 && !stop) {
 if(Node[current].Data>=Item) {
//το Item ή βρέθηκε ή δεν υπάρχει στη List
stop=TRUE;
// found TRUE ή FALSE αν βρέθηκε ή όχι
 found=TRUE;
 }
 else{
 // Ενημέρωσε τους αριθμοδείκτες *PredPtr & current
 //Ο *PredPtr να δείχνει το μέχρι τώρα τρέχοντα κόμβο της λίστας
//o current να δείχνει τον επόμενο κόμβο της λίστας
*PredPtr = current;
 current = Node[current].Next;  //metavenume ston epomeno
 }
 }
 }
 else{ //το στοιχείο δεν βρέθηκε
found=FALSE;}
return found;
}


}
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d: %d->%d) ",i,Node[i].Data, Node[i].Next);
    printf("\n");
}



int main(){
boolean found;
char ch;
ListPointer AList;           //dilosi listas
NodeType Node[NumberOfNodes];
ListPointer FreePtr,PredPtr;       //dixtes p dixnun to diathesimo stixio kai to proigumeno stixio
ListElementType AnItem;   //to item p vazo kai vgazw apo tin oura
InitializeStoragePool(Node, &FreePtr);      //dimiurgi afto pou lei posus diathesimus komvus iparxun
CreateList(&AList);      //dimiurgia listas
printf("---------------Question C--------------------\n");
printf("--------------Storage pool------------------\n");
printAll(AList, FreePtr, Node);    //emfanizi tus diathesimus komvus
printf("---------------Question D--------------------\n");
printf("--------------Linked list--------------------\n");
TraverseLinked(AList,Node);        //emfanizi tin lista
printf("---------------Question E--------------------\n");
do
{
printf("Give us a number:");
scanf("%d", &AnItem);

found=Search(FreePtr,AList,Node,AnItem,&PredPtr); //elexi an iparxi o arithmos stin lista
Insert(&AList, Node,&FreePtr, PredPtr, AnItem);   //isagi ton arithmo stin lista

printf("\nContinue Y/N: ");


do
{
scanf(" %c", &ch);
} while (toupper(ch)!= 'N'  && toupper(ch) != 'Y');
} while (toupper(ch)!='N');
printf("---------------Question F--------------------\n");
printf("--------------Storage pool------------------\n");
printAll(AList, FreePtr, Node);
printf("---------------Question G--------------------\n");
printf("--------------Linked list--------------------\n");
TraverseLinked(AList,Node);
printf("---------------Question H--------------------\n");
if(EmptyList(AList)){
    printf("Empty List\n");
}
else{
    printf("Not an Empty List");
}
printf("\n---------------Question I--------------------\n");
if(FullList(AList)){
    printf("Full List");
}
else{
    printf("Not a Full List");
}
printf("\n---------------Question J--------------------\n");
printf("-----------------Search for a number-----------------\n");
while(1){
printf("Give a number ");
scanf("%d",&AnItem);
found=Search(FreePtr,AList,Node,AnItem,&PredPtr);
if(found==TRUE){
printf("The number is in the list and its predecessor is in position %d\n",PredPtr);
}
else{
    printf("The number is not in the list");
    break;
} }
return 0;
}
