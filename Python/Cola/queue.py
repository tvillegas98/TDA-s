class Node(object):

    def __init__(self, data, next = None):
        self.data = data
        self.next = next

class Queue(object):

    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
    
    def __len__(self):
        return self.size

    def is_empty(self):
        return len(self) == 0

    def enqueue(self, data):
        node = Node(data)

        if self.is_empty():
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            self.tail = node

        self.size += 1

    def dequeue(self):
        if self.is_empty():
            return None

        data = self.head.data

        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next
        
        self.size -= 1
        return data     

    def check_head(self):
        return self.head.data

    def __str__(self):
        string = ""
        auxiliar = self.head
        while auxiliar and auxiliar.next:
            string += f"{auxiliar.data}->"
            auxiliar = auxiliar.next
        if auxiliar:
            string += f"{auxiliar.data}"
        return string

if __name__ == "__main__":
    queue = Queue()
    for i in range(10):
        queue.enqueue(i)
    print(queue)
    while not queue.is_empty():
        queue.dequeue()
        print(f"Dequeue'd: {i}")
        print(queue)