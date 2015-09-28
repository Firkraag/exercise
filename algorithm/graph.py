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
	def dfs(self):
		global time
		for u in self.vertices:
			u.color = 0
			u.p = None
		time = 0
		for u in self.vertices:
			if u.color == 0:
				self.dfs_visit(u)
	def dfs_visit(self, u):
		global time
		time = time + 1
		u.d = time
		u.color = 1
		for v in u.edges:
			if v.color == 0:
				v.p = u
				self.dfs_visit(v)
		u.color = 2
		time = time + 1
		u.f = time
	def printVertices(self):
		for u in self.vertices:
			print "key : {}, distance: {}".format(u.key, u.d)
	def printAllEdges(self):
		self.status = dict()
		s = next(iter(self.vertices))
		print "key of s is {}".format(s.key)
		self.printAllEdges_aux(s)
	def printAllEdges_aux(self, u):
		for v in u.edges:
			try:
				status = self.status[(u, v)]
			except KeyError:
				self.status[(u, v)] = 1
				self.status[(v, u)] = 1
				print (u, v)
				self.printAllEdges_aux(v)
				print (v, u)
	def path_num(self, s, t):
		for u in self.vertices:
			u.color = 0
			u.num = 0
		t.color = 2
		t.num = 1
		return self.path_num_aux(s, t)
	def path_num_aux(self, s, t):
		s.color = 1
		for v in s.edges:
			if v.color == 2:
				s.num = s.num + v.num
			elif v.color == 0:
				s.num = s.num + self.path_num_aux(v, t)
		s.color = 2
		return s.num
	def simplified(self):
		'''create a simplified graph that has the same strong
		connected components and component graph as G and that is as small 
		as possible'''
		self.dfs()
		t = self.transpose()
		t.simplified_aux()
	def simplified_aux(self):
		s = Graph()
		for u in self.vertices:
			u.color = 0
			u.p = None
		
