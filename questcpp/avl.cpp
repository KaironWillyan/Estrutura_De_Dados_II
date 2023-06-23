#include <iostream>
using namespace std;

// Estrutura de um nó AVL
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Função para obter a altura de um nó
int getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Função para calcular o fator de balanceamento de um nó
int getBalanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Função para atualizar a altura de um nó
void updateHeight(Node* node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = max(leftHeight, rightHeight) + 1;
}

// Função para rotacionar à direita em torno de um nó
Node* rotateRight(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

// Função para rotacionar à esquerda em torno de um nó
Node* rotateLeft(Node* node) {
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

// Função para inserir um nó em uma árvore AVL
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->height = 1;
        return newNode;
    }

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;  // Não permitir chaves duplicadas

    updateHeight(root);

    int balanceFactor = getBalanceFactor(root);

    // Caso de desbalanceamento à esquerda-esquerda
    if (balanceFactor > 1 && key < root->left->key)
        return rotateRight(root);

    // Caso de desbalanceamento à direita-direita
    if (balanceFactor < -1 && key > root->right->key)
        return rotateLeft(root);

    // Caso de desbalanceamento à esquerda-direita
    if (balanceFactor > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Caso de desbalanceamento à direita-esquerda
    if (balanceFactor < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Função para imprimir a árvore AVL em ordem
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Árvore AVL em ordem: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}