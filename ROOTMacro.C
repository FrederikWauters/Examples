gROOT->Reset();
gROOT->SetStyle("Plain");

#include<iostream.h>
#include <fstream>
#include<TCanvas.h>
#include<TFile.h>
#include<TH1.h>


{
  ifstream *is = new ifstream(fname);
  if(is!=NULL) { cout << "file " << fname << " open ... " << endl; }
  else { cout << "Could not open file " << fname << " !!!" << endl; }

  //put data in a vector
  std::vector<double> values; double value;
  //loop through  read
  while(is->good())
  {
    *is >> value;
    values.push_back(value);
  }
  cout << values.size() << " values read." << endl;

}


