'''
Dado un grafo no dirigido y pesado (todos pesos positivos), se desea averiguar el camino mínimo de un vértice v hacia
todos los demás vértices del grafo. Ahora bien, entre dos pares de vértices v y w podría existir más de un camino
mínimo posible (por supuesto, todos de mismo costo/peso total). Se desea que ante igualdad de costo, se defina que el
camino a tomar sea el más corto en cantidad de aristas. Explicar (en texto y/o implementando) cómo modificarías
el algoritmo de Dijkstra para cumplir lo pedido. La complejidad del algoritmo debería quedar tal cual el algoritmo
original. Indicar y justificar cuál es dicha complejidad, además de por qué no se modifica con la solución planteada.
Ejemplo: Para el siguiente grafo, se puede llegar desde A hacia D con 3 caminos posibles (detallados debajo). Todos de
costo 10. Se debe asegurar que el camino elegido sea el primero (el más corto). Lo mismo para los demás vértices destino.
A -> C -> D
A -> C -> F -> D
A -> C -> E -> F -> D
'''

from grafo import Grafo
from heap import Heap
from collections import deque

def cmp_distancias(a, b):
    if(a[0] > b[0]): return -1
    if(a[0] < b[0]): return 1
    return 0

def camino_minimo_dijkstra(grafo, origen):
    distancia = dict()
    cant_aristas = dict()
    padres = dict()
    for v in grafo:
        cant_aristas[v] = 0
        distancia[v] = float("inf")
    distancia[origen] = 0
    padres[origen] = None
    q = Heap(cmp_distancias)
    q.heap_encolar((0, origen))
    while not q.heap_esta_vacio():
        distancia_v, v = q.heap_desencolar()
        aristas_actuales = cant_aristas[v] + 1
        for w in grafo.adyacentes(v):
            if distancia[v] + grafo.peso_arista(v, w) == distancia[w] and aristas_actuales < cant_aristas[w]:
                padres[w] = v
                cant_aristas[w] = aristas_actuales
            elif distancia[v] + grafo.peso_arista(v, w) < distancia[w]:
                distancia[w] = distancia[v] + grafo.peso_arista(v,w)
                cant_aristas[w] = aristas_actuales
                padres[w] = v
                q.heap_encolar((distancia[w], w))
    return padres, distancia, cant_aristas

def main():
    grafo = Grafo(['A','B','C','D','E','F'])
    grafo.agregar_arista('B', 'A', 2)
    grafo.agregar_arista('A','C', 3)
    grafo.agregar_arista('C','D',7)
    grafo.agregar_arista('D','F',3)
    grafo.agregar_arista('F','E',2)
    grafo.agregar_arista('C','F',4)
    grafo.agregar_arista('C', 'E', 2)
    padres, distancia, cant_aristas = camino_minimo_dijkstra(grafo, 'A')
    print(padres)
    print(distancia)
    print(cant_aristas)
main()
