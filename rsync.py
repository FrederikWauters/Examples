#/usr/bin/python
#
#
# FW, March 2016
#
# script to rsync raw data to the mu3e server
# checks for new files, and sync's all closed files
#

#
# imports
#

import sys
import time
import subprocess
import os

#
# constants
#

DirectoryList=[
"/home/frederik/Documents/",
"/home/frederik/Analysis/",
"/home/frederik/geant4/user/",
"/home/frederik/data/",
"/usr/local/elog/logbooks/"
]


Server = "mu3e.kph.uni-mainz.de"
Destination = "fwauters@" + Server + ":/data/users/frederik/backup_laptop/"

#
# Methods
#

def rsync(directories):
  for directory in directories:
    subdir = directory.split("/")[-2]
    command = "rsync -ar --max-size='50M' " + str(directory)+ " " + str(Destination) + str(subdir)
    print command
    os.system(command)

def ping(hostname):
  response = os.system("ping -c 1 " + hostname)
  if response == 0:
    return True
  else:
    print "could not reach mu3e ... "
    return False
    

#
# main loop
#

def main():

  print " Running rsync.py "
  print (time.strftime("%d/%m/%Y"))
  print (time.strftime("%H:%M:%S")) 

  if ping(Server):
    print " mu3e ready "
    rsync(DirectoryList)
  time.sleep(1)          

if __name__ == "__main__":
    main()
