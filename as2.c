#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX  50

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

    printf("Input join month         : ");
    scanf("%d",&pEmp->Emp_t.month);

    printf("Input join year          : ");
    scanf("%d",&pEmp->Emp_t.year);

    return pEmp;
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
        if (num < 1 || num > MAX)
        {
            printf("\nWrong input !!");
            printf("\nLet's input again  : ");
        }
    }
    while ( (num < 1) || (num > MAX) );

    for ( element = 0 ; element < num ; element++ )
    {
        node *p_new = createNode();
        Insert(pp_head, p_new);
        //free(p_new);
    }

}

void Output (node *p_head)
{
    while (p_head != NULL)
    {
        printf("\nID            : %d",p_head->Emp_t.ID);
        printf("\nName          : ");
        puts(p_head->Emp_t.Full_Name);
        printf("Department      : ");
        puts(p_head->Emp_t.Department);
        printf("Salary        : %d",p_head->Emp_t.Salary);
        printf("\nStart         : %d/%d/%d", p_head->Emp_t.day, p_head->Emp_t.month, p_head->Emp_t.year);
        printf("\n");
        p_head = p_head->p_next;
    }
    
}

// ascending salary
void ascending(node **pp_head)
{
    node *p_current = NULL;
    node *p_index = NULL;
    int temp = 0;
    if (*pp_head = NULL)
    {
        printf("Empty List\n");
        return;
    }
    else
    {
        p_current = *pp_head;
        while (p_current != NULL)
        {
            p_index = p_current->p_next;
            while(p_index != NULL)
            {
                if(p_current->Emp_t.Salary > p_index->Emp_t.Salary)
                {
                    temp = p_current->Emp_t.Salary;
                    p_current->Emp_t.Salary = p_index->Emp_t.Salary;
                    p_index->Emp_t.Salary = temp;
                }

                p_index = p_index->p_next;
            }

            p_current = p_current->p_next;
        }
    }
}

// descending salary
void descending (node **pp_head)
{
    node *p_current = NULL;
    node *p_index = NULL;
    int temp = 0;
    if (*pp_head = NULL)
    {
        printf("Empty List\n");
        return;
    }
    else
    {
        p_current = *pp_head;
        while (p_current != NULL)
        {
            p_index = p_current->p_next;
            while(p_index != NULL)
            {
                if(p_current->Emp_t.Salary < p_index->Emp_t.Salary)
                {
                    temp = p_current->Emp_t.Salary;
                    p_current->Emp_t.Salary = p_index->Emp_t.Salary;
                    p_index->Emp_t.Salary = temp;
                }

                p_index = p_index->p_next;
            }

            p_current = p_current->p_next;
        }
    }
}


void softName(node **pp_head)
{
    node *p_current = NULL;
    node *p_index = NULL;
    char temp[50];
    int compare = 0;
    if (*pp_head = NULL)
    {
        printf("Empty List\n");
        return;
    }

    else
    {
        p_current = *pp_head;
        while (p_current != NULL)
        {
            p_index = p_current->p_next;
            while(p_index != NULL)
            {
                int compare = 0;
                compare = strcmp( p_current->Emp_t.Full_Name , p_index->Emp_t.Full_Name );
                if ( compare == 1 )
                {
                    strcpy ( temp , p_current->Emp_t.Full_Name );
                    strcpy ( p_current->Emp_t.Full_Name , p_index->Emp_t.Full_Name );
                    strcpy ( p_index->Emp_t.Full_Name , temp );
                }
            } 

            p_current = p_current->p_next;
        }
    }
}

// mode of soft
void softMode(int *p_choice, node **p_head)
{
    while ( *p_choice == 0 || *p_choice == 1 || *p_choice == 2)
    {
        switch (*p_choice)
        {
            case 0: 
                // sap xep theo ten
                softName(p_head);
                break;
        
            case 1:
                // sap xe tang theo luong
                ascending(p_head);
                break;
            case 2:
                // sap xep giam theo luong
                descending (p_head);
                break;

            default:
                printf("wrong input - repeat your choice");
                break;
        }
    }
    
}

int main()
{
    int choice;
    node *p_head;
    init(&p_head);
    Input(&p_head);
    
    printf("\n--------------------------\n");
    printf("1 -- arrange ascending salary \n");
    printf("2 -- arrange descanding salary \n");
    printf("3 -- soft by Name \n");

    printf("\n Your choice :  ");
    scanf("%d" , &choice);
    
    softMode(&choice, &p_head) ;

    printf("\n----the List of employee----");

    Output(p_head);
    
    free(p_head);
    return 0;
}