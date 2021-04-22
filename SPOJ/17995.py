#!/usr/bin/python

import sys

t=int(raw_input())

m=n=c1=c2=[]

for i in range(0,t) :
	a=int(raw_input())
	b=int(raw_input())
	c=int(raw_input())
	d=int(raw_input())
	m+=[a]
	n+=[b]
	c1+=[c]
	c2+=[d]


def cross(m,n,x,y):

	a=[[0 for p in range(m)] for p in range(n)] 
	
	for i in range(0, m):
		for j in range(0,n):
			if((i==x-j and j==y+j)or(i==x-j and j==y-j)or(i==x+j and j==y+j)or(i==x+j and j==y-j)):
				a[i][j]='*'
			else:
				a[i][j]='.'

	for i in range(0,m):
		for j in range (0,n):
			print a[i][j]
		print "\n"			

for i in range(0,t):
	cross(m[i],n[i],c1[i],c2[i])






