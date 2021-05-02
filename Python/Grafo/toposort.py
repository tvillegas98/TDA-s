'''
En clase se ha demostrado que ningún algoritmo de ordenamiento comparativo puede ser mejor que O(n log n), siendo n
la cantidad de elementos del arreglo a ordenar. Al mismo tiempo, hemos visto algoritmos para obtener un ordenamiento
topológico de un conjunto de datos que, modelando el problema con grafos (dirigidos), termina resolviéndose en tiempo
lineal a la cantidad de vértices y aristas del mismo. Explicar por qué en problemas de ordenamientos (e.g.arreglo de
números de los que no se tiene información) no modelamos siempre a estos con grafos y luego resolvemos utilizando
alguno de los algoritmos antes mencionados.
Recomendación: pensar bien este ejercicio, hacerse dibujos, etc. . . antes de ponerse a escribir la respuesta. No responder
“no se puede resolver de esta forma”, porque sí se puede. Por el contrario, para plantear la respuesta conviene plantearse
cómo se haría para resolver un problema de ordenamiento usando una resolución de orden topológico. Esta consigna no
va sobre la posibilidad, sino por qué no es la mejor opción para hacerlo, a pesar de parecer una idea tentadora.
'''

'''
Respuesta:
Primero se debería de encontrar la forma para modelar el grafo y se me ocurrió la siguiente:
Primero, mis vertices obviamente son mis elementos del array y mis aristas deberían representar la jerarquía de menor/mayor, en este caso
podríamos decir que los grados de entrada de un vertice en particular, serían todos aquellos vertices MENORES a el. 
Planteando un ejemplo
[5,3,0,9,11]
5 es menor a 9 y 11, por lo tanto habrá dos aristas salientes de 5.
3 es menor a 5,9 y 11 por lo tanto habrá tres aristas salientes de 3.
0 es menor a todos los numeros del array, por lo tanto habrán 4 aristas salientes de 0.
9 es menor a 11, por lo tanto solo habrá un arista saliente
11 es el mayor, no tendrá aristas salientes.

Una vez modelado el grafo, solo tendríamos que aplicar el algoritmo de orden topológico y listo, obtendremos nuestro array ordenado.
Pero ahora viene la cuestión... armar el grafo cuesta O(N²) y el algoritmo de orden topológico cuesta O(V+E) dado se basa en la modificación de un BFS
utilizando grados de entrada. Finalmente obtendríamos una complejidad de O(N² + (V + E)) una complejidad bastante alta, entonces ¿por qué no se utiliza?.
Simple, modelar el grafo cuesta O(N²), con esa complejidad podríamos hasta utilizar bubblesort para ordenar el array y terminamos con el problema. Ahora,
si sabemos que podemos ordenar el array con una complejidad de O(N²), por qué optaría por utilizar un ordenamiento que cuesta O(N² + (V + E)), que además 
utiliza más espacio en memoria, si podría utilizar un algoritmo de ordenamiento comparativo de O(n log n) que es menor a O(N²).
Conclusión:
    Es una forma interesante de ordenar un array, pero mucho peor si lo comparamos con un algoritmo de ordenamiento comparativo que cuesta O(n log n).
'''

from grafo import Grafo
from collections import deque
from random import shuffle

def grados_entrada(grafo):
    '''
    Complejidad algoritmitica:
    En el primer for tenemos O(v) siendo v la cantidad de vertices en el grafo
    En los siguientes for anidados tenemos O(v + e), siendo V la cantidad de vertices y e la cantidad de aristas
    Entonces O(2v+e) = O(v + e)
    '''

    grados_ent = dict()
    for v in grafo:
        grados_ent[v] = 0
    for v in grafo:
        for e in grafo.adyacentes(v):
            grados_ent[e] += 1
    return grados_ent

def orden_topologico(grafo):
    resultado_final = list()
    gr_ent = grados_entrada(grafo)
    cola = deque()
    
    for v in grafo:
        if(gr_ent[v] == 0):
            cola.append(v)
        
    while len(cola) != 0:
        v = cola.popleft()
        resultado_final.append(v)
        for w in grafo.adyacentes(v):
            gr_ent[w] -= 1
            if(gr_ent[w] == 0):
                cola.append(w)
    return resultado_final

if __name__ == "__main__":
    lista = list(range(1000))
    shuffle(lista)
    grafo = Grafo(lista, True)
    for i in lista:
        for j in lista:
            if i != j and i < j:
                grafo.agregar_arista(i,j)
    print(grafo)
    print(orden_topologico(grafo))

