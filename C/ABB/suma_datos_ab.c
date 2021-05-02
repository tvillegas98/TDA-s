int ab_suma(const ab_t* ab) {
    if(!ab) return 0;

    int dato = ab->dato;

    return dato + ab_suma(ab->izq) + ab_suma(ab->der);
}
