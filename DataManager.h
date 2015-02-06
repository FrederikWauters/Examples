#ifndef DataManager_h
#define DataManager_h


#include <string>
#include <iostream>
#include <cstring>
#include <fstream>

#include "TFile.h"

#include "TH1.h"


class DataManager {
  
  private:
  
    int SetOutputFile(char* outfile);
    void InitHistos();
    void WriteOutput();

    TFile *fout;
    TH1I* hTest;
  
  public:
  
    DataManager(char* fout);
    virtual ~DataManager();

    
  
};

#endif
