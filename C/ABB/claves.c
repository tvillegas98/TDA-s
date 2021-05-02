void _abb_obtener_claves(abb_nodo_t* abb, lista_t* lista){
    if(!abb) return;

    lista_insertar_ultimo(lista, abb->clave);
    _abb_obtener_claves(abb->izq, lista);
    _abb_obtener_claves(abb->der, lista);

}


lista_t* abb_obtener_claves(abb_t* abb) {
    lista_t* lista = lista_crear();
    if(!lista) return NULL;
    _abb_obtener_claves(abb->raiz, lista);
    return lista;
}