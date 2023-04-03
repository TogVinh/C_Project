#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Information
{
	int ID;
	char Full_Name[100];
	char Department[100];
	int Salary;
	int day;
	int month;
	int year;
} Info;

// typedef struct List_Emp node;

struct List_Emp
{
	Info Emp;
	struct List_Emp *next; // dung de link, day la cau truc tu tro
};

typedef struct List_Emp node; // not goc cua list

// node g_head_list;

void init(node **head)
{
	*head = NULL;
}

// kiem tra co rong hay khong
bool isNULL(node **head)
{
	return head == NULL;
}

// kiem tra do dai cua danh sach
int Length(node *head)
{
	if (head == NULL)
		return 0;
	int len = 0;
	while (head != NULL)
	{
		len++;
		head = head->next;
	}
	return len;
}

// nhap thonh tin moi
node *createNode()
{
	node *emp = (node *)malloc(sizeof(node));
	printf("\nNhap ten nhan vien : ");
	fflush(stdin);
	fgets( (*emp).Emp.Full_Name, sizeof(emp->Emp.Full_Name), stdin );

	printf("Nhap ID nhan vien :  ");
	scanf("%d", &emp->Emp.ID);

	//printf("Nhap don vi : ");
	//	gets( (*emp).Emp.Department );
	fgets( (*emp).Emp.Department, sizeof(emp->Emp.Department), stdin );

	printf("Nhap luong : ");
	scanf("%d", &emp->Emp.Salary);

	// printf("Nhap ngay thang nam vao cong ty ");
	// scanf("%d %d %d ", &(*emp).Emp.day, &(*emp).Emp.month, &(*emp).Emp.year);

	return emp;
}

void Insert_Frist(node **head, node *new)
{
	if (*head == NULL)
	{
		*head = new;
		return;
	}

	new->next = *head;
	*head = new;
}

// nhap danh sach nhan vien
void Input(node **head)
{
	int num = 0; //The numbers of employee
	int i = 0;	 // loop variable

	printf("Nhap so luong nhan vien : ");

	do
	{
		scanf("%d", &num);
		if (num < 1 || num > 50)
		{
			printf("\nban da nhap sai so luong");
			printf("\nHay nhap lai : ");
		}
	} while (num < 0 || num > 50);

	for (i = 0; i < num; i++)
	{
		node *new = createNode();
		Insert_Frist(head, new);
	}
}

void Output(node *head)
{
	while (head != NULL)
	{
		printf("\nID         :  %d", head->Emp.ID);
		printf("\nName       :  %s",head->Emp.Full_Name);
		printf("\nDepartment :  %s",head->Emp.Department);
		printf("\nSalary     :  %d", head->Emp.Salary);
		//printf("\nStart Day    : %d/%d/%d",A->Emp.day, A->Emp.month, A->Emp.year);
		printf("\n");
		head = head->next;
	}
}


void sapxep(node **head)

{
	node *current = NULL;
	node *index = NULL;
	int temp = 0;

	if (*head == NULL)
	{
		printf("empty list\n");
		return;
	}

	else
	{
		printf("NON-EMPTY list\n");
		current = *head;
		while (current != NULL)
		{
			// Node index will point to node next to current
			index = current->next;
			while (index != NULL)
			{
				// If current node's data is greater than index's node data, swap the data between them
				if (current->Emp.Salary > index->Emp.Salary)
				{
					temp = current->Emp.Salary;
					current->Emp.Salary = index->Emp.Salary;
					index->Emp.Salary = temp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}

	printf("finish sorting\n");
}

int main()
{
	node *head;
	init(&head);
	Input(&head);
	printf("\n----------------\n");

	sapxep(&head);

	printf("\n---- sap xep thuc hien thanh cong--- \n");
	//
	Output(head);

	free(head);

	return 0;
}
