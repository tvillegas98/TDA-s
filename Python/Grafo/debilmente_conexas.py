'''
Implementar un algoritmo que reciba un grafo dirigido y nos devuelva la cantidad de componentes débilmente conexas
de este. Indicar y justificar la complejidad del algoritmo implementado.
'''
from grafo import Grafo
from collections import deque

def dfs(grafo: Grafo, v:str, visitados: set, componente: list):
    visitados.add(v)
    componente.append(v)
    for w in grafo.adyacentes(v):
        if not w in visitados:
            dfs(grafo, w, visitados, componente)

def componentes_debilmente_conexas(grafo_dirigido: Grafo):
    grafo_nodirigido = Grafo(grafo_dirigido.obtener_vertices())
    for v in grafo_dirigido:
        for w in grafo_dirigido.adyacentes(v):
            if not grafo_dirigido.estan_unidos(w, v) and not grafo_nodirigido.estan_unidos(v,w):
                grafo_nodirigido.agregar_arista(v,w)

    componentes = list()
    visitados = set()
    for v in grafo_nodirigido:
        componente = list()
        if not w in visitados:
            dfs(grafo_dirigido, v, visitados, componente)
            componentes.append(componente)

    return len(componentes)

             

def main():
    grafo = Grafo(['A','B','C','D'], True)
    grafo.agregar_arista('A','B')
    grafo.agregar_arista('C','D')
    print(componentes_debilmente_conexas(grafo))
main()
    
