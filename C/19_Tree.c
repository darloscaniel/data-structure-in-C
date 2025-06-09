#include <stdio.h>
#include <stdlib.h>

//estrutura de nó da árvore
typedef struct cel
{
    int value;
    struct cel* right;
    struct cel* left;
}node;

//função para percorrer a árvore em órdem (ERD) e imprimir valores
void printTree(node* root){
    if(root!= NULL){
        printTree(root->left);
        printf("%d\n", root->value);
        printTree(root->right);
    }
}

int main(){

    node a = {10, NULL, NULL};
    node b = {5, NULL, NULL};
    node c = {15, NULL, NULL};
    node d = {19, NULL, NULL};
    node e = {7, NULL, NULL};
    node f = {4, NULL, NULL};
    node g = {11, NULL, NULL};

    a.right = &c;
    a.left = &b;

    b.right = &e;
    b.left = &f;

    c.right = &d;
    c.left = &g;

    node* root = &a;

    printTree(root);

    return 0;
}



