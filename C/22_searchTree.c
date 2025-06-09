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
    if(root != NULL){
        printTree(root->left);
        printf("%d\n", root->value);
        printTree(root->right);
    }
}

//função para inserir novos valores na árvore
node* insert(node* root, int value){
    if (root == NULL){
        node* newNode;
        newNode = malloc(sizeof(node));
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

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

//função que remove a raiz atual e retorna uma nova raiz para a árvore
node* removeRoot(node* root){
    
    if(root == NULL){
        printf("árvore vazia\n");
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
        free (root);
        return NULL;
    }

    node* tempRoot = root;

    if(root->left == NULL){
        root = tempRoot->right;
        free(tempRoot);
        return root;
    }

    if(root->right == NULL){
        root = tempRoot->left;
        free (tempRoot);
        return root;
    }

    node* largest = tempRoot->left;

    while(largest->right != NULL){
        tempRoot = largest;
        largest = largest->right;
    }

    if(tempRoot != root){
        tempRoot->right = largest->left;
    }
    
    largest->right = root->right;
    largest->left = root->left;
    free(root);

    return largest;
}

//função que busca um valor na árvore
node* searchValue(node* root, int value){
    //caso insira uma raiz nula ou não encontre o valor o retorno é nulo
    if(root == NULL){
        printf("valor não encontrado\n");
        return NULL;
    }

    //caso encontre o valor na árvore retorna o nó
    if(value == root->value){
        printf("%d existe na árvore!", value);
        return root;
    }

    //chamada recursiva até encontrar, ou não, o valor
    if(value > root->value){
        return searchValue(root->right, value);
    }else{
        return searchValue(root->left, value);
    }
} 


int main() {
    node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Árvore em ordem:\n");
    printTree(root);

    printf("\n\nBuscando valor 40:\n");
    searchValue(root, 40);

    printf("\n\nBuscando valor 99:\n");
    searchValue(root, 99); 

    return 0;
}

