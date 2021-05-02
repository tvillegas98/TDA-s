'''Implementar un algoritmo que determine si un grafo no dirigido es conexo o no. 
Indicar la complejidad del algoritmo si el grafo está implementado con una matriz de adyacencia.'''


from grafo import Grafo

def dfs(v: str, grafo: Grafo, visitados: set):
    visitados.add(v)
    for w in grafo.adyacentes(v):
        if not w in visitados:
            dfs(w, grafo, visitados)
    
def es_conexo(grafo: Grafo):
    visitados = set()
    v = grafo.obtener_vertice_aleatorio()
    dfs(v, grafo, visitados)
    return len(grafo) == len(visitados)

if __name__ == "__main__":
    lista = [str(i) for i in range(10)]
    grafo = Grafo(lista)
    for v in lista:
        for w in lista:
            if not grafo.estan_unidos(v, w) and v != w:
                grafo.agregar_arista(v,w)
    print(grafo)
    print(es_conexo(grafo))