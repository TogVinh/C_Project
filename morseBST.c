#include <stdio.h>
#include <stdlib.h>

typedef struct Data
{
    char characters[50] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U",
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

// đi về node trái của cây
// int LeftOf(const int value, const node_t *root)
// {
//     // Nếu bạn muốn cây BST cho phép giá trị trùng lặp, hãy sử dụng dòng code thứ 2
//     return value < root->data;
//     //    return value <= root->data;
// }

// // đi về node phải của cây
// int RightOf(const int value, const node_t *root)
// {
//     return value > root->data;
// }

// char g_code[37][10] = {
//     {".-a"}   , {"-...b"} , {"-.-.c"} , {"-..d"}, {".e"} , 
//     {"..-.f"} , {"--.g"}  , {"....h"} , {"..i"} , {".---j"}, 
//     {"-.-k"}  , {".-..l"} , {"--m"}   , {"-.n"} , 
//     {"---o"}  , {".--.p"} , {"--.-q"} , {".-.r"}, {"...s"},
//     {"-t"}    , {"..-u"}  , {"...-v"} , {".--w"}, {"-..-x"},
//     {"-.--y"} , {"--..z"} ,
//     {".----1"}, {"..---2"},{"...--3"},{"....-4"},{".....5"},
//     {"-....6"}, {"--...7"},{"---..8"}, {"----.9"}, {"-----0"},
//     " /"
// };

// char characters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U",
//                           "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};

// char morsecode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
//                          ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....",
//                          "--...", "---..", "----.", "-----"};