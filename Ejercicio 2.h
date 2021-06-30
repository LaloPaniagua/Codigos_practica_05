#ifndef EJERCICIO2.H
#define EJERCICIO2.H
#include <stdbool.h>

typedef struct _NODO NODO;
typedef int INFO;

struct _NODO{
    INFO info;
    NODO *sig;
    NODO *ant;
};

NODO *crear_nodo(INFO info);
void eliminar_nodo(NODO *n);

typedef struct _BCOLA BCOLA;

struct _BCOLA{
    NODO *head;
    NODO *tail;
    int num;
};

BCOLA *crear_bcola();
void eliminar_bcola(BCOLA *c);
bool es_vacia(BCOLA *c);
bool vaciar(BCOLA *c);
bool insertar_inicio(BCOLA *c, INFO info);
bool insertar_fin(BCOLA *c, INFO info);
void eliminar_inicio(BCOLA *c);
void eliminar_fin(BCOLA *c);
void imprimir_bcola(BCOLA *c);
NODO *crear_nodo(INFO info);
void eliminar_nodo(NODO *n);
#endif
