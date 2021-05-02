/*
Diseñar un TDA PilaConMáximo, que tenga las mismas primitivas de la pila convencional 
(en este caso, sólo para números), y además permita obtener el máximo de la pila. 
Todas las primitivas deben funcionar en \mathcal{O}(1)O(1). 
Explicar cómo implementarías el TDA para que cumpla con todas las restricciones.
*/
#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct pila_maximo{
    pila_t* pila;
    pila_t* maximos;
    size_t cantidad;
}pila_maximo_t;



pila_maximo_t* pila_maximo_crear(){
    pila_maximo_t* pila = malloc(sizeof(pila_maximo_t));
    if(!pila) return NULL;

    pila->pila = pila_crear();
    if(!pila->pila){
        free(pila);
        return NULL;
    }
    pila->maximos = pila_crear();
    if(!pila->maximos){
        pila_destruir(pila->pila);
        free(pila);
        return NULL;
    }
    pila->cantidad = 0;
    return pila;
}

void pila_maximo_destruir(pila_maximo_t* pila){
    pila_destruir(pila->pila);
    pila_destruir(pila->maximos);
    free(pila);
}

bool pila_maximo_esta_vacio(pila_maximo_t* pila){
    return pila->cantidad == 0;
}

bool pila_maximo_apilar(pila_maximo_t* pila, int* dato){
    if(pila_maximo_esta_vacio(pila)){
        pila_apilar(pila->maximos, dato);
        pila_apilar(pila->pila, dato);
        pila->cantidad++;
        return true;
    }
    
    if(*dato > *(int*)pila_ver_tope(pila->maximos)){
        pila_apilar(pila->maximos, dato);
        pila_apilar(pila->pila, dato);
    }else{
        pila_apilar(pila->pila, dato);
    }

    pila->cantidad++;
    return true;
}

int* pila_maximo_desapilar(pila_maximo_t* pila){
    int* tope_pila = pila_ver_tope(pila->pila);
    int* tope_maximo = pila_ver_tope(pila->maximos);
    if(tope_pila == tope_maximo){
        pila_desapilar(pila->pila);
        pila_desapilar(pila->maximos);
    }else{
        pila_desapilar(pila->pila);
    }
    pila->cantidad--;
    return tope_pila;
}

int* pila_maximo_ver_tope(pila_maximo_t* pila){
    if(pila_maximo_esta_vacio(pila)) return NULL;
    return pila_ver_tope(pila->pila);
}

int* pila_maximo_ver_maximo(pila_maximo_t* pila){
    if(pila_maximo_esta_vacio(pila)) return NULL;
    return pila_ver_tope(pila->maximos);
}




int main(void){
    pila_maximo_t* pila = pila_maximo_crear();
    int vector[5] = {4,3,1,9,2};
    for(int i = 0; i < 5; i++){
        pila_maximo_apilar(pila, &vector[i]);
    }
    int* maximo = pila_maximo_ver_maximo(pila);
    int* tope = pila_maximo_ver_tope(pila);
    printf("El tope es %d\n", *tope);
    printf("El maximo es %d\n", *maximo);
    while(!pila_maximo_esta_vacio(pila)){
        int* tope = pila_maximo_desapilar(pila);
        printf("VALOR DESENCOLADO: %d\n", *tope); 
    }
    pila_maximo_destruir(pila);
}
