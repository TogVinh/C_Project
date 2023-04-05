#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct Infomation_t
{
	int ID;
	char Full_Name[50];
	char Department[50];
	int Salary;
	int day;
	int month;
	int year;
}Info_t;

struct list_Emp_t
{
    Info_t Emp_t;
    struct list_Emp_t *p_next;
};
typedef struct list_Emp_t node;

void init (node  **pp_head)
{
    *pp_head = NULL;
}

bool isNull (node **pp_head)
{
    return pp_head == NULL;
}

node *createNode()
{
    node *pEmp = (node*)malloc(sizeof(node));
    printf("\nInput Employee's Name  : ");
    fgets(pEmp->Emp_t.Full_Name, 50, stdin);
    fgets(pEmp->Emp_t.Full_Name, 50, stdin);

    printf("Input ID of Employee     : ");
    scanf("%d",&pEmp->Emp_t.ID);

    printf("Input Department         : ");
    fgets(pEmp->Emp_t.Department,50, stdin);
    fgets(pEmp->Emp_t.Department,50, stdin);

    printf("Input Salary             : ");
    scanf("%d",&pEmp->Emp_t.Salary);

    printf("Input join day           : ");
    scanf("%d",&pEmp->Emp_t.day);

    printf("Input join month           : ");
    scanf("%d",&pEmp->Emp_t.month);

    printf("Input join year           : ");
    scanf("%d",&pEmp->Emp_t.year);
}

void Insert ( node **pp_head, node *p_new )
{
    if (*pp_head == NULL)
    {
        *pp_head = p_new;
        return;
    }

    p_new->p_next = *pp_head;
    *pp_head = p_new;
}


// nhap danh sach nhan vien
void Input(node **pp_head)
{
    int num = 0;
    int element = 0; //loop varibale -- the element of Linked List
    printf("Input the number of Employee : ");

    do
    {
        scanf("%d", &num);
        if (num < 1 || num > 50);
        {
            printf("\nWrong input !!");
            printf("Let's input again  : ");
        }
    }
    while ( num < 0 || num > 50 );

    for ( element = 0 ; element < num ; element++ )
    {
        node *p_new = createNode();
        Insert(pp_head, p_new);
    }

}
