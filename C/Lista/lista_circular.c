//
// Created by Tommy on 29/3/21.
//

#include "lista_circular.h"

/**************************************
 *      ESTRUCTURAS                   *
 * ************************************/
typedef struct nodo_lista {
    void* dato;
    struct nodo_lista* prox;
}nodo_lista_t;

struct lista_circular{
    nodo_lista_t* prim;
    nodo_lista_t* ult;
    size_t largo;
};

/**************************************
 *      PRIMITIVAS DEL NODO           *
 * ************************************/
static nodo_lista_t* crear_nodo(void* dato){
    nodo_lista_t* nodo = malloc(sizeof(nodo_lista_t));
    if(!nodo) return NULL;

    nodo->dato = dato;
    nodo->prox = NULL;
    return nodo;
}

/**************************************
 *      PRIMITIVAS DE LA LISTA        *
 *                CIRCULAR            *
 * ************************************/

lista_circular_t* crear_lista_circular(void){
    lista_circular_t* lista_circular = malloc(sizeof(lista_circular_t));
    if(!lista_circular) return NULL;

    lista_circular->largo = 0;
    lista_circular->prim = NULL;
    lista_circular->ult = NULL;

    return lista_circular;
}


bool lista_circular_esta_vacia(const lista_circular_t* lista){
    return lista->largo == 0;
}

bool lista_circular_insertar_ultimo(lista_circular_t* lista, void* dato){
    nodo_lista_t* nodo = crear_nodo(dato);
    if(!nodo) return false;

    if(lista_circular_esta_vacia(lista)){
        lista->prim = nodo;
        lista->ult = nodo;
    }else{
        lista->ult->prox = nodo;
        lista->ult = nodo;
    }
    lista->ult->prox = lista->prim;
    lista->largo++;
    return true;
}

bool lista_circular_insertar_primero(lista_circular_t* lista, void* dato){
    nodo_lista_t* nodo = crear_nodo(dato);
    if(!nodo) return false;

    if(lista_circular_esta_vacia(lista)){
        lista->prim = nodo;
        lista->ult = nodo;
    }else{
        nodo->prox = lista->prim;
        lista->prim = nodo;
    }
    lista->ult->prox = lista->prim;
    lista->largo++;
    return true;
}


void* lista_circular_ver_primero(const lista_circular_t* lista){
    if(lista_circular_esta_vacia(lista)) return NULL;
    return lista->prim->dato;
}

void* lista_circular_ver_ultimo(const lista_circular_t* lista){
    if(lista_circular_esta_vacia(lista)) return NULL;
    return lista->ult->dato;
}

void* lista_circular_borrar_primero(lista_circular_t* lista){
    if(lista_circular_esta_vacia(lista)) return NULL;
    nodo_lista_t* nodo_aux = lista->prim;
    void* dato = nodo_aux->dato;

    if(lista->prim == lista->ult){
        lista->prim = NULL;
        lista->ult = NULL;
    }else{
        lista->prim = nodo_aux->prox;
        lista->ult->prox = lista->prim;
    }
    free(nodo_aux);
    lista->largo--;
    return dato;
}

void lista_circular_destruir(lista_circular_t* lista, void (*destruir_dato)(void *)){
    while(!lista_circular_esta_vacia(lista)){
        void* dato = lista_circular_borrar_primero(lista);
        if(destruir_dato) destruir_dato(dato);
    }
    free(lista);
}


size_t lista_circular_largo(const lista_circular_t* lista){
    return lista->largo;
}

/**************************************
 * PRIMITIVA DEL ITERADOR INTERNO     *
 * ************************************/

void lista_circular_iterar(lista_circular_t* lista, bool(*visitar)(void* dato, void *extra), void* extra){
    if(lista_circular_esta_vacia(lista)) return;
    bool iterar = true;
    nodo_lista_t* aux = lista->prim;
    do{
        iterar = visitar(aux->dato, extra);
        aux = aux->prox;
    }while(aux != lista->prim and iterar);
}

