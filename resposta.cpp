#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }
};

void insert(Node*& root, int value) {
    if (root == NULL) {
        root = new Node(value);
        return;
    }

    if (value < root->value)
        insert(root->left, value);
    else
        insert(root->right, value);
}

int getHeight(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

vector<int> inOrderTraversal(Node* root) {
    vector<int> result;
    if (root == NULL)
        return result;

    vector<int> left = inOrderTraversal(root->left);
    result.insert(result.end(), left.begin(), left.end());

    result.push_back(root->value);

    vector<int> right = inOrderTraversal(root->right);
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

Node* balanceTree(vector<int>& sortedArray, int first, int last) {
    if (first > last)
        return NULL;

    int mid = (first + last) / 2;
    Node* root = new Node(sortedArray[mid]);

    root->left = balanceTree(sortedArray, first, mid - 1);
    root->right = balanceTree(sortedArray, mid + 1, last);

    return root;
}

bool isBalanced(Node* root){
	int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    bool isBalanced = abs(leftHeight - rightHeight) <= 1;
    
    return isBalanced;
}

bool areTreesEqual(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->value != root2->value)
        return false;

    return areTreesEqual(root1->left, root2->left) && areTreesEqual(root1->right, root2->right);
}

int main() {
    int arr[] = {7, 6, 22, 14, 40, 63};
    vector<int> values(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Node* root = NULL;
    for (size_t i = 0; i < values.size(); ++i)
        insert(root, values[i]);

    int height = getHeight(root);
    cout << "Altura da �rvore: " << height << endl;

    cout << "�rvore resultante (in-order): ";
    vector<int> inOrder = inOrderTraversal(root);
    for (size_t i = 0; i < inOrder.size(); ++i)
        cout << inOrder[i] << " ";
    cout << endl;

    cout << "A �rvore resultante est� balanceada? " << (isBalanced(root) ? "Sim" : "N�o") << endl;

    vector<int> sortedValues = values;
    sort(sortedValues.begin(), sortedValues.end());
    Node* root_ordenada = balanceTree(sortedValues, 0, sortedValues.size() - 1);

  
    cout << "arvore balanceada (in-order): ";
    vector<int> inOrderOrdenada = inOrderTraversal(root);
    Node* root_ordenada2 = balanceTree(sortedValues, 0, sortedValues.size() - 1);
    for (size_t i = 0; i < inOrderOrdenada.size(); ++i)
        cout << inOrderOrdenada[i] << " ";
    cout << endl;

    int balancedHeight = getHeight(root_ordenada);
    cout << "As arvores resultantes estao balanceadas? " << endl;
    cout << "	Vetor ordenado com sort: "<< (isBalanced(root_ordenada) ? "Sim" : "Nao") << endl;
    cout << "	Vetor ordenado com percurso in order: "<<(isBalanced(root_ordenada2) ? "Sim" : "Nao") << endl;
    cout << "As arvores resultantes sao iguais? "<<(areTreesEqual(root_ordenada,root_ordenada2) ? "Sim" : "Nao") << endl;

    return 0;
}
