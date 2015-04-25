import sys

class max_priority_queue(list):
	def __init__(self, data):
		self.__heap = data
		self.__length = len(data)
		self.__heap_size = self.__length
		self.build_max_heap()	# Turn list into a heap
	def left(self, i):
		return 2 * i + 1
	def right(self, i):
		return 2 * i + 2
	def parent(self, i):
		return (i - 1) / 2
	def max_heapify(self, i):
		l = self.left(i)
		r = self.right(i)
		if (l <= (self.__heap_size - 1)) and (self.__heap[l] > self.__heap[i]):
			largest = l
		else:
			largest = i
		if (r <= (self.__heap_size - 1)) and (self.__heap[r] > self.__heap[largest]):
			largest = r
		if 	largest != i:
			tmp = self.__heap[i]
			self.__heap[i] = self.__heap[largest]
			self.__heap[largest] = tmp
			self.max_heapify(largest)
	def build_max_heap(self):
		self.__heap_size = self.__length
		for i in range(self.__length / 2 - 1, -1, -1):
			self.max_heapify(i)
	def heap_maximum(self):
		return self.__heap[0]
	def heap_extract_max(self):
		if self.__heap_size < 1:
			sys.exit("heap underflow")
		max = self.__heap[0]
		self.__heap[0] = self.__heap[self.__heap_size - 1]
		self.__heap_size = self.__heap_size - 1
		self.max_heapify(0)
		return max
	def heap_increase_key(self, i, key):
		if key < self.__heap[i]:
			sys.exit("new key is smaller than current key")
		self.__heap[i] = key
		while i > 0 and self.__heap[self.parent(i)] < self.__heap[i]:
			tmp = self.__heap[self.parent(i)]
			self.__heap[self.parent(i)] = self.__heap[i]
			self.__heap[i] = tmp	
			i = self.parent(i)
	def max_heap_insert(self, key):
		self.__heap_size = self.__heap_size + 1
		self.__heap[self.__heap_size] = float("-Inf")
		self.heap_increase_key(self, self.__heap_size, key)
