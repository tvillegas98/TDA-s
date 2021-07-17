from typing import Any, Callable, List
import random

class Heap(object):
    '''
    Heap data structure, it also allows the user to use upheap, downheap, Heapify and Heapsort algorithms.
    Time complexity:
        Upheap complexity: O(log N)
        Downheap complexity: O(log N)
        Heapify complexity: O(N)
        Heapsort complexity: O(N log N), Due in the worst case we downheap all the elements of the list.
    '''

    @classmethod
    def upheap(cls, data: List[Any], child: int, cmp: Callable[[Any, Any], int]) -> None:
        if child != 0:
            parent = (child - 1) // 2
            if cmp(data[child], data[parent]) > 0:
                data[child], data[parent] = data[parent], data[child]
                cls.upheap(data, parent, cmp)
                
    @classmethod
    def downheap(cls, data: List[Any], index: int, size: int, cmp: Callable[[Any, Any], int]) -> None:
        if index != size :
            left_child = (2 * index) + 1
            right_child = (2 * index) + 2

            parent = index

            if left_child < size and cmp(data[left_child], data[parent]) > 0:
                parent = left_child
            if right_child < size and cmp(data[right_child], data[parent]) > 0:
                parent = right_child
            
            if parent != index:
                data[parent], data[index] = data[index], data[parent]
                cls.downheap(data, parent, size, cmp)

    @classmethod
    def heapify(cls, data: List[Any], cmp: Callable[[Any, Any], int]) -> None:
        n = len(data)
        m = n // 2 - 1
        for i in range(m, -1, -1):
            cls.downheap(data, i, n, cmp)

    @classmethod
    def heapsort(cls, data: List[Any], cmp: Callable[[Any, Any], int]) -> None:
        cls.heapify(data, cmp)
        n = len(data)
        for i in range(n - 1, 0, -1):
            data[i], data[0] = data[0], data[i]
            cls.downheap(data, 0, i, cmp) 

    def __init__(self, cmp_function: Callable[[Any, Any], int], data: List[Any] = list()) -> None:
        '''
        Creates a Heap, with an arbitrary comparison function given by the user.
        I
        '''
        if len(data) != 0:
            self.heapify(data, cmp_function)
        self._data = data
        self._cmp = cmp_function

    def __len__(self):
        return len(self._data)
    
    def is_empty(self):
        return len(self) == 0
    
    def top(self):
        return self._data[0]
    
    def queue(self, element: any) -> any:
        self._data.append(element)
        self.upheap(self._data, len(self) - 1, self._cmp)

    def dequeue(self) -> any:
        if self.is_empty():
            raise ValueError("Heap has no elements.")
        element = self.top()
        self._data[0], self._data[len(self) - 1] = self._data[len(self) - 1], self._data[0]
        self._data.pop()
        self.downheap(self._data, 0, len(self), self._cmp)
        return element

    def __str__(self) -> str:
        string = ""
        string += '['
        for element in self._data:
            string += f" {str(element)} "
        string += ']'
        return string


def f(a,b) -> int:
    if a > b: return 1
    if b > a: return -1
    return 0
