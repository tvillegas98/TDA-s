/*
Implementar una función que ordene de manera ascendente 
una pila de enteros sin conocer su estructura interna y utilizando como 
estructura auxiliar sólo otra pila auxiliar. Por ejemplo, la pila [ 4, 1, 5, 2, 3 ] 
debe quedar como [ 1, 2, 3, 4, 5 ] 
(siendo el último elemento el tope de la pila, en ambos casos). Indicar y justificar el orden de la función.
*/
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


void insertar_ordenado(pila_t* pila, int* dato){
    if(pila_esta_vacia(pila) || *dato < *(int*)pila_ver_tope(pila)){
        pila_apilar(pila, dato);
        return;
    }
    int* tope = pila_desapilar(pila);
    insertar_ordenado(pila, dato);
    pila_apilar(pila, tope);
}
//La complejidad del algoritmo es O(n²) dado que en el peor caso tenemos que vaciar
//la pila más de una vez
void ordenar_pila(pila_t* pila){
    if(pila_esta_vacia(pila)) return;
    int* dato = pila_desapilar(pila);
    ordenar_pila(pila);
    insertar_ordenado(pila, dato);
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