#!/usr/bin/python2.6
#hadd files from a list which are present in a directory
#usage ./HaddList.py dataset group_hadd_jobs_by

import sys
import subprocess
import os
import fileinput
import ROOT
import time



def MakeFileList(filename):
  f = open(filename,'rU')
  filenames=[]

  #generate a list of files which are actually present in the directory
  for line in f:
    command_arg = 'ls ' +'*'+line[:-1]+'*'
    proc = subprocess.Popen(command_arg, shell=True,stdout=subprocess.PIPE)
    proc.wait()
    name,err = proc.communicate()
    if(len(name[:-1]) >0): filenames.append(name[:-1])
    
  return filenames





def Hadd_files(filenames,filename,ngroup):

  # make a dictionary with files for 1 hadd job
  jobs={}
  grp_mod = int(ngroup)
  groups_length = (len(filenames)/grp_mod) + 1
  #print filenames

  for i in range(grp_mod):
    jobs[i]=filenames[i*groups_length:(1+i)*groups_length]
  
  
  print len(jobs), "hadd jobs waiting to be processed"
  start_time = time.time()

  # launch ngroup hadd jobs in parallel
  cmds=[]
  hadd_files=[]
  processes=[]
  for i in range(grp_mod):
    files_to_add = ' '.join(jobs[i])
    if(len(files_to_add) > 1):
      hadd_filename = "hadd" + str(i) +".root"
      cmds.append("hadd " + hadd_filename + " " + files_to_add)
      hadd_files.append(hadd_filename)
      print cmds[i]
      processes.append(subprocess.Popen(cmds[i], shell=True))

  # wait until they are done
  exit_codes = [p.wait() for p in processes]
  print hadd_files

  #do the final adding
  hadd_files_string = ' '.join(hadd_files)
  cmd = "hadd hadd.root " + hadd_files_string
  print cmd
  os.system(cmd)

  #mv the sum file to a custom file name
  cmd = "mv hadd.root " + filename[:-3] + "root"
  print cmd
  os.system(cmd) 

  #remove all temporary hadd files. "hadd" doesnt like target files which already exist
  cmd = "rm hadd.root " + hadd_files_string
  print cmd
  os.system(cmd)

  process_time = time.time() - start_time
  print "hadd finished, this took ", process_time, " s"
  print " sum file =  " , filename[:-3], "root"

  

 


    

def main():
  if len(sys.argv) != 3:
    print 'usage ./HaddList.py dataset nJobs'
    sys.exit(1)
  
  if(int(sys.argv[2])>4):
    print "don`t ask for more than 4 parallel processes"
  
  filenames = MakeFileList(sys.argv[1])
  print len(filenames), "files waiting to be processed"

  Hadd_files(filenames,sys.argv[1],sys.argv[2])
  



if __name__ == '__main__':
  main()
