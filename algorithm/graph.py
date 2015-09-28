from queue import queue

class Vertex(object):
	def __init__(self, key):
		self.key = key
	def __repr__(self):
		return self.key
	def print_path(self, v):
		'''print out the vertices on a shortest path from s to
		v, assuming that BFS has already computed a breadth-first tree'''
		if self == v:
			print self,
		elif v.p == None:
			print "No path from {} to {} exists".format(self.key, v.key)
		else:
			self.print_path(v.p)
			print v,
class Graph(object):
	def __init__(self, vertices = tuple(), edges = tuple()):
		self.vertices = set(vertices)
		self.adj = dict()
		for u in vertices:
			self.adj[u] = set()
		for u,v in edges:
			self.addEdge(u, v)
		self.size = len(self.vertices)
	def addEdge(self, u, v):
		self.adj[u].add(v)
	def addVertex(self, u, edges = tuple()):
		self.vertices.add(u)	
		self.adj[u] = set(edges)
	def printEdge(self, u):
		for v in self.adj[u]:
			print v.key,
		print
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
			for v in self.adj[u]:
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
		for v in self.adj[u]:
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
		for v in self.adj[u]:
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
		for v in self.adj[s]:
			if v.color == 2:
				s.num = s.num + v.num
			elif v.color == 0:
				s.num = s.num + self.path_num_aux(v, t)
		s.color = 2
		return s.num
	def transpose(self):
		t = Graph(self.vertices)
		for u in self.vertices:
			for v in self.adj[u]:
				t.addEdge(v, u)
		return t
	def strongly_connected_components(self):
		global time, cc
		self.dfs()
		t = self.transpose()
		for u in t.vertices:
			u.color = 0
			u.p = None
		time = 0
		cc = 0
		for u in sorted(self.vertices, key = lambda u: u.f, reverse = True):
			if u.color == 0:
				cc = cc + 1
				t.strongly_connected_components_dfs_visit(u)
	def strongly_connected_components_dfs_visit(self, u):
		global time, cc
		u.cc = cc
		time = time + 1
		u.d = time
		u.color = 1
		for v in self.adj[u]:
			if v.color == 0:
				v.p = u
				self.strongly_connected_components_dfs_visit(v)
		u.color = 2
		time = time + 1
		u.f = time
	def simplified(self):
		'''create a simplified graph that has the same strong
		connected components and component graph as G and that is as small 
		as possible'''
		self.dfs()
		t = self.transpose()
		return t.simplified_dfs()
	def simplified_dfs(self):
		global time, cc, status
		status = dict()
		s = Graph(self.vertices)
		for u in self.vertices:
			u.color = 0
			u.p = None
		time = 0
		cc = 0
		for u in sorted(self.vertices, key = lambda u: u.f, reverse = True):
			if u.color == 0:
				stack = []
				cc = cc + 1
				self.simplified_dfs_visit(u, stack, s)
				for i in range(0, len(stack) - 1):
					s.addEdge(stack[i], stack[i + 1])
				if len(stack) > 1:
					s.addEdge(stack[len(stack) - 1], stack[0])
		return s
	def simplified_dfs_visit(self, u, stack, s):
		global time, cc, status
		stack.append(u)
		u.cc = cc
		time = time + 1
		u.d = time
		u.color = 1
		for v in self.adj[u]:
			if v.color == 0:
				v.p = u
				self.simplified_dfs_visit(v, stack, s)
			elif v.color == 2 and v.cc < u.cc:
				try:
					st = status[(v.cc, u.cc)]
				except KeyError:
					status[(v.cc, u.cc)] = 1	
					s.addEdge(v, u)	
		u.color = 2
		time = time + 1
		u.f = time
	def component_graph(self):
		'''compute the component graph of a directed graph
		there is at most one edge between two vertices in the component graph'''
		global time, cc, cg, status, vertices_list 
		self.dfs()
		t = self.transpose()
		for u in t.vertices:
			u.color = 0
			u.p = None
		time = 0
		cc = 0
		status = dict()
		vertices_list = list()
		cg = Graph()
		for u in sorted(self.vertices, key = lambda u: u.f, reverse = True):
			if u.color == 0:
				cc = cc + 1
				vertices_list.append(Vertex(cc))
				cg.addVertex(vertices_list[cc - 1])
				t.component_graph_dfs_visit(u)
		return cg
	def component_graph_dfs_visit(self, u):
		global time, cc, cg, vertices_list
		u.cc = cc
		time = time + 1
		u.d = time
		u.color = 1
		for v in self.adj[u]:
			if v.color == 0:
				v.p = u
				self.component_graph_dfs_visit(v)
			elif v.color == 2 and v.cc < u.cc:
				try:
					st = status[(v.cc, u.cc)]
				except KeyError:
					status[(v.cc, u.cc)] = 1	
					cg.addEdge(vertices_list[v.cc - 1], vertices_list[u.cc - 1])	
		u.color = 2
		time = time + 1
		u.f = time
	def semiconnected(self):
		cg = self.component_graph()
		vertices_list = sorted(cg.vertices, key = lambda u: u.key, reverse = False)
		for i in range(0, len(vertices_list) - 1):
			if vertices_list[i + 1] not in cg.adj[vertices_list[i]]:
				return False
		return True
