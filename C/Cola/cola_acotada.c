/*
 Se quiere implementar un TDA ColaAcotada sobre un arreglo. 
 Dicho TDA tiene un espacio para k elementos (que se recibe por parámetro al crear la estructura). 
 Explicar cómo deberían implementarse 
 las primitivas encolar y desencolar de tal manera que siempre sean operaciones de tiempo constante.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct cola_acotada{
    void** datos;
    size_t tam;
    size_t cantidad;
    size_t index_e;
    size_t index_d;
}cola_acotada_t;

cola_acotada_t* cola_acotada_crear(size_t k){
    cola_acotada_t* cola = malloc(sizeof(cola_acotada_t));
    if(!cola) return NULL;

    void** datos = malloc(sizeof(void*) * k);
    if(!datos){
        free(cola);
        return NULL;
    } 

    cola->datos = datos;
    cola->tam = k;
    cola->cantidad == 0;
    cola->index_d = 0;
    cola->index_e = 0;

    return cola;
}

void cola_acotada_destruir(cola_acotada_t* cola){
    free(cola->datos);
    free(cola);
}

bool cola_acotada_esta_vacia(cola_acotada_t* cola){
    return cola->cantidad == 0;
}

bool cola_acotada_encolar(cola_acotada_t* cola, void* dato){
    if(cola->cantidad == cola->tam) return false;

    cola->datos[cola->index_e] = dato;
    if(cola->index_e + 1 == cola->tam){
        cola->index_e = 0;
    }else{
        cola->index_e++;
    }
    cola->cantidad++;
    return true; 
}

void* cola_acotada_desencolar(cola_acotada_t* cola){
    if(cola_acotada_esta_vacia(cola)) return false;

    void* dato = cola->datos[cola->index_d];
    if(cola->index_d + 1 == cola->tam){
        cola->index_d = 0;
    }else{
        cola->index_d++;
    }
    cola->cantidad--;
    return dato;
}

void* cola_acotada_ver_tope(cola_acotada_t* cola){
    if(cola_acotada_esta_vacia(cola)) return NULL;
    return cola->datos[cola->index_d];
}


int main(){
    cola_acotada_t* ca = cola_acotada_crear(5);
    int vector[5] = {2,3,4,5,6};
    for(int i = 0; i < 5; i++){
        if(cola_acotada_encolar(ca, &vector[i])){
            printf("se encolo el numero %d\n", vector[i]);
            int* dato = cola_acotada_ver_tope(ca);
            printf("%d \n", *dato);
        }
    }

    while(!cola_acotada_esta_vacia(ca)){
        printf("sigue en el while\n");
        int* dato = cola_acotada_desencolar(ca);
        int* tope = cola_acotada_ver_tope(ca);
        if(tope) printf("EL DATO DESENCOLADO ES: %d Y EL TOPE ACTUAL ES %d\n", *dato, *tope);
        else printf("La cola esta vacia el ultimo valor desencolado fue %d\n", *dato);
    }

    cola_acotada_destruir(ca);
}