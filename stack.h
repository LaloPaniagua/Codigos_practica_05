#ifndef stack_H
#define stack_H
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _nodo NODO;
typedef char INFO;

struct _nodo{
    INFO info;
    NODO *sig;
    int prioridad;
};

typedef struct _pila PILA;
struct _pila{
    NODO *head;
    NODO *tail;
    int num;
};


NODO* crear_nodo(INFO info);
void eliminar_nodo(NODO* n);
PILA* crear_pila();
bool push(PILA* l,INFO info);
bool es_vacia(PILA *l);
void vaciar_pila(PILA *l);
void imprimir_pila(PILA *l);
void pop(PILA *l);
bool comparar(INFO info1, INFO info2);
INFO* first(PILA* l);
#endif
