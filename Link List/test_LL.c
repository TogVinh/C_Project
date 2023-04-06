#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int data;
	struct node *next; // dung de link, day la cau truc tu tro
};

typedef struct node node;

node *makeNode(int x)
{
	node *newNode = (node *)malloc(sizeof(node));

	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}

void duyet(node *head)
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next; /* gan dia chi cura node tiep theo cho con tro head */
	}
}

// ham nay la ham truyen tham tri
// ham nay khong anh huong toi danh sach lien ket
// tuy ham la tham so con tro, nhung ban than tk head la mot con tro
// nen con tro va con tro la truyen tham tri
int count(node *head)
{
	int dem = 0;
	while (head != NULL)
	{
		dem++;
		head = head->next;
	}
	return dem;
}

/*them mot node vao dau danh sach
 * do ban than la mot con tro, thi de c� the thay doi thi
 * can truyen tham chieu nen can 1 con tro 2 sao
 */
void pushFront(node **head, int x) // day laf ham truyen tham tri
{
	// khoi tao node moi
	node *newNode = makeNode(x);
	// newnode dang tro toi Null va mang gia tri x

	// B1 : next cua newNode ->head
	newNode->next = *head; //*head laf dia chi node head

	// B2 cap nhap node head la node moi cura hang laf newNode
	*head = newNode;
}

/*them vao cuoi
void pushBack(node **head, int x)
{
	node *temp = *head;

	*chay toi node cuoi cung cua danh sach va dung o node cuoi
	* neu == NULL thi ket thuc duyet node da o sau node cuoi
	* nen de khac NULL, vi den NULL la dung
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	*chuyen next cua node head toi newNode
	node *newNode = makeNode(x);
	temp->next = newNode;
}/*code nay bi sai trong truong hop lisk list dang rong*/

void pushBack(node **head, int x)
{
	node *temp = *head;
	node *newNode = makeNode(x);

	if (*head == NULL)
	{
		*head = newNode;
		return;
		// neu khong return chuong trinh se tiep tuc
		// vay khi vao vong while chuong trinh se bi loi bo nho
		// do link list dang rong nen con tro head da o temp
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	// chuyen next cua node head toi newNode
	temp->next = newNode;
}

/*chen vao giua cua mot danh sach lien ket*/
void insert(node **head, int k, int x)
{
	int n = count(*head);
	int i;
	if (k < 1 || k > n + 1)
		return;

	if (k == 1)
	{
		pushFront(head, x);
		return;
	}
	node *temp = *head;

	for (i = 1; i <= k - 2; i++)
	{
		temp = temp->next;
	}

	// temp = k -1

	node *newNode = makeNode(x);
	newNode->next = temp->next;
	temp->next = newNode;
}

void popFront(node **head)
{
	node *temp = *head;

	if (*head == NULL)
		return; // k lam gi, thoat ham

	*head = (*head)->next; //*head->next == *(head->next) => sai
						   //(*head)->next => ddusng

	free(temp);
}

void popBack(node **head)
{
	// tim node thu 2 tu cuoi len
	if (*head == NULL)
		return;

	node *temp = *head;
	if (temp->next == NULL)
	{
		*head = NULL;
		free(temp);
		return;
	}
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	node *last = temp->next; // node cuoi -- temp->next dong nay la chi toi NULL => Last dang tro toi NULL
	temp->next = NULL;
	free(last);
}

void erase(node **head, int k)
{
	int n = count(*head);
	if (k < 1 || k > n)
		return;

	if (k == 1)
		popFront(head);

	else
	{
		node *temp = *head;
		int i;

		for (i = 1; i <= k - 2; i++)
		{
			temp = temp->next;
		} // temp da den vi tri k - 1 sau k -2 lan lap

		node *kth = temp->next;
		// cho node k-1 ket noi voi node k+1

		temp->next = kth->next;
		// da ket noi node k-1 voi node k+1

		free(kth);
	}
}

// sắp xếp danh sách liên kết
// chi thay doi data cac node, k thay doi vij tri cua node
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
				if (current->data > index->data)
				{
					temp = current->data;
					current->data = index->data;
					index->data = temp;
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
	node *head = NULL;
	int ch;
	int x;
	int k;
	while (1)
	{
		printf("\n----------------------------\n");
		printf("1. them vao dau\n");
		printf("2 them vao cuoi\n");
		printf("3. them vao giua\n");
		printf("4. xoa dau\n");
		printf("5. xoa cuoi\n");
		printf("6 xoa node o giua\n");
		printf("7 sap xep\n");
		printf("8 duyet\n");
		printf("0. exit\n");
		printf("----------------------------\n");
		printf("nhap lua chon : ");
		scanf("%d", &ch);

		if (ch == 1)
		{
			printf("nhap x = ");
			scanf("%d", &x);
			pushFront(&head, x);
		}
		else if (ch == 2)
		{
			printf("nhap x = ");
			scanf("%d", &x);
			pushBack(&head, x);
		}
		else if (ch == 3)
		{
			printf("nhap x = ");
			scanf("%d", &x);
			printf("nhap k = ");
			scanf("%d", &k);
			insert(&head, k, x);
		}
		else if (ch == 4)
		{
			popFront(&head);
		}
		else if (ch == 5)
		{
			popBack(&head);
		}
		else if (ch == 6)
		{
			int k;
			printf("nhap vi tri can xoa ");
			scanf("%d", &k);
			erase(&head, k);
		}
		else if (ch == 7)
		{
			sapxep(&head);
			printf("da sap xep \n");
		}

		else if (ch == 8)
			duyet(head);
		else
			break;
	}
	//	int i;
	//	for( i = 1; i<= 10; i++)
	//	{
	//		pushBack(&head,i); // do ham la con tro nen can truyen dia chi vao
	//	}

	// duyet(head);
	return 0;
}
