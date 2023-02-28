#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct tree {
    int data;
    struct tree *left;
    struct tree *right;
} *Tree;

Tree createNodeTree(int x, Tree l, Tree r){
    Tree newTree = (Tree)malloc(sizeof(Tree));
    newTree->data = x;
    newTree->left = l;
    newTree->right = r;
}

Tree emptyTree(){
    return NULL;
}

void printFormated(Tree root){
    if(root != NULL){
        cout << "<" << root->data;

        printFormated(root->left);
        printFormated(root->right);
        cout << ">";
    }
}

void firstSearch(Tree root){
    queue<Tree> fila;
    fila.push(root);
    Tree node;

    while(!fila.empty()){
        node = fila.front();
        fila.pop();

        cout << node->data;

        if(node->left != NULL){
            fila.push(node->left);
        }

        if(node->right != NULL){
            fila.push(node->right);
        }
    }
}

int nodesTot(Tree root){
    if(root = NULL){
        return 0;
    }

    return nodesTot(root->left) + nodesTot(root->right) +1;
}

int contLeaves(Tree root){
    if(root == NULL) {
	    return 0;
	}
	
	if(root->left == NULL && root->right == NULL) {
		return 1;
	}

	return contLeaves(root->left) + contLeaves(root->right);
}

int alturaTree(Tree root){
    if(root == NULL){
        return 0;
    }

    int left = alturaTree(root->left);
    int right = alturaTree(root->right);

    if(left > right){
        return left + 1;
    }

    return right + 1;
}

bool tem(Tree root, int item){
    if(root == NULL){
        return false;
    }

    if(root->data == item){
        return true;
    }

    return tem(root->left, item) || tem(root->right, item);
}