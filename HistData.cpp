//Little macro to read a data in a text file and put it in a root histogram


gROOT->Reset();
gROOT->SetStyle("Plain");

#include<iostream.h>
#include <fstream>
#include<TCanvas.h>
#include<TFile.h>
#include<TH1.h>

using namespace std;

TH1D* h[10];

//allowing multiple entries
Int_t count = 0;



void Read_OneColumn()
{
  //Open file
  cout << "Give filename data: " << endl;
  char fname[1024];
  cin >> fname;

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

  Add_Histogram(0.,(double)values.size(),values);
  Draw_Histograms();
}

void Read_TwoColumn()
{

  //Open file
  cout << "Give filename data: " << endl;
  char fname[1024];
  cin >> fname;

  ifstream *is = new ifstream(fname);
  if(is!=NULL) { cout << "file " << fname << " open ... " << endl; }
  else { cout << "Could not open file " << fname << " !!!" << endl; }

  //put data in a vector
  std::vector<double> values; double value;
  std::vector<double> xvalues; double xvalue;
  //loop through  read
  while(is->good())
  {
    *is >> xvalue;
    *is >> value;
    values.push_back(value);
    xvalues.push_back(xvalue);
    cout << value << "  " << xvalue << endl;
  }
  //cout << values.size() << " values read." << endl;

  Add_Histogram(xvalues.at(0),xvalues.at(values.size()),values);

}


void Add_Histogram(double xMin, double xMax, std::vector<double> values)
{
  count++;

  h[count-1] = new TH1D(Form("hData%02d",count),"data",20,3,4);

  for(int i = 0; i < values.size(); i++)
  {
    //h[count-1]->SetBinContent(i+1,values.at(i));
    h[count-1]->Fill(values.at(i));
  }
  h[count-1]->SetLineColor(count);
  cout << "Histogram nr. " << count << " constructed." << endl;
}

void Draw_Histograms()
{
  h[0]->Draw();
  if(count > 1)
  {
    for(int i = 1; i < count; i++)
    {
      h[i]->Draw("SAME");
    }
  }

}

