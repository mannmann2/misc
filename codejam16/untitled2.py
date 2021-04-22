#!/usr/bin/python

import sys


f = open('B-small-attempt0.in.txt', 'r')
t= int(f.readline())


k= open('vash.txt', 'w')
sys.stdout = k

# t = int(raw_input())


for j in range(0,t):

    a = []
    flip = 0

    s = f.readline()
    print s
    # s=raw_input()

    for l in s:
        a += l

        
    for i in range(len(a)):
        if(i<len(a)-1):
            if (a[i]=='-'):
                if (a[i+1]=='+'):
                    flip += 1

            else:
                if (a[i+1]=='-'):
                    flip +=1


    if (a[len(s)-2]=='-'):
        flip += 1

    print "Case #" + str(j+1) + ": " + str(flip)


f.close()
            