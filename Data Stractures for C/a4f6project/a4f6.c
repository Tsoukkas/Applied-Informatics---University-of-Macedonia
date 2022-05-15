#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define HMax 9              /*     �� ������� ��� ������ HashTable
                                ���������� ��� �� 5 */
#define VMax 30             /*�� ������� ��� ������,
                                ���������� ��� �� 30 */
#define EndOfList -1        /* ������ ��� ����������� �� ����� ��� ������
                                ��� ��� ���� ��������� ��������� */

typedef struct{
char phone[10];
int type;
} ListElementType;  /*����� ��������� ��� �� �������� ��� ������
                               * ���������� ����� int */
typedef char KeyType[32];

typedef struct {
	KeyType RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // ������� ������� ���� ��� ��������� ���������
    int Size;                // ������ �������� ��� ������ List
	int SubListPtr;          // D������� �� ��� �������� ���������
    int StackPtr;           // ������� ���� ��� ����� �������� ���� ��� ������ List
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

void Print_HashList(HashListType HList);
void PrintPinakes(HashListType HList);
void CreateHashList(HashListType *HList);
int HashKey(KeyType Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);
void BuildHashList(HashListType *HList);
void Search_HashList_By_Subject(HashListType HList,int code);
int findAverage(KeyType s);

int main()
{

   char ch;
   HashListType HList;
   ListElm AnItem;
   KeyType AKey;
   int Loc, Pred;
   char surname[20];
   int code;

   //1
   printf("1.Create HashList\n");
   BuildHashList(&HList);
   PrintPinakes(HList);

   //2
   printf("2.Insert new teacher\n");
    do
            {
   	            printf("Enter teacher's name:");
                scanf("%s", &AnItem.RecKey);
                printf("Enter teacher's surname:");
                scanf("%s", &surname);
                strcat(AnItem.RecKey," ");
                strcat(AnItem.RecKey,surname);
                printf("Enter teacher's phone:");
                scanf("%d",&AnItem.Data.phone);
                printf("Enter teacher code:");
                scanf("%d",&AnItem.Data.type);
                AnItem.Link=EndOfList;
                AddRec(&HList, AnItem);
                printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');
            PrintPinakes(HList);

    //3
    printf("3. Delete a teacher\n");
    printf("Enter teacher's name:");
    scanf("%s",&AnItem.RecKey);
    printf("Enter teacher's surname:");
    scanf("%s",&surname);
    strcat(AnItem.RecKey," ");
    strcat(AnItem.RecKey,surname);
    DeleteRec(&HList,AnItem.RecKey);
    PrintPinakes(HList);

    //4
    printf("4. Search for a teacher\n");
    printf("Enter teacher's name:");
    scanf("%s",&AnItem.RecKey);
    printf("Enter teacher's surname:");
    scanf("%s", &surname);
    strcat(AnItem.RecKey," ");
    strcat(AnItem.RecKey,surname);
    SearchHashList(HList,AnItem.RecKey,&Loc,&Pred);
    if(Loc != -1){
        printf("[%s %s,%d,%d]\n",HList.List->RecKey,HList.List->Data.phone,HList.List->Data.type);
    }
    else{
        printf("Den iparxi\n");
    }

    //5
    printf("5. Search by subject\n");
    printf("Enter code:");
    scanf("%d",&code);
    Search_HashList_By_Subject(HList,code);

    return 0;
}
void BuildHashList(HashListType *HList)
{
    // ������ ��� ����������
    ListElm AnItem;
    FILE *FPs;
    char surname[20], termch;
    int nscan;

    CreateHashList(HList); // ���������� ���� ���������������

    FPs=fopen("i4f6.txt", "r"); // ������ �� ������ "i4f6.txt" ��� ��������

    if(FPs!=NULL){ // �� �� ������ ������ ��������
        while(TRUE){
            // ������� �� �������� ��� �������������
            nscan=fscanf(FPs, "%10[^,],%20[^,],%10[^,],%d%c", AnItem.RecKey,surname,AnItem.Data.phone,&AnItem.Data.type,&termch);
            if(nscan==EOF) // �� � �������� ������ ��� ����� ��� �������
                break; // ����� �� �����
            if(nscan!=5 || termch != '\n') // �� � �������� ��� �������� ��� ���� ��������
                printf("Error\n"); // ���� ��� ������ �����
            else{ // ������
                strcat(AnItem.RecKey, " ");
                strcat(AnItem.RecKey, surname); // ����������� �� ������ ���������������
                AddRec(HList, AnItem); // �������� ��� ������������ ��� ����
            }
        }
    }
    fclose(FPs); // ������ �� ������
}

void Search_HashList_By_Subject(HashListType HList, int code)
{
    int i, SubIndex;
    printf("List of teachers with subject code %d:",code);

    for (i=0;i<HMax;i++)
    {
        SubIndex=HList.HashTable[i];
        while (SubIndex != EndOfList)
        {
            if (HList.List[SubIndex].Data.type == code)
                printf("[%d:(%s %s,%d)]\n",SubIndex,HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.phone,HList.List[SubIndex].Data.type);
            SubIndex=HList.List[SubIndex].Link;
        }
    }
}

void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d, ",HList.HashTable[i]);

	printf("\nHash List\n");
    for (i=0;i<HList.Size;i++)
	   printf("%d) %s, %d\n",i,HList.List[i].RecKey,HList.List[i].Link);
	printf("\n");
}

void Print_HashList(HashListType HList)
{
   int i, SubIndex;

     printf("HASHLIST STRUCTURE with SYNONYM CHAINING\n");
     printf("========================================\n");

          printf("PINAKAS DEIKTWN STIS YPO-LISTES SYNWNYMWN EGGRAFWN:\n");
            for (i=0; i<HMax;i++)
              printf("%d| %d\n",i,HList.HashTable[i]);

          printf("OI YPO-LISTES TWN SYNWNYMWN EGGRAFWN:\n");
          for (i=0; i<HMax;i++)
          {
              SubIndex = HList.HashTable[i];
              while ( SubIndex != EndOfList )
              {
                   printf("[%d, %d, %d]",HList.List[SubIndex].RecKey,HList.List[SubIndex].Data,HList.List[SubIndex].Link);
                   printf(" -> ");
                   SubIndex = HList.List[SubIndex].Link;
               } //* while *)
              printf("TELOS % dHS YPO-LISTAS\n", i);
          }

          printf("H STOIBA TWN ELEY8ERWN 8ESEWN THS LISTAS:\n");
          SubIndex = HList.StackPtr;
          while ( SubIndex != EndOfList )
          {
                printf("%d <= ",SubIndex);
                SubIndex = HList.List[SubIndex].Link;
          }
          printf("TELOS\n");

          printf("MEGE8OS THS LISTAS = %d\n", HList.Size);
          printf("========================================\n");
}


int HashKey(KeyType Key)
/* �������:    ��� ���� Key ���� ��������.
   ����������: ������� ��� ���� ��������������� HValue ��� �� ������ Key.
   ����������: ��� ���� ��������������� HValue
*/
{
    int average;
     average=findAverage(Key);
	/*�� ��������� ��� �� KeyType ��� ����� ��������
	�� ������ �� ������������ ��������� �� ������ �� ������*/
	return average%HMax;
}

void CreateHashList(HashListType *HList)
/* ����������: ���������� ��� ���� HList.
   ����������: ��� ���� HList
*/
{
	int index;

	HList->Size=0;           //���������� ��� ���� �����
	HList->StackPtr=0;       //������� ��� ������ ��� ������� ��� ��������� ������

    /*����������� ��� ������ HashTable ��� ����� HList ���� ���� ��������� ���
        �� ���� �� ���� EndOfList (-1)*/
    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

     //���������� ��� ������� ��� ��������� ������ ��� ����� HList
    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;
}

boolean FullHashList(HashListType HList)
/* �������:    ��� ���� HList.
   ����������: ������� �� � ����� List ��� ����� HList ����� ������.
   ����������: TRUE �� � ����� List ����� ������, FALSE �����������.
*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (strcmp(HList.List[Next].RecKey,KeyArg)==0)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}

void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ��� ���� HList.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ���
                ������������ �������� ��� ��������� ���� ����� ������.
                �� ��� ������� ������� �� ������ KeyArg ���� Loc=Pred=-1
*/
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
/* �������:    ��� ���� HList ��� ��� ������� InRec.
   ����������: ������� ��� ������� InRec ��� ����� List, �� ��� ����� ������,
                ��� ���������� �� ���� HList.
   ����������: ��� ������������� ���� HList.
   ������:     ������ ������� ������, �� � List ����� ������, �����������,
                �� ������� ��� ������� �� �� ���� ������,
                �������� ����������� ���������
*/
{
	int Loc, Pred, New, HVal;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,KeyType DelKey)
/* DEXETAI:    TH DOMH (HList) KAI To KLEIDI (DelKey) THS EGGRAFHS
               POY PROKEITAI NA DIAGRAFEI
   LEITOYRGIA: DIAGRAFEI, THN EGGRAFH ME KLEIDI (DelKey) APO TH
               LISTA (List), AN YPARXEI ENHMERWNEI THN DOMH HList
   EPISTREFEI: THN TROPOPOIHMENH DOMH (HList)
   EJODOS:     "DEN YPARXEI EGGRAFH ME KLEIDI" MHNYMA
*/
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %s \n",DelKey);
	}
}

int findAverage(KeyType s)
{
    int first, last;

    first=toupper(s[0]);
    last=toupper(s[strlen(s)-1]);

    return ((first-64)+(last-64))/2;
}
