#!/usr/bin/python

import ctypes

def main():
        TestLib = ctypes.cdll.LoadLibrary('/home/frederik/Analysis/Examples/Python/C-interface/libfunctions.so')
        return_value = TestLib.Print(1,"from python")
	print "return_value = " + str(return_value)

if __name__ == '__main__':
        main()
