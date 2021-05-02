'''
Implementar un algoritmo que, dado un grafo dirigido, 
nos devuelva un ciclo dentro del mismo, si es que lo tiene. Indicar el orden del algoritmo.
'''
from grafo import Grafo
from collections import deque

def _tarjan(grafo: Grafo, v:str, visitados:set, apilados:set, orden:dict, mb:dict, pila:deque, cfc:list, index:list):
    visitados.add(v)
    orden[v] = index[0]
    mb[v] = orden[v]
    index[0] += 1
    pila.appendleft(v)
    apilados.add(v)
    
    for w in grafo.adyacentes(v):
        if w not in visitados:
            _tarjan(grafo, w, visitados, apilados, orden, mb, pila, cfc, index)

        if w in apilados:
            mb[v] = min(mb[v], mb[w])

    if orden[v] == mb[v] and len(pila) > 0:
        nueva_cfc = []
        while True:
            w = pila.popleft()
            apilados.remove(w)
            nueva_cfc.append(w)
            if w == v: break
        cfc.append(nueva_cfc)

def tarjan(grafo: Grafo):
    visitados = set()
    apilados = set()
    orden = dict()
    mb = dict()
    pila = deque()
    cfc = list()
    index = [0]
    vertice = grafo.obtener_vertice_aleatorio()
    _tarjan(grafo, vertice, visitados, apilados, orden, mb, pila, cfc, index)
    return cfc


if __name__ == "__main__":
    lista = [str(i) for i in range(10)]
    grafo = Grafo(lista, True)
    grafo.agregar_arista('0', '1')
    grafo.agregar_arista('1', '2')
    grafo.agregar_arista('2', '3')
    grafo.agregar_arista('3', '0')
    grafo.agregar_arista('0', '3')
    grafo.agregar_arista('1', '4')
    grafo.agregar_arista('5', '4')
    print(tarjan(grafo))