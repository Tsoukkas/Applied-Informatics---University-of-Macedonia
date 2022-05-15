#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <string.h>

typedef struct{
int code;
int RecN;
} BinTreeElementType;

typedef struct{
int code;
char surname[20];
char name[20];
char sex;
int year;
float grade;
}StudentT1;             /*ο τύπος των στοιχείων του ΔΔΑ
                                                ενδεικτικά τύπου int */
typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);
 void printStudentsWithGrade(float theGrade);
int BuildBST(BinTreePointer *Root);
void writeNewStudents(BinTreePointer *Root, int *size);
void PrintStudent(int RecN);
int main(){

    BinTreePointer ARoot;
    BinTreeElementType LocPtr;
    BinTreeElementType c;
    int size;
    boolean found;
    float theGrade;

   //1
    printf("Q1. Build BST from a file\n");
    size=BuildBST(&ARoot);
   //2
    printf("Q2. Print size and BST\n");
    printf("Size=%d\n",size);
    printf("Nodes of BST\n");
    RecBSTInorder(ARoot);
    //3
    printf("\nQ3. Write new students, update file and BST\n");
    writeNewStudents(&ARoot,&size);
    //4
    printf("\nQ4. Print size and BST\n");
    printf("Size=%d\n",size);
    printf("Nodes of BST\n");
    RecBSTInorder(ARoot);
    //5
   printf("\nQ5. Search for a student\n");
    printf("Give student's code? ");
    scanf("%d",&c.code);
    RecBSTSearch(ARoot,c,&found,&LocPtr);
    if(found==TRUE)
    {
        PrintStudent(LocPtr.RecN);
    }
    else
    {
        printf("Student with this code was not found\n");
    }
    //6
    printf("\nQ6. Print size and BST\n");
    printf("Size=%d\n",size);
    printf("Nodes of BST\n");
    RecBSTInorder(ARoot);
    //7
    printf("\nQ7. Print students with grades >= given grade\n");
    printf("Give the grade:");
    scanf("%f",&theGrade);
    printStudentsWithGrade(theGrade);
    return 0; }


int BuildBST(BinTreePointer *Root){
    FILE *F1;
    int nscan;
    char termch;
    int size;
    StudentT1 student;
    BinTreeElementType indexRec;
    F1=fopen("foitites.dat","r");
    size=0;
    CreateBST(&(*Root));
    if(F1 != NULL){
        while(1){
            nscan=fscanf(F1, "%d,%20[^,],%20[^,],%c,%d,%f%c",&student.code,&student.name,&student.surname,&student.sex,&student.year,&student.grade,&termch);
           if (nscan == EOF) { break; }

           if (nscan !=7 || termch != '\n')
           {
               printf("Improper file format");
               exit(1);}
            else{
                indexRec.code=student.code;
                indexRec.RecN=size;
                RecBSTInsert(&(*Root),indexRec);
                size++;
            }
        }

    }
fclose(F1);
        return size;
}
void PrintStudent(int RecN)
{
    FILE *fp;
    int nscan;
    char termch;
    StudentT1 student;
    int lines;

    fp=fopen("foitites.dat","r");
    lines=0;
    if (fp!=NULL)
    {
      while(lines<=RecN)
      {
           nscan=fscanf(fp, "%d,%20[^,],%20[^,],%c,%d,%f%c",&student.code,student.name,student.surname,&student.sex,&student.year,&student.grade,&termch);
           if (nscan == EOF) break;

           if (nscan !=7 || termch != '\n')
           {
               printf("Improper file format");
               exit(1);
           }
           lines++;
      }
      if(lines==RecN+1)
          printf("%d,%s,%s,%c,%d,%.1f\n",student.code,student.name,student.surname,student.sex,student.year,student.grade);
    }
    fclose(fp);
}

 void printStudentsWithGrade(float theGrade)
 {
     FILE *fp;
     int nscan;
     char termch;
     StudentT1 student;

     fp=fopen("foitites.dat","r");
     if (fp!=NULL)
     {
       while(TRUE)
       {
           nscan=fscanf(fp, "%d,%20[^,],%20[^,],%c,%d,%f%c",&student.code,&student.name,&student.surname,&student.sex,&student.year,&student.grade,&termch);
           if (nscan == EOF) break;
           if (nscan !=7 || termch != '\n')
           {
               printf("Improper file format");
               exit(1);
           }
           else
           {
               if(student.grade>=theGrade)
                    printf("%d,%s,%s,%c,%d,%.1f\n",student.code,student.name,student.surname,student.sex,student.year,student.grade);
           }
       }
     fclose(fp);
    }
 }


