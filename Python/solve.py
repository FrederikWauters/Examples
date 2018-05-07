#!/usr/bin/python

from scipy.optimize import fsolve
import numpy as np
import math
import matplotlib.pyplot as plt

def y(a,b,x):
  return a*x+b*x*x+math.sqrt(x*x-b)
  
a = 2
b = 3

result = y(a,b,4)
print "for x = 4 , y = " + str(result)

#recover x

func = lambda x : result - y(a,b,x)
solution = fsolve(func, 2)

print "solving y for x with y = " + str(result) + " yields " + str(solution[0])


