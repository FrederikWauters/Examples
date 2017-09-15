##!/usr/bin/python2.7

import sys
from ROOT import TCanvas, TF1, TH1, TFile, TH1F
import time 
import array

def read_simple(f,h):    
  # open tree
  treename="t1"
  tree=f.Get(treename)
     
  for event in tree:
    h.Fill(event.gaus)  
    
def read_SetBranchAddress(f,h):
  # open tree
  treename="t1"
  tree=f.Get(treename)
  value = array.array('f', [0])
  tree.SetBranchAddress("gaus", value )
  for i in range(0, tree.GetEntries()):
    tree.GetEntry(i)
    h.Fill(value[0])
  
def main():

  start_time = time.time()
  # open file
  filename="tree.root"
  infile=TFile(filename,"READ")
  if not infile.IsOpen():
    print ("does not exist, so will abort")
    return False
    
  #declare histogram
  h = TH1F("h", "h", 200, -10, 10)
  
  #run
  read_simple(infile,h)
  run_time = time.time() - start_time
  print("runtime: %s" %run_time)
  h.Draw()
  raw_input("Press Enter to continue...")
  
  start_time = time.time()
  read_SetBranchAddress(infile,h)
  run_time = time.time() - start_time
  print("runtime: %s" %run_time)
  h.Draw()
  raw_input("Press Enter to continue...")

if __name__ == '__main__':
  main()

