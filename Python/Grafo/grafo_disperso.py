'''Implementar un algoritmo que determine si un grafo no dirigido es un grafo disperso. Se considera que un grafo es
disperso si tiene menos del 5 % de las aristas totales que puede llegar a tener. Indicar y justificar el orden del algoritmo,
si el grafo se encuentra implementado con matriz de adyacencia.'''


'''
Un grafo no dirigido puede llegar a tener n(n-1) / 2, aristas totales, sin contar los vertices bucles.
'''

from grafo import Grafo

def grafo_calcular_aristas(grafo: Grafo):
    aristas = 0
    for v in grafo:
        for w in grafo.adyacentes(v):
            aristas +=1
    return aristas // 2

def grafo_disperso(grafo: Grafo):
    '''
    Verifica si un grafo es disperso o no.
    Complejidad:
    Como suponemos que el grafo está implementado como matriz de adyacencia y en una de las funciones calculamos la cantidad
    de aristas actuales en el grafo, esto nos traería una complejidad de O(V²) siendo V la cantidad de vertices en el grafo, 
    dado que por cada vertice visitamos a todos los vertices del grafo
    '''
    aristas_totales_posibles = len(grafo)*(len(grafo) - 1) // 2
    aristas_actuales = grafo_calcular_aristas(grafo)
    aristas_minimas = 5 * aristas_totales_posibles // 100
    print(f'''
    Aristas totales posibles: {aristas_totales_posibles}
    Aristas actuales: {aristas_actuales}
    Aristas mínimas: {aristas_minimas}
    ''')
    return aristas_actuales < aristas_minimas


if __name__ == "__main__":
    grafo = Grafo([str(i) for i in range(10)])
    grafo.agregar_arista('0', '1')
    # for i in range(10):
    #     for j in range(10):
    #         if i != j and not grafo.estan_unidos(str(i), str(j)):
    #             grafo.agregar_arista(str(i), str(j))
    print(grafo_disperso(grafo))