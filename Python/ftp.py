#!/usr/bin/python
from ftplib import FTP
import time
import sys
import subprocess
import os


files_copied=[]
files_available=[]

server_name='archivpsi.psi.ch'
user='muX'
pswd='muonX2015'
directory='/archiv/project/muX/data/muX2016/mid'
localdir='/home/frederik/tmp/Python'


def connect():
  ftp=FTP(server_name)
  ftp.login(user,pswd)
  ftp.cwd('/archiv/project/muX/data/muX2016/mid')
  print "current directory: "
  print ftp.pwd()
  return ftp

def do_ls():
  tempfilename = 'tempfile'
  cmd="ls " + localdir + "/run*mid > " + tempfilename
  #print cmd
  os.system(cmd)
  file1 = open(tempfilename,"r")
  files=[]
  for line in file1:
    tocut=localdir+'/'
    print line[:-1]
    files.append(line[:-1].split(tocut)[1])
  return files

def newfile(local,remote,ftp):
  newfiles=[]
  for f in local:
    if f in remote:
      ftp.voidcmd('TYPE I')
      remote_size = ftp.size(f)
      local_size = os.path.getsize(localdir + "/" + f)
      if local_size == remote_size:
        print str(f) + " also on remote"
      else:
        print str(f) + "also on remote but with different size"
        newfiles.append(f)
    else:
      newfiles.append(f)
  return newfiles

def upload(ftp,files):
  cut_files=files[:-1]
  for f in files:
    filename = localdir+"/"+f
    print str(filename) + " fill be copied"
    ftp.storbinary('STOR '+ os.path.basename(filename) , open(filename, 'rb'))

def main():

  ftp = connect()
  #filename="/data/muX/mid/run00769.mid"
  #ftp.storbinary('STOR '+ os.path.basename(filename) , open(filename, 'rb'))

  while(10):
    remote_files = ftp.nlst()
    local_files = do_ls()
    #print remote_files
    #print local_files
    newfiles=newfile(local_files,remote_files,ftp)
    newfiles.sort()
    if len(newfiles) > 1:
      #upload(ftp,newfiles)
      a=1
    time.sleep(10)



if __name__ == "__main__":
    main()

