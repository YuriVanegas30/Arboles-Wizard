#include <stdio.h>
#include <stdlib.h>


struct Nodo {
    int dato;
    struct Nodo *izq;
    struct Nodo *der;
};


struct Nodo* crearNodo(int valor) {
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}


struct Nodo* insertar(struct Nodo* raiz, int valor) {

    
    if (raiz == NULL) {
        raiz = crearNodo(valor);
    }
    else {
        
        if (valor < raiz->dato) {
            raiz->izq = insertar(raiz->izq, valor);
        }
        
        else if (valor > raiz->dato) {
            raiz->der = insertar(raiz->der, valor);
        }
        
        else {
            printf("El valor %d ya está en el árbol (no se inserta).\n", valor);
        }
    }

    return raiz;
}


void inorder(struct Nodo* raiz) {
    if (raiz != NULL) {
        inorder(raiz->izq);
        printf("%d ", raiz->dato);
        inorder(raiz->der);
    }
}


void preorder(struct Nodo* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dato);
        preorder(raiz->izq);
        preorder(raiz->der);
    }
}


void postorder(struct Nodo* raiz) {
    if (raiz != NULL) {
        postorder(raiz->izq);
        postorder(raiz->der);
        printf("%d ", raiz->dato);
    }
}

int main() {

    struct Nodo* raiz = NULL;
    int numero;

    printf("=== Construcción de Árbol Binario (BST) ===\n");
    printf("Ingrese números (para terminar escriba -1)\n");


    do {
        printf("Número: ");
        scanf("%d", &numero);

        if (numero != -1) {
            raiz = insertar(raiz, numero);
        }

    } while (numero != -1);

    printf("\n--- Recorridos del Árbol ---\n");

    printf("Inorder (menor a mayor): ");
    inorder(raiz);
    printf("\n");

    printf("Preorder: ");
    preorder(raiz);
    printf("\n");

    printf("Postorder: ");
    postorder(raiz);
    printf("\n");

    return 0;
}
