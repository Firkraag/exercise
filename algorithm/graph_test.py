#!/usr/bin/env ipython
import unittest
from graph import Vertex, Graph

class TestGraph(unittest.TestCase):
	def testBfs(self):
		s = Vertex('s')
		r = Vertex('r')
		v = Vertex('v')
		w = Vertex('w')
		t = Vertex('t')
		x = Vertex('x')
		u = Vertex('u')
		y = Vertex('y')
		z = Vertex('z')
		vertices = [v,r,s,w,t,x,u,y,z]
		edges = [(s, r), (s, w), (r, v), (r, s), (v, r), (w, s), (w, t), (w, x), (t, w), (t, x), (t, u), (u, t), (u, x), (u, y), (x, w), (x, t), (x, u), (x, y), (y, x), (y, u)]
		g = Graph(vertices, edges)
		#g.printAllEdges()
		#for i in g.vertices:
		#	i.printEdge()
	#		print
		g.bfs(s)
	#	g.printVertices()
		self.assertEquals(s.d, 0)
		self.assertEquals(r.d, 1)
		self.assertEquals(v.d, 2)
		self.assertEquals(w.d, 1)
		self.assertEquals(t.d, 2)
		self.assertEquals(x.d, 2)
		self.assertEquals(u.d, 3)
	 	self.assertEquals(y.d, 3)
	def testDfs(self):
		s = Vertex('s')
		v = Vertex('v')
		z = Vertex('z')
		w = Vertex('w')
		y = Vertex('y')
		x = Vertex('x')
		t = Vertex('t')
		u = Vertex('u')
		#edges_list = [(z, w), (s, w), (y, w), (x, ), (x, ), (z, ), (v, u), (v, t)]
		#vertices = (s, v, z, w, y, x, t, u)
		#map(lambda vertex, edges: map(lambda vertex, edge: vertex.addEdge(edge), zip([vertex] * len(edges) , edges)),  zip(vertices, edges_list))
		vertices = [s, v, z, w, y, x, t, u]
		edges = [(y, x), (x, z), (z, y), (z, w), (w, x), (s, z), (s, w), (v, w), (v, s), (t, v), (t, u), (u, v), (u, t)]
		g = Graph(vertices, edges)
		g.dfs()
		vertices = (s, v, z, w, y, x, t, u)
		for u in vertices:
			print u, u.d, u.f
		#df = [(1, 10), (12, 13), (2, 9), (7, 8), (3, 6), (4, 5), (11, 16), (14, 15)]
		#edges_list = [(z, w), (s, w), (y, w), (x, ), (x, ), (z, ), (v, u), (v, t)]
	def testPathNum(self):
		m = Vertex('m')		
		n = Vertex('n')		
		o = Vertex('o')		
		p = Vertex('p')		
		q = Vertex('q')		
		r = Vertex('r')		
		s = Vertex('s')		
		t = Vertex('t')		
		u = Vertex('u')		
		v = Vertex('v')		
		w = Vertex('w')		
		x = Vertex('x')		
		y = Vertex('y')		
		z = Vertex('z')		
		vertices = [m, n, o, p, q, r, s, t, u, v, w, x, y, z]
		edges = [(m, q), (m, r), (m, x), (n, q), (n, o), (n, u), (o, r), (o, s), (o, v), (p, o), (p, s), (p, z), (q, t), (r, u), (r, y), (s, r), (u, t), (v, w), (v, x), (w, z), (y, v)]
		g = Graph(vertices, edges)
		self.assertEquals(g.path_num(m, v), 1)
		self.assertEquals(g.path_num(n, v), 3)
		self.assertEquals(g.path_num(o, v), 3)
		self.assertEquals(g.path_num(p, v), 4)
		self.assertEquals(g.path_num(q, v), 0)
		self.assertEquals(g.path_num(r, v), 1)
		self.assertEquals(g.path_num(s, v), 1)
		self.assertEquals(g.path_num(t, v), 0)
		self.assertEquals(g.path_num(u, v), 0)
		self.assertEquals(g.path_num(v, v), 1)
		self.assertEquals(g.path_num(w, v), 0)
		self.assertEquals(g.path_num(x, v), 0)
		self.assertEquals(g.path_num(y, v), 1)
		self.assertEquals(g.path_num(z, v), 0)
	def testSCC(self):
		a = Vertex('a')		
		b = Vertex('b')		
		c = Vertex('c')		
		d = Vertex('d')		
		e = Vertex('e')		
		f = Vertex('f')		
		g = Vertex('g')		
		h = Vertex('h')		
		vertices = [a, b, c, d, e, f, g, h]
		edges = [(e, a), (a, b), (b, c), (d, c), (c, d), (b, e), (e, f), (b, f), (g, f), (f, g), (c, g), (g, h), (h, h)]	
		G = Graph(vertices, edges)
		G.strongly_connected_components()
		self.assertEquals(a.cc, 1)
		self.assertEquals(b.cc, 1)
		self.assertEquals(c.cc, 2)
		self.assertEquals(d.cc, 2)
		self.assertEquals(e.cc, 1)
		self.assertEquals(f.cc, 3)
		self.assertEquals(g.cc, 3)
		self.assertEquals(h.cc, 4)
	def testSimplified(self):
		a = Vertex('a')		
		b = Vertex('b')		
		c = Vertex('c')		
		d = Vertex('d')		
		e = Vertex('e')		
		f = Vertex('f')		
		g = Vertex('g')		
		h = Vertex('h')		
		vertices = [a, b, c, d, e, f, g, h]
		#edges = [(a, c), (b, a), (d, h), (d, f), (e, a), (a, b), (b, c), (d, c), (c, d), (b, e), (e, f), (b, f), (g, f), (f, g), (c, g), (g, h), (h, h)]	
		edges = [(e, a), (a, b), (b, c), (d, c), (c, d), (b, e), (e, f), (b, f), (g, f), (f, g), (c, g), (g, h), (h, h)]	
		G = Graph(vertices, edges)
		s = G.simplified()
		for u in s.vertices:
			print "u.key: {}, u.cc: {}".format(u.key, u.cc)	
			s.printEdge(u)
		a = Vertex('a')	
		b = Vertex('b')	
		c = Vertex('c')	
		d = Vertex('d')	
		e = Vertex('e')	
		f = Vertex('f')	
		vertices = [a, b, c, d, e, f]
		edges = [(a, b), (b, a), (b, c), (b, d), (c, b), (d, b), (c, e), (b, e), (d, f), (e, f), (f, e)]
		G = Graph(vertices, edges)
		s = G.simplified()
		for u in s.vertices:
			print "u.key: {}, u.cc: {}".format(u.key, u.cc)	
			s.printEdge(u)
	def testComponentGraph(self):
		a = Vertex('a')		
		b = Vertex('b')		
		c = Vertex('c')		
		d = Vertex('d')		
		e = Vertex('e')		
		f = Vertex('f')		
		g = Vertex('g')		
		h = Vertex('h')		
		vertices = [a, b, c, d, e, f, g, h]
		edges = [(e, a), (a, b), (b, c), (d, c), (c, d), (d, h), (b, e), (e, f), (b, f), (g, f), (f, g), (c, g), (g, h), (h, h)]	
		G = Graph(vertices, edges)
		cg = G.component_graph()
		print "www"
		print
		for u in cg.vertices:
			print "u.key: {}".format(u.key)	
			cg.printEdge(u)
		a = Vertex('a')	
		b = Vertex('b')	
		c = Vertex('c')	
		d = Vertex('d')	
		e = Vertex('e')	
		f = Vertex('f')	
		vertices = [a, b, c, d, e, f]
		edges = [(a, b), (b, a), (b, c), (b, d), (c, b), (d, b), (c, e), (b, e), (d, f), (e, f), (f, e)]
		G = Graph(vertices, edges)
		cg = G.component_graph()
		print "www"
		print
		for u in cg.vertices:
			print "u.key: {}".format(u.key)	
			cg.printEdge(u)
	def testSemiconnected(self):
		a = Vertex('a')		
		b = Vertex('b')		
		c = Vertex('c')		
		d = Vertex('d')		
		e = Vertex('e')		
		f = Vertex('f')		
		g = Vertex('g')		
		h = Vertex('h')		
		vertices = [a, b, c, d, e, f, g, h]
		edges = [(e, a), (a, b), (b, c), (d, c), (c, d), (d, h), (b, e), (e, f), (b, f), (g, f), (f, g), (c, g), (g, h), (h, h)]	
		G = Graph(vertices, edges)
		self.assertEquals(G.semiconnected(), True)
		a = Vertex('a')	
		b = Vertex('b')	
		c = Vertex('c')	
		d = Vertex('d')	
		e = Vertex('e')	
		f = Vertex('f')	
		vertices = [a, b, c, d, e, f]
		edges = [(a, b), (b, a), (b, c), (b, d), (c, b), (d, b), (c, e), (b, e), (d, f), (e, f), (f, e)]
		G = Graph(vertices, edges)
		self.assertEquals(G.semiconnected(), True)
		edges = [(a, b), (b, a), (b, c), (b, d), (c, b), (d, b), (e, f)]
		G = Graph(vertices, edges)
		self.assertEquals(G.semiconnected(), False)
		abe = Vertex('abe')	
		cd = Vertex('cd')	
		fg = Vertex('fg')	
		h =  Vertex('h')	
		vertices = [abe, cd, fg, h]
		edges = [(abe, fg), (abe, cd), (fg, h), (cd, h), (cd, fg)]
		G = Graph(vertices, edges)
		self.assertEquals(G.semiconnected(), True)
		edges = [(abe, fg), (abe, cd), (fg, h), (cd, h)]
		G = Graph(vertices, edges)
		self.assertEquals(G.semiconnected(), False)
		edges = [(abe, fg), (abe, cd), (cd, h), (cd, fg)]
		G = Graph(vertices, edges)
		self.assertEquals(G.semiconnected(), False)
		edges = [(abe, fg), (abe, cd), (fg, h), (cd, fg)]
		G = Graph(vertices, edges)
		self.assertEquals(G.semiconnected(), True)
		edges = [(abe, cd), (fg, h), (cd, fg)]
		G = Graph(vertices, edges)
		self.assertEquals(G.semiconnected(), True)
