'''Implementar una función que determine el:

a. El grado de todos los vértices de un grafo no dirigido.

b. El grado de salida de todos los vértices de un grafo dirigido.

c. El grado de entrada de todos los vértices de un grafo dirigido.'''
from grafo import Grafo



def grados(grafo_nodirigido: Grafo):
    '''
    Función que calcula los grados de los vertices de un grafo no dirigido
    pasado por parámetro.
    returns:
        grados(dict)
    '''

    grados = dict()
    for v in grafo_nodirigido:
        grados[v] = len(grafo_nodirigido.adyacentes(v))    
    return grados

def grados_salida(grafo_dirigido: Grafo):
    '''
    Función que calcula los grados de salida de los vertices de un grafo
    pasado por parametro.
    returns:
        grados(dict)
    '''
    
    grados = dict()
    for v in grafo_dirigido:
        grados[v] = len(grafo_dirigido.adyacentes(v))
    return grados

def grados_entrada(grafo_dirigido: Grafo):
    '''
    Función que calcula los grados de entrada de los vertices de un grafo
    pasado por parámetro
    returns:
        grados(dict)
    '''
    grados = dict()
    for v in grafo_dirigido:
        for w in grafo_dirigido.adyacentes(v):
            grados[w] = grados.get(w, 0) + 1
    return grados



'''
Prueba
'''

if __name__ == "__main__":
    lista = [str(i) for i in range(10)]
    grafo_dirigido = Grafo(lista, True)
    grafo_nodirigido = Grafo(lista)
    grafo_dirigido.agregar_arista('0', '1')
    grafo_dirigido.agregar_arista('1', '2')
    grafo_nodirigido.agregar_arista('0', '1')
    grafo_nodirigido.agregar_arista('1', '2')
    print(grados(grafo_nodirigido))
    print(grados_salida(grafo_dirigido))
    print(grados_entrada(grafo_dirigido))