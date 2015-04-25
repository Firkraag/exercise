import unittest
from max_priority_queue import max_priority_queue

class TestHeap(unittest.TestCase):
	def test_init(self):
		a = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]
		max_priority_queue(a)
		self.assertEquals(a, [16, 14, 10, 8, 7, 9, 3, 2, 4, 1])
#	def test_parent(self):
#		self.assertEquals(2, maparent(5))
#		self.assertEquals(2, parent(6))
	def test_max_heapify(self):
		a = [16, 4, 10, 14, 7, 9, 3, 2, 8, 1]
		max_priority_queue(a).max_heapify(1)
		self.assertEquals(a, [16, 14, 10, 8, 7, 9, 3, 2, 4, 1])
	def test_build_max_heap(self):
		a = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]
		max_priority_queue(a).build_max_heap()
		self.assertEquals(a, [16, 14, 10, 8, 7, 9, 3, 2, 4, 1])
	def test_heap_maximum(self):
		a = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]
		self.assertEquals(max_priority_queue(a).heap_maximum(), 16)
	def test_heap_extract_max(self):
		a = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]
		self.assertEquals(max_priority_queue(a).heap_extract_max(), 16)
		self.assertEquals(a, [14, 8, 10, 4, 7, 9, 3, 2, 1, 1])
	def test_heap_increase_key(self):
		a = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]
		max_priority_queue(a).heap_increase_key(8, 15)
		self.assertEquals(a, [16, 15, 10, 14, 7, 9, 3, 2, 8, 1])
			
