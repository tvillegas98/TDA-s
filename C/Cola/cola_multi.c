/*
Implementar la función void** cola_multiprimeros(cola_t* cola, size_t k) 
con el mismo comportamiento de la primitiva anterior.
*/

#include "cola.h"
#include <stdio.h>

void** cola_multiprimeros(cola_t* cola, size_t k){
    void** datos = malloc(sizeof(void*) * k);
    cola_t* cola_aux = cola_crear();
    
    for(size_t i = 0; i < k ; i++){
        if(!cola_esta_vacia(cola)){
            void* p_aux = cola_desencolar(cola);
            datos[i] = p_aux;
            cola_encolar(cola_aux, p_aux);
        }else{
            datos[i] = NULL;
        }
    }

    while(!cola_esta_vacia(cola)){
        cola_encolar(cola_aux, cola_desencolar(cola));
    }

    while(!cola_esta_vacia(cola_aux)){
        cola_encolar(cola, cola_desencolar(cola_aux));
    }

    cola_destruir(cola_aux, NULL);
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