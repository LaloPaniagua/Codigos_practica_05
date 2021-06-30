#ifndef ejercicio03_H
#define ejercicio03_H
#include <stdbool.h>
typedef struct _nodo NODO;
typedef int INFO;

struct _nodo{
    INFO info;
    NODO *sig;
    int prioridad;
};

typedef struct _cola COLA;
struct _cola{
    NODO *head;
    NODO *tail;
    int num;
};

NODO* crear_nodo(INFO info, int prioridad);
void eliminar_nodo(NODO* n);
COLA* crear_cola();
bool enqueue(COLA* l,INFO info, int prioridad);
bool es_vacia(COLA *l);
bool vaciar_cola(COLA *l);
void imprimir_cola(COLA *l);
void dequeue(COLA *l);
bool comparar(INFO info1, INFO info2);
INFO* first(COLA* l);
#endif
