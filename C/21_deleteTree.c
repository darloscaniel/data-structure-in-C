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
    
    //verifica se a raiz passada no parâmetro é válida
    if(root == NULL){
        printf("árvore vazia\n");
        return NULL;
    }

    //caso a raiz nao tenha sub-árvores
    if(root->left == NULL && root->right == NULL){
        free (root);
        return NULL;
    }

    //salvamos a raiz atual antes de modificá-la
    node* tempRoot = root;

    //caso a raiz nao tenha sub-árvore na esquerda
    if(root->left == NULL){
        root = tempRoot->right;
        free(tempRoot);
        return root;
    }

    //caso a raiz nao tenha sub-árvore na direita
    if(root->right == NULL){
        root = tempRoot->left;
        free (tempRoot);
        return root;
    }

    //caso a raiz tenha sub-árvores na direita e esquerda
    //nesse ponto tratamos o tempRoot como pai do maior
    node* largest = tempRoot->left;

    //procura o maior nó da subárvore da esquerda
    while(largest->right != NULL){
        tempRoot = largest;
        largest = largest->right;
    }

    //caso o maior nao seja filho direto da raiz, temos que realocar os nós
    if(tempRoot != root){
        tempRoot->right = largest->left;
    }
    
    //o maior assume o lugar da raiz da árvore e liberamos a raiz antiga
    largest->right = root->right;
    largest->left = root->left;
    free(root);
    return largest;
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

    printf("Árvore em ordem antes da remoção da raiz:\n");
    printTree(root);

    // Removendo a raiz várias vezes para testar
    printf("\nRemovendo a raiz atual (valor %d)\n", root->value);
    root = removeRoot(root);

    printf("\nÁrvore em ordem após uma remoção de raiz:\n");
    printTree(root);

    return 0;
}
