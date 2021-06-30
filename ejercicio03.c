#include<stdio.h>
#include<stdlib.h>
#include "ejercicio03.h"

NODO* crear_nodo(INFO info, int prioridad){
    NODO* t=(NODO*)malloc(sizeof(NODO));
    t->sig=NULL;
    t->info=info;
    t->prioridad=prioridad;
    return t;
}
COLA* crear_cola(){
    COLA* l=(COLA*)malloc(sizeof(COLA));
    l->head=l->tail=NULL;
    l->num=0;
    return l;
}
bool enqueue(COLA* l,INFO info, int prioridad){
    NODO* nuevo=crear_nodo(info,prioridad);
    if(l->head==NULL  && l->tail==NULL){
        l->head=l->tail=nuevo;
        l->num++;
        return true;
    }
    else if(nuevo->prioridad >= l->head->prioridad){
        nuevo->sig=l->head;
        l->head=nuevo;
        l->num++;
        return true;
    }
    else if(nuevo->prioridad <= l->tail->prioridad){
        l->tail->sig=nuevo;
        l->tail=l->tail->sig;
        l->num++;
        return true;
    }
    else{
        NODO* temporal = l->head;
        for(;temporal->prioridad > nuevo->prioridad;temporal=temporal->sig);
        nuevo->sig=temporal->sig;
        temporal->sig=nuevo;
        l->num++;
        return true;
    }
    return false;
}


void eliminar_nodo(NODO* n){
    if(n->sig==NULL){
        free(n);
        n=NULL;
    }
}

bool es_vacia(COLA *l){
    if(l->head==NULL && l->tail==NULL)
        return true;
    return false;
}

bool vaciar_cola(COLA *l){
    if(es_vacia(l)) return false;
    NODO* temporal = l->head;
    while(temporal != NULL){
        l->head=l->head->sig;
        temporal->sig=NULL;
        eliminar_nodo(temporal);
        temporal=l->head;
    }
    return true;
}

void imprimir_cola(COLA *l){
    for(NODO* t=l->head;t != NULL;t=t->sig){
        printf("%d ->",t->info);
    }
    printf("\n");
}

void dequeue(COLA *l){
    if(es_vacia(l)) return;
    else if(l->head==l->tail) {
        eliminar_nodo(l->head);
        l->num--;
    }
    else{
        NODO* temporal=l->head;
        l->head=l->head->sig;
        temporal->sig=NULL;
        eliminar_nodo(temporal);
        l->num--;
    }
}

INFO* first(COLA* l){
    if(es_vacia(l)) return NULL;
    return &l->head->info;
}

bool comparar(INFO info1, INFO info2){
    if(info1==info2) return true;
    return false;
}
    
int main(){
    COLA *l1=crear_cola();
    enqueue(l1,8,7);
    enqueue(l1,4,7);
    enqueue(l1,9,3);
    enqueue(l1,2,9);

    imprimir_cola(l1);

    dequeue(l1);

    imprimir_cola(l1);

    vaciar_cola(l1);
    free(l1);
    getchar();
    return(EXIT_SUCCESS);
}
