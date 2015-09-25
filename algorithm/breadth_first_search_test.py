#!/usr/bin/env ipython
import unittest
from breadth_first_search import Vertex, Graph

class TestBfs(unittest.TestCase):
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
		s.printEdge()
		for i in s,v:
			r.addEdge(i)
		v.addEdge(r)
		v.printEdge()
		for i in s,t, x:
			w.addEdge(i)
		w.printEdge()
		for i in w, x, u:
			t.addEdge(i)
		t.printEdge()
		for i in w, t, u, y:
			x.addEdge(i)
		x.printEdge()
		for i in t, x, y:
			u.addEdge(i)
		u.printEdge()
		for i in x, u:
			y.addEdge(i)
		y.printEdge()
		g = Graph([v,r,s,w,t,x,u,y,z])
		g.printAllEdges()
		for i in g.vertices:
			i.printEdge()
			print
		g.bfs(s)
		g.printVertices()
		self.assertEquals(s.d, 0)
		self.assertEquals(r.d, 1)
		self.assertEquals(v.d, 2)
		self.assertEquals(w.d, 1)
		self.assertEquals(t.d, 2)
		self.assertEquals(x.d, 2)
		self.assertEquals(u.d, 3)
	 	self.assertEquals(y.d, 3)
		print
		s.print_path(s)
		print
		s.print_path(r)
		print
		s.print_path(v)
		print
		s.print_path(w)
		print
		s.print_path(t)
		print
		s.print_path(x)
		print
		s.print_path(u)
		print
		s.print_path(y)
		print
		s.print_path(z)
		g.bfs(u)
		print
		u.print_path(s)
		print
		u.print_path(r)
		print
		u.print_path(v)
		print
		u.print_path(w)
		print
		u.print_path(t)
		print
		u.print_path(x)
		print
		u.print_path(u)
		print
		u.print_path(y)
		print
		u.print_path(z)
