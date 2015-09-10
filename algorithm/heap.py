class max_heap(object):
	def __init__(self, data):
		self.heap = data
		self.length = len(data)
		self.heap_size = self.length
		self.build_max_heap()
	def left(self, i):
		return 2 * i + 1
	def right(self, i):
		return 2 * i + 2
	def parent(self, i):
		return (i - 1) / 2
	def max_heapify(self, i):
		l = self.left(i)
		r = self.right(i)
		if (l <= (self.heap_size - 1)) and (self.heap[l] > self.heap[i]):
			largest = l
		else:
			largest = i
		if (r <= (self.heap_size - 1)) and (self.heap[r] > self.heap[largest]):
			largest = r
		if 	largest != i:
			self.heap[i],self.heap[largest] = self.heap[largest],self.heap[i]
			self.max_heapify(largest)
	def build_max_heap(self):
		self.heap_size = self.length
		for i in range(self.length / 2 - 1, -1, -1):
			self.max_heapify(i)
	def heapsort(self):
		self.build_max_heap()
		for i in range(self.length - 1, 0, -1):
			self.heap[0],self.heap[i] = self.heap[i],self.heap[0]
			self.heap_size = self.heap_size - 1
			self.max_heapify(0)
class min_heap(object):
	def __init__(self, data):
		self.heap = data
		self.length = len(data)
		self.heap_size = self.length
		self.build_min_heap()
	def left(self, i):
		return 2 * i + 1
	def right(self, i):
		return 2 * i + 2
	def parent(self, i):
		return (i - 1) / 2
	def min_heapify(self, i):
		l = self.left(i)
		r = self.right(i)
		if (l <= (self.heap_size - 1)) and (self.heap[l] < self.heap[i]):
			smallest = l
		else:
			smallest = i
		if (r <= (self.heap_size - 1)) and (self.heap[r] < self.heap[smallest]):
			smallest = r
		if 	smallest != i:
			self.heap[i],self.heap[smallest] = self.heap[smallest],self.heap[i]
			self.min_heapify(smallest)
	def build_min_heap(self):
		self.heap_size = self.length
		for i in range(self.length / 2 - 1, -1, -1):
			self.min_heapify(i)
