#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct lista_circular lista_circular_t;


/***************************
 *DEFINICION DE PRIMITIVAS *
 **************************/

lista_circular_t* crear_lista_circular();
bool lista_circular_esta_vacia(const lista_circular_t* );
bool lista_circular_insertar_ultimo(lista_circular_t* , void*);
bool lista_circular_insertar_primero(lista_circular_t*, void*);
void* lista_circular_ver_primero(const lista_circular_t* );
void* lista_circular_ver_ultimo(const lista_circular_t* );
void* lista_circular_borrar_primero(lista_circular_t* );
void lista_circular_destruir(lista_circular_t*, void (*destruir_dato)(void *));
size_t lista_circular_largo(const lista_circular_t* );

/***************************
 *DEFINICION DEL ITERADOR  *
 *       INTERNO           *
 **************************/
void lista_circular_iterar(lista_circular_t* , bool(*visitar)(void* , void* ), void* );


#endif //LISTA_CIRCULAR_H
