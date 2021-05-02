#include "pila.h"
#include <stdio.h>
#include <stdlib.h>



void ordenar_pila(pila_t* pila){
    pila_t* pila_aux = pila_crear();
    while(!pila_esta_vacia(pila)){
        int* tope = pila_desapilar(pila);
        while(!pila_esta_vacia(pila_aux) && *tope < *(int*)pila_ver_tope(pila_aux)){
            pila_apilar(pila, pila_desapilar(pila_aux));
        }
        pila_apilar(pila_aux, tope);
    }

    while(!pila_esta_vacia(pila_aux)){
        pila_apilar(pila, pila_desapilar(pila_aux));
    }
    pila_destruir(pila_aux);
}
int main(){
    pila_t* pila = pila_crear();
    int vector[5] = {4,1,5,2,3};
    for(int i = 0; i < 5; i++){
        pila_apilar(pila, &vector[i]);
    }
    ordenar_pila(pila);
    while(!pila_esta_vacia(pila)){
        int* dato = pila_desapilar(pila);
        printf("%d,", *dato);
    }
    printf("\n");
}