gROOT->Reset();

#include<iostream.h>
#include<TCanvas.h>
#include<TGraph.h>
#include<TGraphErrors.h>


void main()
{

const Int_t nP1 = 2;
Double_t x1[nP1]={0.25,1};
Double_t y1[nP1]={9.7,12};
TGraph *g1 = new TGraph(nP1,x1,y1);

const Int_t nP2 = 2;
Double_t x2[nP2]={0.25,1};
Double_t y2[nP2]={8.8,7.6};
TGraph *g2 = new TGraph(nP2,x2,y2);
TGraph *g2b = new TGraph(nP2,y1,y2);


const Int_t nP3 = 4;
Double_t x3[nP3]={0.24,0.5,1,2};
Double_t y3[nP3]={7.7,6.6,6.7,7.9};
TGraph *g3 = new TGraph(nP3,x3,y3);


const Int_t nP4 = 5;
Double_t x4[nP4]={60,356,835,1173,1332};
Double_t x4Err[nP4]={0.2,0.2,0.2,0.2,0.2};
Double_t y4[nP4]={6.9,26,45,41,45};
Double_t y4Err[nP4]={0.3,4,2,4,2};
TGraphErrors *g4 = new TGraphErrors(nP4,x4,y4,x4Err,y4Err);
 g4->Draw("ap");
//Plot(g4);

//PlotMG(g1,g2,g3,g4);
//PlotMG(g1,g2);

//PlotMR(g1,g2);

}

void Plot(TGraph *g)
{
  g->Draw("alp");
}

void PlotMG(TGraph * g1,TGraph * g2,TGraph * g3,TGraph * g4)
{
  TCanvas *c1 = new TCanvas("c1","Multigraph",800,800);
  c1->cd();
  //gPad->SetGridx();
  //gPad->SetGridy();

  TMultiGraph *mg = new TMultiGraph();
  mg->Add(g1,"lp");
  mg->Add(g2,"lp");
  mg->Add(g3,"lp");
  mg->Add(g4,"lp");
  mg->Draw("A");
}

void PlotMG(TGraph * g1,TGraph * g2)
{
  TCanvas *c1 = new TCanvas("c1","Multigraph",800,800);
  c1->cd();
  //gPad->SetGridx();
  //gPad->SetGridy();

  TMultiGraph *mg = new TMultiGraph();
  mg->Add(g1,"lp");
  mg->Add(g2,"lp");
  mg->Draw("A");
}


void PlotMR(TGraph * g1,TGraph * g2)
{

gROOT->SetStyle("Plain");
//gStyle->SetTitleFontSize(0.5);
gStyle->SetTitleOffset(0.9,"y");
gStyle->SetTitleOffset(0.8,"x");
gStyle->SetTitleSize(0.05,"xy");
gStyle->SetLabelSize(0.045,"xy");

  c1 = new TCanvas("c1","MultiGraph",100,10,700,500);
//c1->SetBorderMode(0);
  c1->SetFillColor(kWhite);
  TPad *pad = new TPad("pad","",0,0,1,1);
  pad->SetFillColor(0);
  gPad->UseCurrentStyle();
//   pad->SetGrid();
   pad->Draw();
   pad->cd();


// draw a frame to define the range

  TH1F *hr = c1->DrawFrame(1,10,3.4,30);
  hr->SetYTitle("Kicked muon rate (kHz)");
  //hr->GetYaxis()->SetTitleSize(0.06);
  //hr->GetYaxis()->SetTitleOffSet(0.70);
  //hr->GetXaxis()->SetLabelSize(0.044);
  hr->SetXTitle("dp/p (%)");
  //hr->SetTitleSize(0.05);
  pad->GetFrame()->SetFillColor(0);

  pad->SetFillStyle(1001);
//pad->GetFrame()->SetBorderColor(0);
  pad->GetFrame()->SetBorderSize(0);
  


  g1->SetMarkerColor(1);
  g1->SetMarkerStyle(21);
  g1->SetMarkerSize(1.5);
 


  g1->Draw("LP");


  TPad *overlay = new TPad("overlay","",0,0,1,1);

  overlay->SetFillStyle(4000);
  overlay->SetFillColor(0);
  overlay->SetFrameFillStyle(0);
  //overlay->SetTickx(0);
  overlay->SetTicky(0);
  overlay->Draw();
  overlay->cd();

  g2->SetMarkerColor(12);
  g2->SetMarkerSize(1.5);
  g2->SetLineColor(12);
  g2->SetMarkerStyle(20);
  g2->SetName("gr2");
  
  Double_t xmin = pad->GetUxmin();
  Double_t ymin = 45;
  Double_t xmax = pad->GetUxmax();
  Double_t ymax = 85;
  TH1F *hframe = overlay->DrawFrame(xmin,ymin,xmax,ymax);
  hframe->GetXaxis()->SetLabelOffset(99);  
  hframe->GetYaxis()->SetLabelOffset(99);    
  g2->Draw("LP");

   //Draw an axis on the right side
   TGaxis *axis = new TGaxis(xmax,ymin,xmax, ymax,ymin,ymax,510,"+L");

   axis->SetLineColor(12);
   axis->SetLabelColor(12);
   axis->SetTitleColor(12);
   axis->SetTitleSize(0.05);
   axis->SetLabelSize(0.044);


  axis->SetTitle("FWHM #\mu stop distribution in z (mm)");
  g2->GetYaxis()->RotateTitle(180);
  axis->Draw();


} 

