class linked_list(object):
    def __init__(self):
        self.head = None
    def search(self, k):
        x = self.head
        while x != None and x.key != k:
            x = x.next
        return x
    def insert(self, x):
        x.next = self.head
        if self.head != None:
            self.head.prev = x
        self.head = x
        x.prev = None
    def delete(self, x):
        if x.prev != None:
            x.prev.next = x.next
        else:
            self.head = x.next
        if x.next != None:
            x.next.prev = x.prev
class linked_list_node(object):
    def __init__(self, element):
        self.key = element
        self.prev = None
        self.next = None
