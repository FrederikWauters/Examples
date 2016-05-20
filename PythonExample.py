#!/usr/bin/python2.7

#arguments are random input file
#This will histogram the lengths of the lines

import sys
import numpy as np
import pylab as pl
import matplotlib.pyplot as plt

def Read(filename):
  file = open(filename,"rU")
  lengths= []
  for line in file:
    length = len(line) 
    lengths.append(length)
 
  while 1 in lengths: lengths.remove(1)
  return lengths
  
def HistAndPlot(data):
  pl.hist(data, bins=10, normed=0)       # matplotlib version (plot)
  mean = np.mean(data)
  pl.show()
  
  n, bins, patches = plt.hist(datos, 60, normed=1, facecolor='green', alpha=0.75)

  
def main():
  data = Read(sys.argv[1])
  HistAndPlot(data)
  
if __name__ == '__main__':
  main()


 
