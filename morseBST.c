#include <stdio.h>
#include <stdlib.h>

char dot =  '.' ;
char dash = '-';

typedef struct Data
{
    char characters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U",
                          "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};

    char morsecode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
                         ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....",
                         "--...", "---..", "----.", "-----"};
}data_t;



struct Node
{
    data_t morse;
    struct Node *left;
    struct Node *right;
};
typedef struct Node node_t;


// giải phóng dữ liệu
void Free(node_t *root)
{
    if (root == NULL)
        return;

    Free(root->left);
    Free(root->right);
    free(root);
}

// if is dot, move to the left
int LeftOf(  )
{
    return ;
}

// if is dash, mofe to the right
int RightOf(  )
{
    return;
}


// add to the tree
node_t* Insert( node_t* root, data_t data )
{
    if ( root == NULL )
    {
        node_t* node = (node_t*)malloc( sizeof( node_t ) );
        node->left = NULL;
        node->right = NULL;
        node->data = value;
        return node;
    }

    while ( data.morsecode != '\0')
    {
        if ( LeftOf() )
    }
    if ( LeftOf( value, root ) ) // neu gia tri them la be hon
        root->left = Insert( root->left, value ); // de quy de insert
    else if ( RightOf( value, root ) )
        root->right = Insert( root->right, value ); // de uy de insert vao ben phai
    return root;
}




int main()
{
    
}
