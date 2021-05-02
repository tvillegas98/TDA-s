class Node(object):

    def __init__(self, data, next = None):
        self.data = data
        self.next = next

class LinkedList(object):

    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
    
    def __len__(self):
        return self.size 

    def is_empty(self):
        return len(self) == 0
    
    def insert_at_head(self, dato):
        nodo = Node(dato)

        if self.is_empty():
            self.head = nodo
            self.tail = nodo
        else:
            nodo.next = self.head
            self.head = nodo
        
        self.size += 1
    
    def insert_at_tail(self, dato):
        nodo = Node(dato)

        if self.is_empty():
            self.head = nodo
            self.tail = nodo
        else:
            self.tail.next = nodo
            self.tail = nodo
        
        self.size += 1
    
    def get_head(self, dato):
        return self.head

    def get_tail(self, dato):
        return self.tail
    
    def delete_head(self, dato):
        if self.is_empty():
            return

        data = self.head.data

        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next
        
        self.size -= 1
    
    def __str__(self):
        string = ""
        auxiliar = self.head
        while auxiliar.next:
            string += f"{auxiliar.data}->"
            auxiliar = auxiliar.next
        string += f"{auxiliar.data}"
        return string


if __name__ == "__main__":
    linked_list = ListaEnlazada()
    linked_list.insert_at_head(4)
    linked_list.insert_at_head(5)
    linked_list.insert_at_head(6)
    linked_list.insert_at_head(7)
    linked_list.insert_at_tail(8)
    print(linked_list)