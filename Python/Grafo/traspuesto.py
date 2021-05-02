'''
Proponer una función para calcular el grafo traspuesto G^T de un grafo dirigido G. El grafo traspuesto G^T
posee los mismos vértices que G, pero con todas sus aristas invertidas (por cada arista (v, w) en G, existe una arista (w, v) en G^T
'''


from grafo import Grafo


def grafo_traspuesto(grafo: Grafo):
    grafo_nuevo = Grafo(grafo.obtener_vertices(), True)
    for v in grafo:
        for w in grafo.adyacentes(v):
            if not grafo_nuevo.estan_unidos(w, v):
                grafo_nuevo.agregar_arista(w, v)
    return grafo_nuevo


if __name__ == "__main__":
    grafo = Grafo([str(i) for i in range(3)], True)
    grafo.agregar_arista('0', '1')
    grafo.agregar_arista('0', '2')
    grafo.agregar_arista('1', '2')
    grafo.agregar_arista('2', '1')
    print(grafo)
    grafo_nuevo = grafo_traspuesto(grafo)
    print(grafo_nuevo)