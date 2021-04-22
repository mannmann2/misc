#!/usr/bin/python

from graphics import *

dim = 500

win = GraphWin("circle2", dim)

a=[]
k=0

for i in range(dim):
	for j in range(dim):

		a.append((i,j))
		k+=1

for i in range(k):
	pt = Point(a[0], a[1])
	pt.draw(win)

# pt2 = Point(20, 100)
# pt2.draw(win)