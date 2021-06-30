#include "stack.c"
int main(){ 
    char s[80],r[80],operadores[6]={'(','^','*','/','+','-'},operando[80];
    int i,j=0;
    PILA *p1 = crear_pila();
    printf("Por favor ingrese una expresion infija:\n");
    scanf("%s",s);
    int size = strlen(s);
    for(i=0;i<size;i++){
        if(s[i] != operadores[0] && s[i] != operadores[1] && s[i] != operadores[2] && s[i] != operadores[3] && s[i] != operadores[4] && s[i] != operadores[5] && s[i] != ')'){
            r[j]=s[i];
            j++;
        }
        else if (s[i] == operadores[0] || s[i]==operadores[1] || s[i]==operadores[2] || s[i]==operadores[3] || s[i]==operadores[4] || s[i]==operadores[5]){
            if(es_vacia(p1)) push(p1,s[i]);
            else{
                NODO* temporal=crear_nodo(s[i]);
                if (temporal->prioridad > p1->head->prioridad){
                    push(p1,s[i]);
                }
                else{ 
                    while(p1->head != NULL && temporal->prioridad <= p1->head->prioridad && p1->head->info != '('){
                    r[j]=p1->head->info;
                    pop(p1);
                    j++;
                    }
                    push(p1,temporal->info);
                }
            }
        }
        else if(s[i] == ')'){
            while(p1->head->info != '('){
                r[j]=p1->head->info;
                printf("%c %d \n",r[j],j);
                pop(p1);
                j++;
            }
        }
    }
    
    if(es_vacia(p1)==false){
        while(p1->head != NULL){
            r[j]=p1->head->info;
            pop(p1);
            j++;
        }
        pop(p1);
    }


	r[j]='\0';
    size=strlen(r);
    printf("expresion postfija: ");
    for(i=0;i<=size;i++)
        if (r[i] != '(') printf("%c",r[i]);
    printf("\n");
    vaciar_pila(p1);
    free(p1);
    p1=NULL;
    getchar();
    getchar();
    return EXIT_SUCCESS;
}
