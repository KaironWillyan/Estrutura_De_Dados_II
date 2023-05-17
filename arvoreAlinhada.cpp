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
void incluirNo(ArvoreNo<T>*& raiz, const T& valor) {
    if (raiz == NULL) {
        raiz = new ArvoreNo<T>(valor);
    } else {
        if (valor < raiz->valor) {
            incluirNo(raiz->esquerda, valor);
        } else {
            incluirNo(raiz->direita, valor);
        }
    }
}

template<typename T>
void percursoInOrder(ArvoreNo<T>* raiz) {
    if (raiz != NULL) {
        percursoInOrder(raiz->esquerda);
        cout << raiz->valor << " ";
        percursoInOrder(raiz->direita);
    }
}

template<typename T>
void percursoPreOrder(ArvoreNo<T>* raiz) {
    if (raiz != NULL) {
        cout << raiz->valor << " ";
        percursoPreOrder(raiz->esquerda);
        percursoPreOrder(raiz->direita);
    }
}

int main() {
    ArvoreNo<int>* raiz = NULL;

    incluirNo(raiz, 10);
    incluirNo(raiz, 5);
    incluirNo(raiz, 15);
    incluirNo(raiz, 3);
    incluirNo(raiz, 7);

    cout << "Percurso In-Order: ";
    percursoInOrder(raiz);
    cout << endl;

    cout << "Percurso Pre-Order: ";
    percursoPreOrder(raiz);
    cout << endl;

    return 0;
}
