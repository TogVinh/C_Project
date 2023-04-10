#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} node_t;


// dung de giai phong du lieu
void Free( node_t* root )
{
    if ( root == NULL )
        return;

    Free( root->left );
    Free( root->right );
    free( root );
}

// dieu huong cay sang trai
int LeftOf( const int value, const node_t* root )
{
    // N?u b?n mu?n c�y BST cho ph�p gi� tr? tr�ng l?p, h�y s? d?ng d�ng code th? 2
    return value < root->data;
//    return value <= root->data;
}

// dieu huong cay sang phai
int RightOf( const int value, const node_t* root )
{
    return value > root->data;
}


// them phan tu
node_t* Insert( node_t* root, const int value )
{
    if ( root == NULL )
    {
        node_t* node = (node_t*)malloc( sizeof( node_t ) );
        node->left = NULL;
        node->right = NULL;
        node->data = value;
        return node;
    }
    if ( LeftOf( value, root ) ) // neu gia tri them la be hon
        root->left = Insert( root->left, value ); // de quy de insert
    else if ( RightOf( value, root ) )
        root->right = Insert( root->right, value ); // de uy de insert vao ben phai
    return root;
}


//tim kiesm tren cay nhi phan dung recursion
/* neu node hien t?i c� gia tri => return
gia tri can tim < node => de quy de tim o cay con ben trai
gia tri can tim >node => de quy tim o cay con ben phai
*/
bool Search( const node_t* root, int value )
{
    if ( root == NULL )
        return 0;
    if(root->data == value){
        return 1;
    }else if ( LeftOf( value, root ) ){
        return Search( root->left, value );
    }else if( RightOf( value, root ) ){
        return Search( root->right, value );
    }
}

// node con trai nhat
/* node be nhat trong mot nhanh cua node nao do
=> node nay ơ ben trai cuoi cung trong nhanh do
=> node se la node leaf hoac co right child
gia tri be nhat so voi node do se luon nam o ben trai cuoi cung*/
int LeftMostValue( const node_t* root )
{
    while ( root->left != NULL )
        root = root->left;
    return root->data;
}


//xoa mot node
/*khi xoa mot node ta can thay the voi 1 node khac ma van dam bao quy luat
-neu node do khong co child thi chi can giai phong
- node co 1 child => noi node child roi giai phong node can xoa
- node can xoa co 2 child 
  +) tim node the than
  +) node thay the nodeLessChild cua nhanh ben phai
  +) gọi dệ quy hàm xóa để xóa node lessChild
*/
node_t* Delete( node_t* root, int value )
{
    if ( root == NULL )
        return root;
    if ( LeftOf( value, root ) )
        root->left = Delete( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Delete( root->right, value );
    else
    {
        // root->data == value, delete this node
        if ( root->left == NULL )
        {
            node_t* newRoot = root->right;
            free( root );
            return newRoot;
        }
        if ( root->right == NULL )
        {
            node_t* newRoot = root->left;
            free( root );
            return newRoot;
        }
        root->data = LeftMostValue( root->right );
        root->right = Delete( root->right, root->data );
    }
    return root;
}

void PreOrder(node_t* root){
    if(root != NULL)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(node_t* root){
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

void PostOrder(node_t* root){
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}


int main()
{
    node_t* root = NULL;

    root = Insert( root, 25 );
    root = Insert( root, 15 );
    root = Insert( root, 50 );
    root = Insert( root, 10 );
    root = Insert( root, 22 );
    root = Insert( root, 35 );
    root = Insert( root, 70 );
    root = Insert( root, 4 );
    root = Insert( root, 12 );
    root = Insert( root, 18 );
    root = Insert( root, 24 );
    root = Insert( root, 31 );
    root = Insert( root, 44 );
    root = Insert( root, 66 );
    root = Insert( root, 90 );
    printf("\nDuyet preorder : ");
    PreOrder(root);
    printf("\nDuyet inorder  : ");
    InOrder(root);
    printf("\nDuyet postorder:");
    PostOrder(root);

    printf("\n==Thu them phan tu 15 vao BTS==\n");
    Insert(root, 15);
    printf("\nDuyet preorder : ");
    PreOrder(root);
    printf("\nDuyet inorder  : ");
    InOrder(root);
    printf("\nDuyet postorder:");
    PostOrder(root);


    printf("\n==Thu xoa phan tu 50 khoi BTS==\n");
    Delete(root, 50);
    printf("\nDuyet preorder : ");
    PreOrder(root);
    printf("\nDuyet inorder  : ");
    InOrder(root);
    printf("\nDuyet postorder:");
    PostOrder(root);




    Free( root );
    root = NULL;
    return 0;
}


//#include <stdlib.h>
//#include <stdio.h>
//#include <stdbool.h>
//
//int main()
//{
//	int a = 45;
//	int b = 46;
//	
//	printf("\na = %c", a); // -
//	printf("\nb = %c", b); // .
//	printf("%c%c",a,b);
//	
//	
//	return 0;
//}
