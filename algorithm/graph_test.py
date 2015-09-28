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
		for i in r,w:
			s.addEdge(i)
		for i in s,v:
			r.addEdge(i)
		v.addEdge(r)
		for i in s,t, x:
			w.addEdge(i)
		for i in w, x, u:
			t.addEdge(i)
		for i in w, t, u, y:
			x.addEdge(i)
		for i in t, x, y:
			u.addEdge(i)
		for i in x, u:
			y.addEdge(i)
		g = Graph([v,r,s,w,t,x,u,y,z])
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
		for i in z,w:
			s.addEdge(i)
		for i in s,w:
			v.addEdge(i)
		for i in y, w:
			z.addEdge(i)
		w.addEdge(x)
		y.addEdge(x)
		x.addEdge(z)
		for i in v,u:
			t.addEdge(i)
		for i in t,v:
			u.addEdge(i)
		g = Graph([s, v, z, w, y, x, t, u])
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
		for i in q,r,x:
			m.addEdge(i)
		for i in q, o, u:
			n.addEdge(i)
		for i in r,s,v:
			o.addEdge(i)
		for i in o, s, z:
			p.addEdge(i)
		q.addEdge(t)
		for i in u, y:
			r.addEdge(i)
		s.addEdge(r)
		u.addEdge(t)
		for i in w, x:
			v.addEdge(i)
		w.addEdge(z)
		y.addEdge(v)
		g = Graph([m, n, o, p, q, r, s, t, u, v, w, x, y, z])
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