void writeNewStudents(BinTreePointer *Root, int *size){
FILE *F1;
StudentT1 student;
BinTreeElementType indexRec;
boolean found;
char c;
BinTreePointer LocPtr;
F1=fopen("foitites.dat","a");
if(F1 != NULL){
do{
    //2, DIMITRIS, DIMITRIOU, M, 2020, 5.0
    printf("Give student's AM?");
    scanf("%d",&student.code);
    indexRec.code=student.code;
    RecBSTSearch(Root,indexRec,&found,&LocPtr);  //void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
    if(found==FALSE){


    printf("Give student name?");
    scanf("%s",&student.name);

    printf("Give student surname?");
    scanf("%s",&student.surname);

    printf("Give student sex F/M?");
    scanf(" %c",&student.sex);

    printf("Give student's registration year?");
    scanf("%d",&student.year);

    printf("Give student's grade?");
    scanf("%d",&student.grade);
    fprintf(F1,"%d,%s,%s,%c,%d,%f",student.code,student.name,student.surname,student.sex,student.year,student.grade);
    indexRec.RecN=*size;
    RecBSTInsert(Root,indexRec);
    (*size)++;
    }
    else{
        printf("%d",student.code);
    }
    printf("Continue Y/N:");
    do{
        scanf(" %c",&c);getchar();
    }while(toupper(c)!= 'N' && toupper(c)!= 'Y');
}while(toupper(c)!= 'N');

fclose(F1);
}
}

void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item.code < (*Root)->Data.code)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item.code > (*Root)->Data.code)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{
    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (KeyValue.code < Root->Data.code)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (KeyValue.code > Root->Data.code)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}

void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* Δέχεται:  Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Προσπαθεί να βρει έναν κόμβο στο ΔΔΑ που να περιέχει την τιμή
                KeyValue στο πεδίο κλειδί του τμήματος δεδομένων του και,
                αν τον βρει, τον διαγράφει από το ΔΔΑ.
  Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του.
*/
{

   BinTreePointer TempPtr;          //* true AN TO STOIXEIO KeyValue EINAI STOIXEIO TOY DDA *)

    if (BSTEmpty(*Root))          //* ΑΔΕΙΟ ΔΕΝΔΡΟ ΤΟ KeyValue ΔΕ ΘΑ ΒΡΕΘΕΙ *)
        printf("TO STOIXEIO DEN BRE8HKE STO DDA\n");
     else
         //* αναζήτησε αναδρομικά τον κόμβο που περιέχει την τιμή KeyValue και διάγραψέ τον
          if (KeyValue.code < (*Root)->Data.code)
             RecBSTDelete(&((*Root)->LChild), KeyValue);       //* ΑΡΙΣΤΕΡΟ ΥΠΟΔΕΝΔΡΟ *
          else
            if (KeyValue.code > (*Root)->Data.code)
                  RecBSTDelete(&((*Root)->RChild), KeyValue);   //* ΔΕΞΙ  ΥΠΟΔΕΝΔΡΟ *
            else                                       //* TO KeyValue ΒΡΕΘΗΚΕ ΔΙΑΓΡΑΦΗ ΤΟΥ ΚΟΜΒΟΥ *)
                if ((*Root)->LChild ==NULL)
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;      //* ΔΕΝ ΕΧΕΙ ΑΡΙΣΤΕΡΟ ΠΑΙΔΙ *)
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL)
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild;      //* ΕΧΕΙ ΑΡΙΣΤΕΡΟ ΠΑΙΔΙ, ΑΛΛΑ ΟΧΙ ΔΕΞΙ *)
                        free(TempPtr);
                   }
                   else                               //* ΕΧΕΙ 2 ΠΑΙΔΙΑ *)
                   {
                        //* ΕΥΡΕΣΗ ΤΟΥ INORDER ΑΠΟΓΟΝΟΥ ΤΟΥ *)
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL)
                              TempPtr = TempPtr->LChild;
                        /* ΜΕΤΑΚΙΝΗΣΗ ΤΟΥ ΑΠΟΓΟΝΟΥ ΤΗς ΡΙΖΑΣ ΤΟΥ ΥΠΟΔΕΝΔΡΟΥ
                        ΠΟΥ ΕΞΕΤΑΖΕΤΑΙ ΚΑΙ ΔΙΑΓΡΑΦΗ ΤΟΥ ΑΠΟΓΟΝΟΥ ΚΟΜΒΟΥ */
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTInorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
    //    printf("L");
        RecBSTInorder(Root->LChild);
        printf("(%d,%d)",Root->Data.code,Root->Data.RecN);
    //    printf("R");
        RecBSTInorder(Root->RChild);
    }
   // printf("U");
}

void RecBSTPreorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί προδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        printf("%d ",Root->Data);
       // printf("L");
        RecBSTPreorder(Root->LChild);
      //  printf("R");
        RecBSTPreorder(Root->RChild);
    }
   // printf("U");
}

void RecBSTPostorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί μεταδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
      //  printf("L");
        RecBSTPostorder(Root->LChild);
     //   printf("R");
        RecBSTPostorder(Root->RChild);
        printf("%d ",Root->Data);
    }
   // printf("U");
}
