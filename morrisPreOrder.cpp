#include <iostream>
using namespace std;

template<typename T>
struct ArvoreNo {
    T valor;
    ArvoreNo<T>* esquerda;
    ArvoreNo<T>* direita;

    ArvoreNo(const T& valor) : valor(valor), esquerda(NULL), direita(NULL) {}
};

template<typename T>
void visit(ArvoreNo<T>* no) {
    cout << no->valor << " ";
}

template<typename T>
void MorrisPreorder(ArvoreNo<T>* root) {
    ArvoreNo<T> *p = root, *tmp;
    while (p != 0) {
        if (p->esquerda == 0) {
            visit(p);
            p = p->direita;
        } else {
            tmp = p->esquerda;
            while (tmp->direita != 0 && tmp->direita != p)
                tmp = tmp->direita;

            if (tmp->direita == 0) {
                visit(p);
                tmp->direita = p;
                p = p->esquerda;
            } else {
                tmp->direita = 0;
                p = p->direita;
            }
        }
    }
}

template<typename T>
void morrisPreOrder(ArvoreNo<T>* raiz) {
    ArvoreNo<T>* atual = raiz;
    while (atual != NULL) {
        if (atual->esquerda == NULL) {
            cout << atual->valor << " ";
            atual = atual->direita;
        } else {
            ArvoreNo<T>* antecessor = atual->esquerda;
            while (antecessor->direita != NULL && antecessor->direita != atual)
                antecessor = antecessor->direita;

            if (antecessor->direita == NULL) {
                cout << atual->valor << " ";
                antecessor->direita = atual;
                atual = atual->esquerda;
            } else {
                antecessor->direita = NULL;
                atual = atual->direita;
            }
        }
    }
}

template<typename T>
void morrisInOrder(ArvoreNo<T>* raiz) {
    ArvoreNo<T>* atual = raiz;
    while (atual != NULL) {
        if (atual->esquerda == NULL) {
            cout << atual->valor << " ";
            atual = atual->direita;
        } else {
            ArvoreNo<T>* antecessor = atual->esquerda;
            while (antecessor->direita != NULL && antecessor->direita != atual)
                antecessor = antecessor->direita;

            if (antecessor->direita == NULL) {
                antecessor->direita = atual;
                atual = atual->esquerda;
            } else {
                antecessor->direita = NULL;
                cout << atual->valor << " ";
                atual = atual->direita;
            }
        }
    }
}

int main() {
    ArvoreNo<int>* raiz = new ArvoreNo<int>(1);
    raiz->esquerda->direita = new ArvoreNo<int>(5);
    raiz->esquerda = new ArvoreNo<int>(2);
    raiz->esquerda->esquerda = new ArvoreNo<int>(4);
    raiz->direita = new ArvoreNo<int>(3);

    morrisInOrder(raiz);
    cout << endl;

    morrisPreOrder(raiz);
    cout << endl;

    return 0;
}
