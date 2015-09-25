from queue import queue

class Vertex(object):
	def __init__(self, key, edges = None):
		self.key = key
		if edges == None:
			self.edges = set()
		else:
			self.edges = edges
	def __repr__(self):
		return self.key
	def addEdge(self, node):
		self.edges.add(node)
	def printEdge(self):
		for v in self.edges:
			print v.key,
		print
	def print_path(self, v):
		if self == v:
			print self,
		elif v.p == None:
			print "No path from {} to {} exists".format(self.key, v.key)
		else:
			self.print_path(v.p)
			print v,
class Graph(object):
	def __init__(self, vertices = []):
		self.vertices = set()
		self.size = 0
		for vertex in vertices:
			self.addVertex(vertex)
	def addEdge(self, u, v):
		u.addEdge(v)
	def addVertex(self, u):
		self.vertices.add(u)	
	def bfs(self, s):
		for u in self.vertices:
			u.d = float("Inf")
			u.color = 0
			u.p = None
		s.color = 1
		s.d = 0
		s.p = None
		q = queue(2 * len(self.vertices))
		q.enqueue(s)
		while not q.empty():
			u = q.dequeue()
			for v in u.edges:
				if v.color == 0:
					v.color = 1
					v.d = u.d + 1
					v.p = u
					q.enqueue(v)
			u.color = 2
	def printVertices(self):
		for u in self.vertices:
			print "key : {}, distance: {}".format(u.key, u.d)
	def printAllEdges(self):
		self.status = dict()
		s = next(iter(self.vertices))
		print "key of s is {}".format(s.key)
		self.bfs(s)
		self.printAllEdges_aux(s)
	def printAllEdges_aux(self, u):
		for v in u.edges:
			if v.p == u:
				self.status[(v, u)] = 1
				print (u, v)
				self.printAllEdges_aux(v)
				print (v, u)
			else:
				try:
					status = self.status[(u, v)]
				except KeyError:
					self.status[(v, u)] = 1
					print (u, v)
					print (v, u)
