#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct employee{
	char ID[100];
//	char Full_Name[100];
//	char Department[100];
	int Salary;
//	int day;
//	int month;
//	int year;
}Employee;

struct List_Emp;
//typedef struct List_Emp node;

struct List_Emp
{
	Employee Emp;
	struct List_Emp *next; //dung de link, day la cau truc tu tro
};

typedef struct List_Emp node;; // not goc cua list

void init(node **A){
	*A = NULL;
}

// kiem tra co rong hay khong
bool isNULL(node **A)
{
	return A == NULL;
}

// kiem tra do dai cua danh sach
int Length (node *A)
{
	if (A == NULL)
		return 0;
	int len = 0; 
	while ( A != NULL )
	{
		len++;
		A = A->next;
	}
	return len;
}

 //nhap thonh tin moi 
node *createNode()
{
	node *emp = (node*)malloc(sizeof(node) );
//	printf("\nNhap ten nhan vien : ");
//	fflush(stdin);
//	gets( (*emp).Emp.Full_Name );
	
	printf("Nhap ID nhan vien :  ");
	fflush(stdin);
	gets( emp->Emp.ID );
	
//	printf("Nhap don vi : ");
//	gets( (*emp).Emp.Department );
	
	printf("Nhap luong : ");
	scanf("%d",&(emp->Emp.Salary));
	
//	printf("Nhap ngay thang nam vao cong ty ");
//	scanf("%d %d %d ", &(*emp).Emp.day, &(*emp).Emp.month, &(*emp).Emp.year);
	
	return emp;
}

void Insert_Frist(node **A, node *P){
	if (*A == NULL)
	{
		*A = P;
		return;
	}
	
	P->next = *A;
	*A = P;
	
}

// nhap danh sach nhan vien
void Input(node **A)
{
	int num;
	printf("Nhap so luong nhan vien : ");
	
	do{
		scanf("%d",&num);
		if(num < 1 || num > 50)
		{
			printf("\nban da nhap sai so luong");
			printf("\nHay nhap lai : ");
		}
	}while(num <0 || num > 50);
	
	int i;
	for(i = 0 ; i<num ; i++)
	{
		node *new = createNode();
		Insert_Frist(A, new);
	}
}

void Output( node *A )
{
	while(A != NULL)
	{
		printf("\nID         :  %s",A->Emp.ID);
//		printf("\nName       :  %s",A->Emp.Full_Name);
//		printf("\nDepartment :  %s",A->Emp.Department);
		printf("\nSalary     :  %d",A->Emp.Salary);
//		printf("\nStart Day    : %d/%d/%d",A->Emp.day, A->Emp.month, A->Emp.year);
		printf("\n");
		A = A->next;
	}
}



//sap xep 
void sapxep(node **A)
{
	node *i;
	//i = *A;
	for ( i = *A ; i != NULL; i->next)
	{
		node *minSalary = i;
		node *j;
		for (j = i->next ; j != NULL ; j = j->next)
		{
			node *temp;
			if(j->Emp.Salary < minSalary->Emp.Salary)
			{
				minSalary->Emp = j->Emp;
			}
		}
		
		Employee temp = minSalary->Emp;
		minSalary->Emp = i->Emp;
		i->Emp = temp;
		
	}
}

int main()
{
	node *A;
	init(&A);
	Input(&A);
	printf("\n----------------\n");
	
	
	sapxep( &A );
	printf("\n---- sap xep thuc hien thanh cong--- \n");
	//
	Output(A);
	
	
	
}

























