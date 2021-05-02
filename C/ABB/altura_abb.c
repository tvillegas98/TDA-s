size_t max(size_t uno, size_t dos){
    return uno >= dos ? uno:dos;
}

size_t ab_altura(const ab_t* ab) {
    if(!ab) return 0;

    size_t izq = ab_altura(ab->izq);
    size_t der = ab_altura(ab->der);

    return max(izq, der) + 1;
}
