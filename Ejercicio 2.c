#include "ejercicio2.h"
#include <stdio.h>
#include <stdlib.h>

BCOLA *crear_bcola()
{
    BCOLA *c = (BCOLA *)malloc(sizeof(BCOLA));
    c->head = c->tail = NULL;
    c->num = 0;
    return c;
}
NODO *crear_nodo(INFO info)
{
    NODO *nodo = (NODO *)malloc(sizeof(NODO));
    nodo->sig = nodo->ant = NULL;
    nodo->info = info;
    return nodo;
}
void eliminar_nodo(NODO *n)
{
    if (n->sig == NULL && n->ant == NULL)
    {
        free(n);
        n = NULL;
    }
}
void eliminar_bcola(BCOLA *c)
{
    if (c == NULL)
        return;
    vaciar(c);
    free(c);
    c = NULL;
}
bool es_vacia(BCOLA *c)
{
    if (c->head == NULL && c->tail == NULL)
        return true;
    return false;
}
bool vaciar(BCOLA *c)
{
    if (es_vacia(c))
        return false;
    NODO *temporal = c->head;
    while (temporal != NULL)
    {
        c->head = temporal->sig;
        temporal->sig = NULL;
        c->head->ant = NULL;
        free(temporal);
        temporal = c->head;
    }
    c->head = c->tail = NULL;
    c->num = 0;
    return true;
}
bool insertar_inicio(BCOLA *c, INFO info)
{
    NODO *n = crear_nodo(info);
    if (es_vacia(c))
    {
        c->head = c->tail = n;
        c->num++;
        return true;
    }
    else
    {
        n->sig = c->head;
        c->head->ant = n;
        c->head = n;
        c->num++;
        return true;
    }
    return false;
}
bool insertar_fin(BCOLA *c, INFO info)
{
    NODO *n = crear_nodo(info);
    if (es_vacia(c))
    {
        c->head = c->tail = n;
        c->num++;
        return true;
    }
    else
    {
        n->ant = c->tail;
        c->tail->sig = n;
        c->tail = n;
    }
    return false;
}
void eliminar_inicio(BCOLA *c)
{
    if (es_vacia(c))
        return;
    NODO *temporal = c->head;
    c->head = c->head->sig;
    temporal->sig = NULL;
    c->head->ant = NULL;
    eliminar_nodo(temporal);
    c->num--;
}
void eliminar_fin(BCOLA *c)
{
    if (es_vacia(c))
        return;
    NODO *temporal = c->tail;
    c->tail = c->tail->ant;
    c->tail->sig = NULL;
    eliminar_nodo(c->tail);
    c->num--;
}

void imprimir_bcola(BCOLA *c)
{
    for (NODO *t = c->head; t != NULL; t = t->sig)
    {
        printf("%d ->", t->info);
    }
    printf("\n");
}
int main()
{
    BCOLA *c1;
    c1 = crear_bcola();
    insertar_inicio(c1, 5);
    imprimir_bcola(c1);
    insertar_inicio(c1, 7);
    imprimir_bcola(c1);
    insertar_fin(c1, 9);
    imprimir_bcola(c1);
    eliminar_inicio(c1);
    imprimir_bcola(c1);
    eliminar_fin(c1);
    vaciar(c1);
    eliminar_bcola(c1);
    getchar();
    return 0;
}
