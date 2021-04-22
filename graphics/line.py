#!/usr/bin/python

from graphics import *

def main():

	print "Enter 2 points:"

	x1 = float(input("x1: ")) 
	y1 = float(input("y1: "))
	x2 = float(input("x2: "))
	y2 = float(input("y2: "))

	win = GraphWin("LineDr", 500, 500)

	m = (y2-y1) / (x2 - x1)

	c = y1 - m * x1

	for i in range(x1, x2 + 1):

		y = m * i + c
		pt = Point(i, y)
		pt.draw(win)

main()