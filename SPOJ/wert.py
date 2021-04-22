#!/usr/bin/python

import sys

t=int(raw_input())
a=b=c=[]
for i in range(0,t) :
    x=int(raw_input())
    a=a+[x]
    y=int(raw_input())
    b=b+[y]
    z=int(raw_input())
    c=c+[z]
    
def calc(a,b,c):

    if(c==a) or (c==b): return 1

    k=1
    while (k<=(max(a,b)//min(a,b))):
        if any ([c==k*a1, c==b1-(k*a1)]): return 2*k
        k+=1
        
    return -1


for j in range (0,t):
    print calc(a[j],b[j],c[j])