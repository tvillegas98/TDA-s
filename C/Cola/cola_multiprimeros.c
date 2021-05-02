/*
Implementar la primitiva void** cola_multiprimeros(const cola_t* cola, size_t k) 
que dada una cola y un número kk, devuelva los primeros kk elementos de la cola, 
en el mismo orden en el que habrían salido de la cola. 
En caso que la cola tenga menos de kk elementos, 
rellenar con NULL. Indicar y justificar el orden de ejecución del algoritmo.
*/

#include "cola.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct nodo{
    void* dato;
    struct nodo* prox;
}nodo_t;


static nodo_t* crear_nodo(void* valor){
    nodo_t* nodo = malloc(sizeof(nodo_t));
    
    if(!nodo) return NULL;

    nodo->dato = valor;
    nodo->prox = NULL;

    return nodo;
}

typedef struct cola {
    nodo_t* prim;
    nodo_t* ult;
}cola_t;

/* *****************************************************************
 *                    PRIMITIVAS DE LA COLA
 * *****************************************************************/


cola_t *cola_crear(void){

    cola_t* cola = malloc(sizeof(cola_t));
    if(cola == NULL) return NULL;
    cola->prim = NULL;
    cola->ult = NULL;
    return cola;

}


bool cola_esta_vacia(const cola_t *cola){
    return cola->prim == NULL;
}

bool cola_encolar(cola_t *cola, void *valor){
    nodo_t* nuevo_nodo = crear_nodo(valor);
    if(!nuevo_nodo) return false;

    if(cola_esta_vacia(cola)){   
        cola->prim = nuevo_nodo;
        cola->ult = nuevo_nodo;
        return true;
    }
    cola->ult->prox = nuevo_nodo;
    cola->ult = nuevo_nodo;
    
    return true;
}

void *cola_ver_primero(const cola_t *cola){
    if(cola_esta_vacia(cola)) return NULL;
    void* puntero_auxiliar = cola->prim->dato;
    return puntero_auxiliar;
}

void *cola_desencolar(cola_t *cola){
    if(cola_esta_vacia(cola)) return NULL;

    nodo_t* nodo_auxiliar = cola->prim;
    void* puntero_auxiliar = nodo_auxiliar->dato;

    if(cola->prim == cola->ult){
        cola->ult = NULL;
    }

    cola->prim = cola->prim->prox;

    free(nodo_auxiliar);
    return puntero_auxiliar;
}

void cola_destruir(cola_t *cola, void (*destruir_dato)(void *)){
    while(!cola_esta_vacia(cola)){
        void* dato = cola_desencolar(cola);
        if(destruir_dato) destruir_dato(dato);
    }
    free(cola);
}

/*
Implementar la primitiva void** cola_multiprimeros(const cola_t* cola, size_t k) 
que dada una cola y un número kk, devuelva los primeros kk elementos de la cola, 
en el mismo orden en el que habrían salido de la cola. 
En caso que la cola tenga menos de kk elementos, 
rellenar con NULL. Indicar y justificar el orden de ejecución del algoritmo.
*/

void** cola_multiprimeros(cola_t* cola, size_t k){
    void** datos = malloc(sizeof(void*) * k);

    nodo_t* p = cola->prim;

    for(size_t i = 0; i < k; i++){
        if(p){
            datos[i] = p->dato;
            p = p->prox;
        }else{
            datos[i] = NULL;
        }
    }
    return datos;
}


int main(void){
    cola_t* cola = cola_crear();
    int vector[10];
    for(int i = 0; i < 10; i++){
        vector[i] = i;
        if(cola_encolar(cola, &vector[i])) printf("El valor encolado fue %d\n", vector[i]); 
    }
    void** datos = cola_multiprimeros(cola, 11);
    for(int i = 0; i < 11; i++){
        int* p = datos[i];
        printf("valor %d : %p\n", i, p);
    }
    cola_destruir(cola, NULL);
    free(datos);
}