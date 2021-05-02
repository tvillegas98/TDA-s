/*Diseñar el TDA Mediana. Dicho TDA debe poder recibir un flujo de números y, 
en cualquier momento, debe poder consultársele cuál es la mediana de todos los elementos vistos hasta ese momento. 
La primitiva para agregar un nuevo número debe poder hacerse en O(logn) mientras que la operación de consultar la 
mediana debe ser O(1). Recordar que la mediana de una secuencia de números es el elemento que se encontraría a la mitad si 
la secuencia se encontrara ordenada (en caso de ser una cantidad par, 
se puede definir como el promedio entre ambos valores adyacentes del medio, o como uno de los dos de ellos de forma arbitraria)
*/


#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp_max(const void* p_a, const void* p_b){
    const int* a = p_a;
    const int* b = p_b;
    return *a > *b? 1:(*a < *b? -1:0);
}

int cmp_min(const void* p_a, const void* p_b){
    const int* a = p_a;
    const int* b = p_b;
    return *a < *b? 1:(*a > *b? -1:0);
}

typedef struct mediana {
    heap_t* min_heap;
    heap_t* max_heap;
}mediana_t;



mediana_t* mediana_crear(){
    mediana_t* mediana = malloc(sizeof(mediana_t));
    if(!mediana) return NULL;

    heap_t* min = heap_crear(cmp_min);
    if(!min){
        free(mediana);
        return NULL;
    }
    heap_t* max = heap_crear(cmp_max);
    if(!max){
        free(mediana);
        heap_destruir(min, NULL);
        return NULL;
    }

    mediana->max_heap = max;
    mediana->min_heap = min;
    return mediana;
}

void mediana_balancear(mediana_t* mediana){
    if(heap_cantidad(mediana->max_heap) > heap_cantidad(mediana->min_heap) + 1){
        heap_encolar(mediana->min_heap, heap_desencolar(mediana->max_heap));
    }else if(heap_cantidad(mediana->min_heap) > heap_cantidad(mediana->max_heap) + 1){
        heap_encolar(mediana->max_heap, heap_desencolar(mediana->min_heap));
    }

}

bool mediana_insertar(mediana_t* mediana, int* dato){
    if(heap_cantidad(mediana->min_heap) != 0 && *dato < *(int*)heap_ver_max(mediana->min_heap)){
        heap_encolar(mediana->max_heap, dato);
    }else{
        heap_encolar(mediana->min_heap, dato);
    }
    mediana_balancear(mediana);
    return true;
}

int mediana_ver(mediana_t* mediana){
    size_t cantidad_heap_min = heap_cantidad(mediana->min_heap);
    size_t cantidad_heap_max = heap_cantidad(mediana->max_heap);
    int* tope_min = heap_ver_max(mediana->min_heap);
    int* tope_max = heap_ver_max(mediana->max_heap);

    if(heap_cantidad(mediana->max_heap) > heap_cantidad(mediana->min_heap)){
        return *tope_max;
    }else if(heap_cantidad(mediana->min_heap) > heap_cantidad(mediana->max_heap)){
        return *tope_min;
    }
    return (*tope_max + *tope_min) / 2;

}

int mediana_borrar(mediana_t* mediana){
    if(heap_cantidad(mediana->max_heap) == 0 && heap_cantidad(mediana->min_heap) == 0) {
    	return -1;
    	printf("Ta vacia la wea \n");
    }
    
    if(heap_cantidad(mediana->max_heap) >= heap_cantidad(mediana->min_heap)){
    	printf("Entre aquí borrar maxheap\n");
        return *(int*)heap_desencolar(mediana->max_heap);
    }else if(heap_cantidad(mediana->min_heap) > heap_cantidad(mediana->max_heap)){
    	printf("Entre aquí borrar minheap\n");
        return *(int*)heap_desencolar(mediana->min_heap);
    }
}

void mediana_destruir(mediana_t* mediana){
    heap_destruir(mediana->min_heap, NULL);
    heap_destruir(mediana->max_heap, NULL);
    free(mediana);
}

void mediana_mostrar(mediana_t* mediana){
    printf("Datos del heap de minimos: ");
    heap_mostrar(mediana->min_heap);
    printf("Datos del heap de maximos: ");
    heap_mostrar(mediana->max_heap);
}

int main(void){
    int vector[] = {0,1,2,3,4,5,6,7,8,9,10};
    mediana_t* mediana = mediana_crear();
    
    for(int i = 0; i < 11; i++){
        mediana_insertar(mediana, &vector[i]);
        printf("Se inserto el valor %d\n", vector[i]);
    }
    
    mediana_mostrar(mediana);
    int median = mediana_ver(mediana);
    printf("la mediana es %d\n", median);
    median = mediana_borrar(mediana);
    median = mediana_borrar(mediana);
    median = mediana_borrar(mediana);
    median = mediana_borrar(mediana);
    median = mediana_borrar(mediana);
    median = mediana_borrar(mediana);
    median = mediana_borrar(mediana);
    printf("la mediana es %d\n", median);
    mediana_mostrar(mediana);
    median = mediana_ver(mediana);
    printf("la mediana es %d\n", median);
    median = mediana_ver(mediana);
    printf("la mediana es %d\n", median);
    mediana_mostrar(mediana);
    mediana_destruir(mediana);
}
