'''
Un árbol es un grafo no dirigido que cumple con las siguientes propiedades:

a. E = V - 1
b. Es acíclico <----Si se cumplen las primera, ya es aciclico
c. Es conexo

Por teorema, si un grafo cumple dos de estas tres condiciones, será árbol (y por consiguiente, cumplirá la tercera). 
Haciendo uso de ésto (y únicamente de ésto), se pide implementar una función que reciba un grafo no dirigido y 
determine si se trata de un árbol, o no. Indicar el orden de la función implementada.
'''



from grafo import Grafo
from grafo_conexo import es_conexo


def aristas_grafo(grafo: Grafo):
    aristas = 0
    for v in grafo:
        for w in grafo.adyacentes(v):
            aristas += 1
    return aristas//2

def es_arbol(grafo: Grafo):
    condicion_aristas = aristas_grafo(grafo) == len(grafo) - 1
    condicion_conexa = es_conexo(grafo)
    return condicion_aristas and condicion_conexa



if __name__ == "__main__":
    lista = [str(i) for i in range(7)]
    grafo = Grafo(lista)
    grafo.agregar_arista('0', '1')
    grafo.agregar_arista('0', '2')
    grafo.agregar_arista('1', '3')
    grafo.agregar_arista('1', '4')
    grafo.agregar_arista('2', '5')
    grafo.agregar_arista('2', '6')
    print(grafo)
    print(es_arbol(grafo))