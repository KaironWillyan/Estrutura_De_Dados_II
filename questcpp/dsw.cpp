#include <iostream>
#include <cmath>
#include <iomanip>  
using namespace std;

// Estrutura de um nó DSW
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};
// Função para fazer uma rotação à direita
Node* rotateRight(Node* node) {
    if(node == nullptr || node->left == nullptr)
        return node;

    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    return newRoot;
}
// Função para realizar o balanceamento DSW
Node* DSWBalance(Node* root) {
    int n = 0;
    Node* curr = root;

    // Fase 1: Construir uma lista encadeada vertical
    while (curr != nullptr) {
        if (curr->left != nullptr) {
            Node* child = curr->left;
            curr->left = child->right;
            child->right = curr;
            curr = child;
        } else {
            n++;
            curr = curr->right;
        }
    }
    // Fase 2: Realizar rotações à direita para balancear a árvore
    int m = pow(2, floor(log2(n + 1))) - 1;
    curr = root;

    for (int i = 0; i < n - m; i++) {
        curr = rotateRight(curr);
        curr = curr->right;
    }

    while (m > 1) {
        m /= 2;
        curr = root;

        for (int i = 0; i < m; i++) {
            curr = rotateRight(curr);
            curr = curr->right;
        }
    }

    return root;
}
// Função para inserir um nó em uma árvore BST
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Função para realizar a travessia em ordem da árvore
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

void printTreeStructure(Node* root, int depth = 0) {
    if (root == nullptr)
        return;

    printTreeStructure(root->right, depth + 1);
    cout << setw(4 * depth) << ""; // Espaçamento proporcional à profundidade
    cout << root->key << endl;
    printTreeStructure(root->left, depth + 1);
}

int main() {
    Node* root = nullptr;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 1);
    root = insert(root, 6);

    // cout << "Árvore BST antes do balanceamento DSW: ";
    // inorderTraversal(root);
    // cout << endl;

    // root = DSWBalance(root);

    // cout << "Árvore BST após o balanceamento DSW: ";
    // inorderTraversal(root);
    // cout << endl;

    cout << "Árvore BST antes do balanceamento DSW:\n";
    printTreeStructure(root);
    cout << endl;

    cout << "Árvore BST após o balanceamento DSW:\n";
    root = DSWBalance(root);
    printTreeStructure(root);
    cout << endl;

    return 0;
}