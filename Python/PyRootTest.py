#!/usr/bin/python2.7

import sys
from ROOT import TCanvas, TF1
import time 

def main():
  c1 = TCanvas( 'c1', 'Example with Formula', 200, 10, 700, 500 )
 
  #
  # Create a one dimensional function and draw it
  #
  fun1 = TF1( 'fun1', 'x*1/(sqrt(1-x*x))', 0, 0.99999 )
  fun1.SetNpx(10000)
  c1.SetGridx()
  c1.SetGridy()
  fun1.Draw()
  c1.Update()
  
  raw_input("Press Enter to continue...")
  


if __name__ == '__main__':
  main()


 
