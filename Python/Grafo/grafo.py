class Grafo:
    def __init__(self, vertices = list(), dirigido = False):
        self.vertices = {v:dict() for v in vertices}
        self.dirigido = dirigido
    
    def __contains__(self, v):
        return v in self.vertices

    def __len__(self):
        return len(self.vertices)

    def __iter__(self):
        return iter(self.vertices)

    def validar_vertice(self, v):
        if not v in self.vertices:
            raise ValueError(f"No existe el vertice {v} en el grafo")

    def agregar_vertice(self, v):
        if v in self.vertices:
            raise ValueError(f"Ya existe el vertice{v} en el grafo")
        self.vertices[v] = dict()
    
    def borrar_vertice(self, v):
        self.validar_vertice(v)
        for w in self.vertices:
            if v in self.vertices[w]:
                del self.vertices[w][v]
        del self.vertices[v]
    
    def estan_unidos(self, v, w):
        self.validar_vertice(v)
        self.validar_vertice(w)
        return w in self.vertices[v]

    def agregar_arista(self, v, w, peso = 0):
        if self.estan_unidos(v, w):
            raise ValueError(f"Los vertices {v} y {w} ya poseen una aristas en comun")
        self.vertices[v][w] = peso
        if not self.dirigido:
            self.vertices[w][v] = peso
    
    def borrar_arista(self, v, w):
        if not self.estan_unidos(v,w):
            raise ValueError(f"No se puede borrar la arista entre {v} y {w} porque no existe")
        del self.vertices[v][w]
        if not self.dirigido:
            del self.vertices[w][v]
    
    
    def peso_arista(self, v, w):
        if not self.estan_unidos(v,w):
            raise ValueError(f"No se puede obtener el peso entre {v} y {w} porque no existe arista entre ellos")
        return self.vertices[v][w]

    def obtener_vertices(self):
        return list(self.vertices.keys())
    
    def obtener_vertice_aleatorio(self):
        return self.obtener_vertices()[0]
    
    def adyacentes(self, v):
        return list(self.vertices[v].keys())
    
    def __str__(self):
        string = ""
        for v in self.vertices:
            string += f"{v}" 
            for w in self.adyacentes(v):
                string += f" >>> {w}"
            string += "\n"
        return string
        