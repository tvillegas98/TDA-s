#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int cmp(char* str_a, char* str_b){
    size_t len_a = strlen(str_a);
    size_t len_b = strlen(str_b);
    return len_a < len_b ? 1:(len_a > len_b ? -1:0);
}

char** top_k_cadenas(char* cadenas[], size_t n, size_t k){
    heap_t* heap_aux = heap_crear(cmp);

    for(size_t i = 0; i < k; i++){
        if(heap_encolar(heap_aux, cadenas[i])) printf("Se encolo la cadena %s\n", cadenas[i]);
    }

    for(size_t i = k; i < n; i++){
        if(cmp(cadenas[i], heap_ver_max(heap_aux))){
            heap_desencolar(heap_aux);
            heap_encolar(heap_aux, cadenas[i]);
        }
    }
    char** k_cadenas = malloc(sizeof(char*) * k + 1);
    for(size_t i = 0; i < k; i++){
        k_cadenas[i] = heap_desencolar(heap_aux);
    }
    k_cadenas[k] = NULL; 
    heap_destruir(heap_aux, NULL);
    return k_cadenas;
}

int main(void){
    char* cadenas[] = {"hola", "como", "estas", "yo bien", "me gustaria saber", "SNAADIASNDUIANDANSDIO", NULL};
    size_t n = 6;
    size_t k = 5;
    char** k_cadenas = top_k_cadenas(cadenas, n, k);
    size_t i = 0;
    while(k_cadenas[i]){
        printf("CADENA MÁS LARGA NUMERO %d, %s\n", k - i, k_cadenas[i]);
        i++;
    }
    free(k_cadenas);
}
