//Template C++ program with root libraries
//set root outputfile data manager class



#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "TFile.h"
#include "TTree.h"
#include "DataManager.h"
#include "TRandom.h"

using namespace std;

const int nArgc =3;
char *fout_name;

int analyze_command_line (int argc, char **argv);
void tree1w();

int main(int argc, char* argv[])
{
  std::cout << "Running tensor minimizer ... " << std::endl;
  tree1w();
    return 0;
  int ret = analyze_command_line(argc, argv);
  if(ret) { return 1; }
  
  DataManager* io = new DataManager(fout_name);  
  
  delete io;
  return 0;
}
  
  
  
  
  
int analyze_command_line(int argc, char **argv)
{
  if(argc==nArgc)
  {
    for(int i=1; i<argc; /*increment in loop*/)
    {
      if(argv[i][0] != '-'){ printf("ERROR: Wrong argument %s\n",argv[i]); }
      else
      {
        if(strlen(&argv[i][1]) == 1)
        {
	  switch(argv[i][1])
          {
	    case 'o':
	      if(i+1 < argc)
              {
	        fout_name = argv[i+1];
	        i+=2;
	      }
              else
              {
	        printf("ERROR: No argument for output file specified\n");
	      }
              break;

             default:
	     printf("Argument %s not recognized\n",argv[i]);
             return 1;
          }
        }
      }
    }
  }
  else
  {
    cout << " use as ./Program -o outputfile" << endl;
    return 1;
  }
  return 0;
}

void tree1w()
{
   //create a Tree file tree1.root
   //create the file, the Tree and a few branches
   TFile f("tree1.root","recreate");
   TTree t1("t1","a simple Tree with simple variables");
   Float_t px, py, pz;
   Double_t random;
   Int_t ev;
   t1.Branch("px",&px,"px/F");
   t1.Branch("py",&py,"py/F");
   t1.Branch("pz",&pz,"pz/F");
   t1.Branch("random",&random,"random/D");
   t1.Branch("ev",&ev,"ev/I");
   //fill the tree
   for (Int_t i=0;i<50000000;i++) {
     gRandom->Rannor(px,py);
     pz = px*px + py*py;
     random = gRandom->Rndm();
     ev = i;
     t1.Fill();
  }
  //save the Tree header. The file will be automatically closed
  //when going out of the function scope
  t1.Write();
}
