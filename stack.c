#include "stack.h"
NODO* crear_nodo(INFO info){
    NODO* t=(NODO*)malloc(sizeof(NODO));
    t->sig=NULL;
    t->info=info;
    if(t->info=='(') t->prioridad=6;
    if(t->info=='^') t->prioridad=5;
    if(t->info=='*') t->prioridad=4;
    if(t->info=='/') t->prioridad=4;
    if(t->info=='+') t->prioridad=3;
    if(t->info=='-') t->prioridad=3;
    return t;
}
PILA* crear_pila(){
    PILA* l=(PILA*)malloc(sizeof(PILA));
    l->head=l->tail=NULL;
    l->num=0;
    return l;
}
bool push(PILA* l,INFO info){
    NODO* nuevo=crear_nodo(info);
    if(l->head==NULL  && l->tail==NULL){
        l->head=l->tail=nuevo;
        l->num++;
        return true;
    }
    else{
        nuevo->sig=l->head;
        l->head=nuevo;
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

bool es_vacia(PILA *l){
    if(l->head==NULL && l->tail==NULL) return true;
    else return false;
}

void vaciar_pila(PILA *l){
    if(es_vacia(l)) return;
    NODO* temporal = l->head;
    while(temporal != NULL){
        l->head=l->head->sig;
        temporal->sig=NULL;
        eliminar_nodo(temporal);
        temporal=l->head;
    }
    return;
}

void imprimir_pila(PILA *l){
    for(NODO* t=l->head;t != NULL;t=t->sig){
        printf("%c ->",t->info);
    }
    printf("\n");
}

void pop(PILA *l){
    if(es_vacia(l)) return;
    else if(l->head==l->tail){
        eliminar_nodo(l->head);
        l->head=l->tail=NULL;
    }
    else{
        NODO* temporal=l->head->sig;
        l->head->sig=NULL;
        eliminar_nodo(l->head);
        l->head=temporal;
        l->num--;
    }
}

INFO* first(PILA* l){
    if(es_vacia(l)) return NULL;
    return &l->head->info;
}

bool comparar(INFO info1, INFO info2){
    if(info1==info2) return true;
    return false;
}
