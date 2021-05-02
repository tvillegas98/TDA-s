size_t ab_2_hijos(const ab_t* ab) {
    if(!ab) return 0;
    size_t num = ab->izq && ab->der? 1:0;
    return num + ab_2_hijos(ab->izq) + ab_2_hijos(ab->der);
}
