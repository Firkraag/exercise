import unittest
from heap import max_heap, min_heap

class TestHeap(unittest.TestCase):
#	def test_init(self):
#		a = heap([4, 1, 3, 2, 16, 9, 10, 14, 8, 7])
#		self.assertEquals(a.__heap, a)
#		self.assertEquals(a.__length, 10)
#		self.assertEquals(a.__heap_size, 10)
	def test_max_heapify(self):
		a = [16, 4, 10, 14, 7, 9, 3, 2, 8, 1]
		max_heap(a).max_heapify(1)
		self.assertEquals(a, [16, 14, 10, 8, 7, 9, 3, 2, 4, 1])
	def test_build_max_heap(self):
		a = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]
		max_heap(a).build_max_heap()
		self.assertEquals(a, [16, 14, 10, 8, 7, 9, 3, 2, 4, 1])
	def test_heapsort(self):
		a = [4, 1, 3, 3, 16, 9, 10, 14, 8, 7]
		max_heap(a).heapsort()
		self.assertEquals(a, [1, 3, 3, 4, 7, 8, 9, 10, 14, 16])
	def test_min_heapify(self):
		a = [1, 10, 3, 2, 7, 8, 9, 4, 14, 16]
		min_heap(a).min_heapify(1)
		self.assertEquals(a, [1, 2, 3, 4, 7, 8, 9, 10, 14, 16])
	def test_build_min_heap(self):
		a = [1, 10, 3, 2, 7, 8, 9, 4, 14, 16]
		min_heap(a).build_min_heap()
		self.assertEquals(a, [1, 2, 3, 4, 7, 8, 9, 10, 14, 16])
