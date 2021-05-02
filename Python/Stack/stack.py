class Stack(object):

    def __init__(self):
        self.stack = list()
    
    def __len__(self):
        return len(self.stack)
    
    def pop(self):
        return self.stack.pop()
    
    def push(self, data):
        self.stack.append(data)
    
    def top(self):
        if len(stack) == 0:
            return None
        return self.stack[len(stack) - 1]