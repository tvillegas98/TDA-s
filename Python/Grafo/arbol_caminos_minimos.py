'''
A un grafo pesado y no dirigido se le obtuvo un árbol de tendido mínimo. Sobre dicho árbol se quiere obtener caminos
mínimos. Implementar un algoritmo que reciba dicho árbol y un vértice v y obtenga los caminos mínimos desde v hacia
todos los demás vértices (sobre dicho grafo en forma de árbol, no el grafo original) en tiempo lineal de la cantidad de
vértices y aristas. Justificar la complejidad del algoritmo implementado.
'''

from grafo import Grafo
from collections import deque


def arbol_bfs(arbol: Grafo, v: str):
    '''
    Complejidad: O(V + E)
    '''
    visitados = set()
    distancias = dict()
    distancias[v] = 0
    cola = deque()
    cola.append(v)
    while len(cola) != 0:
        v = cola.popleft()
        for w in grafo.adyacentes(v):
            if w not in visitados:
                distancias[w] = distancias[v] + 1 
                visitados.add(w)
                cola.append(w)
    return distancias



