

#include "DataManager.h"

using std::cout;
using std::endl;

DataManager::DataManager(char* fout)
{
  cout << "Construct data manager ... " << endl;

  if(SetOutputFile(fout)==1) cout << fout << " open ... " << endl;
  
  InitHistos();

}

//Destructor
DataManager::~DataManager()
{
  cout << "Delete data manager ... " << endl;
  WriteOutput();
}

int DataManager::SetOutputFile(char* outfile)
{
  fout = new TFile ( outfile, "ReCreate");

  if ( fout->IsZombie() ) {
    std::cerr << "**ERROR! Cannot open file [" << outfile << "]" << endl;
    return 0;
  }
  fout->cd();
  return 1;
}

void DataManager::InitHistos()
{
  hTest = new TH1I("hTest","Test histogram",10,0.5,10.5);
  hTest->SetBinContent(5,3);
}


void DataManager::WriteOutput()
{
  fout->Write();
}
