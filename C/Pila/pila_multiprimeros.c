/*
Implementar la primitiva de la pila void** pila_multitop(const pila_t* pila, size_t n), 
que devuelve un arreglo de tamaño nn con los nn topes de la pila (los primeros nn elementos si estos 
fueran desapilados), sin utilizar estructuras auxiliares. Completar el arreglo a devolver 
con NULL cuando el n recibido por parámetro sea mayor a la cantidad de elementos de la pila.
Indicar el orden de complejidad de la primitiva.
*/
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define CANTIDAD_INICIAL 10
#define DIMENSIONADOR 2

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void **datos;
    size_t cantidad;   // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

pila_t *pila_crear(void){
    pila_t* pila = malloc(sizeof(pila_t));
    if(pila == NULL) return NULL;
    
    pila->datos = malloc(CANTIDAD_INICIAL * (sizeof(void*)));

    if(pila->datos == NULL){
        free(pila);
        return NULL;
    }

    pila->capacidad = 10;
    pila->cantidad = 0;
    
    return pila;
}

bool pila_redimensionar(pila_t *pila, size_t capacidad_nueva){
    void** datos_nuevo;

    datos_nuevo = realloc(pila->datos, capacidad_nueva * sizeof(void*));
    if(datos_nuevo == NULL) return false;

    pila->capacidad = capacidad_nueva;
    pila->datos = datos_nuevo;
    return true;
}

void pila_destruir(pila_t *pila){
    free(pila->datos);
    free(pila);
}

bool pila_esta_vacia(const pila_t *pila){
    return pila->cantidad == 0;
}

bool pila_apilar(pila_t *pila, void *valor){

    if(pila->cantidad == pila->capacidad){ 
        if(!pila_redimensionar(pila, pila->capacidad * DIMENSIONADOR)) return false;
    }
    
    pila->cantidad++;
    pila->datos[pila->cantidad - 1] = valor;

    return true; 
}

void *pila_ver_tope(const pila_t *pila){

    if(pila_esta_vacia(pila)){
        return NULL;
    }

    void *puntero_aux = pila->datos[pila->cantidad - 1];
    
    return puntero_aux;
}

void *pila_desapilar(pila_t *pila){
    if(pila_esta_vacia(pila)) return NULL;
    
    void *puntero_aux = pila->datos[pila->cantidad - 1];

    if(pila->cantidad <= pila->capacidad/4 && pila->capacidad > CANTIDAD_INICIAL){
        if(!pila_redimensionar(pila, pila->capacidad / DIMENSIONADOR)) return NULL;
    }
    
    pila->cantidad--;

    return puntero_aux;
}

/*
Dado que iteramos en un for de ciclo N y N es la cantidad de elementos que solicitamos a la función
la complejidad de la primitiva es O(n)
*/
void** pila_multitop(const pila_t* pila, size_t n){
    void** datos = malloc(sizeof(void*) * n);
    if(!datos) return NULL;

    for(size_t i = 0; i < n; i++){
        if(i < pila->cantidad){
            printf("datos %zu: %d\n", i,*(int*)pila->datos[pila->cantidad - 1 - i]);
            datos[i] = pila->datos[pila->cantidad - 1 - i];
        }else{
            datos[i] = NULL;
        }
    }
    return datos;
}

int main(void){
    pila_t* pila = pila_crear();
    
    int tam = 10;
    int vector[tam];

    for(int i = 0; i < 10; i++){
        vector[i] = i;
        if(pila_apilar(pila, &vector[i])) printf("apilado el numero %d\n", vector[i]);
    }

    int k = 5;
    void** datos = pila_multitop(pila, k);
    for(int i = 0; i < k; i++){
        printf("VALOR DEL TOPE %d: %d\n", i, *(int*)datos[i]);
    }
    return 0;
}
