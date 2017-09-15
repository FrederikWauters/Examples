#!/usr/bin/python

import ctypes

def main():
        TestLib = ctypes.cdll.LoadLibrary('/home/frederik/Analysis/Examples/Python/C-interface/libfunctions.so')
        print TestLib.Print(1,"from python")

if __name__ == '__main__':
        main()
