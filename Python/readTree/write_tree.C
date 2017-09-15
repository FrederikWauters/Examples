#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH2.h"
#include "TRandom.h"
#include "TRandom3.h"

void tree1w()
{
   //create the file, the Tree and a few branches
   TFile f("tree.root","recreate");
   TTree t1("t1","a simple Tree with simple variables");
   Float_t px, py, pz;
   Double_t random;
   Int_t ev;
   Float_t gaus;
   t1.Branch("px",&px,"px/F");
   t1.Branch("py",&py,"py/F");
   t1.Branch("pz",&pz,"pz/F");
   t1.Branch("random",&random,"random/D");
   t1.Branch("ev",&ev,"ev/I");
   t1.Branch("gaus",&gaus,"gaus/F");

   TRandom r;
   //fill the tree
   for (Int_t i=0;i<5000000;i++) 
   {
     gRandom->Rannor(px,py);
     pz = px*px + py*py;
     random = gRandom->Rndm();
     ev = i;
     gaus = r.Gaus(3,2);
     t1.Fill();
   }
  f.Write();
}
     
