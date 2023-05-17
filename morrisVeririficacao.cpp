#include <iostream>

using namespace std;

template<typename T>
struct ArvoreNo {
    T valor;
    ArvoreNo<T>* left;
    ArvoreNo<T>* right;

    ArvoreNo(const T& valor) : valor(valor), left(NULL), right(NULL) {}
};

template<typename T>
void visit(ArvoreNo<T>* no) {
    cout << no->valor << " ";
}

template<typename T>

void MorrisPreorder(ArvoreNo<T>* root){
    ArvoreNo<T> *p=root, *tmp;
    while (p!=0){
        if (p->left==0){
            visit(p);
            p=p->right;
        }
        else{
            tmp = p->left;
            while (tmp->right!=0 && tmp->right!=p)
                tmp=tmp->right;
        if (tmp->right==0){
            visit(p);                    
            tmp->right=p;
            p=p->left;
        }
        else{                    
            tmp->right=0;
            p=p->right;    
        } /*fim else*/  }
    }
}


int main() {
    // Criando uma �rvore de teste
    ArvoreNo<int>* raiz = new ArvoreNo<int>(1);
    raiz->left = new ArvoreNo<int>(2);
    raiz->right = new ArvoreNo<int>(3);
    raiz->left->left = new ArvoreNo<int>(4);
    raiz->left->right = new ArvoreNo<int>(5);

    // Chamando o algoritmo para percurso pre-ordem
    MorrisPreorder(raiz);

    return 0;
}
