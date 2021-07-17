from Heap import Heap


def min_cmp(a, b):
    if(a > b): return -1
    elif(a < b): return 1
    return 0

def max_cmp(a,b):
    if(a > b): return 1
    if(a < b): return -1
    return 0

def top_k_min_heap(array, k):
    '''
    Since we queue k elements into the heap and we also traversal the array between k~len(array), we get the following
    Complexity
    O(k + n log k)
    '''
    auxiliar_heap = Heap(min_cmp)
    for i in range(k):
        auxiliar_heap.queue(array[i])
    
    for i in range(k+1, len(array)):
        if array[i] > auxiliar_heap.top():
            auxiliar_heap.dequeue()
            auxiliar_heap.queue(array[i])

    result = list()
    while not auxiliar_heap.is_empty():
        result.append(str(auxiliar_heap.dequeue()))
    result = ",".join(result)
    print(f"Using a min heap in top-k algorithm: {result}")

def top_k_max_heap(array, k):
    '''
    since we queue all the elements within the array and after that we dequeue the next k elements, we get the following
    Complexity:
    O(n + k log n)
    '''
    auxiliar_heap = Heap(max_cmp)
    for element in array:
        auxiliar_heap.queue(element)
    
    result = list()
    for i in range(k):
        result.append(str(auxiliar_heap.dequeue()))
    result = ",".join(result)
    print(f"Using a max heap in top-k algorithm: {result}")

if __name__ == "__main__":
    array = [1,2,3,4,5,6,7,8,9]
    array = list(reversed(array))
    top_k_min_heap(array, 7)
    top_k_max_heap(array, 7)