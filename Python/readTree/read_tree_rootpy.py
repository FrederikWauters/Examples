##!/usr/bin/python2.7

import sys
from rootpy.plotting import Hist
from rootpy.tree import Tree
from rootpy.io import root_open
import time 
import array

def read_simple(f,h):    
  # open tree
  tree=f.t1
     
  for event in tree:
    h.Fill(event.gaus)  
    
def read_SetBranchAddress(f,h):
  # open tree
  tree=f.t1
  value = array.array('f', [0])
  tree.SetBranchAddress("gaus", value )
  for i in range(0, tree.GetEntries()):
    tree.GetEntry(i)
    h.Fill(value[0])
  
def main():

  start_time = time.time()
  # open file
  filename="tree.root"
  infile= root_open(filename, "read")
  if not infile.IsOpen():
    print ("does not exist, so will abort")
    return False
    
  #declare histogram
  h = Hist(200, -10, 10)
  
  #run
  #read_simple(infile,h)
  #run_time = time.time() - start_time
  #print("runtime: %s" %run_time)
  #h.Draw()
  #raw_input("Press Enter to continue...")
  
  start_time = time.time()
  read_SetBranchAddress(infile,h)
  run_time = time.time() - start_time
  print("runtime: %s" %run_time)
  h.Draw()
  raw_input("Press Enter to continue...")

if __name__ == '__main__':
  main()

