#include <stdio.h>
#include <stdlib.h>

//estrutura de nó da árvore
typedef struct cel
{
    int value;
    struct cel* right;
    struct cel* left;
}node;

void printTree(node* root){
    if(root != NULL){
        printTree(root->left);
        printf("%d\n", root->value);
        printTree(root->right);
    }
}

//função para inserir novos valores na árvore
node* insert(node* root, int value){

    //verifica se o ponteiro esta nulo para fazer a inserção
    if (root == NULL){
        node* newNode;
        newNode = malloc(sizeof(node));
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;

        //retorna o novo nó, necessariamente dentro de um ponteiro pra raiz da árvore
        return newNode;
    }

    //verifica se o valor inserido é maior ou menor que a raiz e chama a 
    //inserção recursivamente até encontrar o ponteiro nulo
    //caso o valor que deseja inserir seja encontrado na árvore, a inserção sera encerrada
    if (value == root->value) {
        printf("Valor %d já existe na árvore. Ignorando inserção.\n", value);
        return root; 
    } else if(value > root->value) {
        root->right = insert(root->right, value);
    }else{
        root->left = insert(root->left, value);
    }

    return root;
}

int main(){

    node* root = NULL;

    //aqui a raiz receberá o novo valor inserido, então "root->value = 10"
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);   
    insert(root, 3);
    insert(root, 7);

    printTree(root); 

    insert(root, 7);

    return 0;
}