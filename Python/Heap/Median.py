from Heap import Heap


def _cmp_min(a:int , b:int):
    if a < b: return 1
    if a > b: return -1
    return 0

def _cmp_max(a:int , b:int):
    if a > b: return 1
    if a < b: return -1
    return 0

class Mediana():

    
    def __init__(self):
        self.min_heap = Heap(_cmp_min, [])
        self.max_heap = Heap(_cmp_max, [])
    

    def balance(self):
        if(len(self.max_heap) - len(self.min_heap) > 1):
            self.min_heap.queue(self.max_heap.dequeue())
        if(len(self.min_heap) - len(self.max_heap) > 1):
            self.max_heap.queue(self.min_heap.dequeue())

    def insert(self, value):
        if len(self.min_heap) != 0 and value < self.min_heap.top():
            self.max_heap.queue(value)
        else:
            self.min_heap.queue(value)
        
        self.balance()

    def get_median(self):
        if(len(self.max_heap) == len(self.min_heap)):
            min_top = self.min_heap.top()
            max_top = self.max_heap.top()
            return (min_top + max_top) // 2

        if(len(self.max_heap) > len(self.min_heap)):
            return self.max_heap.top()
        else:
            return self.min_heap.top() 
        
if __name__ == "__main__":
    lista = [0,1,2,3,4,5,6,7,8,9,10]
    mediana = Mediana()
    for x in lista:
        print(mediana.max_heap)
        print(mediana.min_heap)
        mediana.insert(x)
    print(f"{mediana.get_median()}")

