void _abb_mayores(const abb_nodo_t* abb, lista_t* lista, const char* clave){
    if(!abb) return;
    char* copia = abb->clave;
    int a = strcmp(copia, clave);
    if(a > 0){
        _abb_mayores(abb->izq, lista, clave);
        lista_insertar_primero(lista, abb->clave);
    }
    _abb_mayores(abb->der, lista,clave);
}

lista_t* abb_mayores(const abb_t* abb, const char* clave){
    lista_t* lista = lista_crear();
    if(!lista) return NULL;
    _abb_mayores(abb->raiz, lista, clave);
    return lista;
}