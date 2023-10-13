/* 
   In this ROOT function we generate a distribution according to sin(x)
   between 0 and pi

   To run do:
   root 
   .L rootgenerate_sinx.C 
   rootfuncgenerate(10000)
*/

// include C++ STL headers 
/*#include <iostream>

using namespace std;

// ROOT library obejcts
#include <TF1.h> // 1d function class
#include <TH1.h> // 1d histogram classes
#include <TStyle.h>  // style object
#include <TMath.h>   // math functions
#include <TCanvas.h> // canvas object

void rootfuncgenerate(Int_t nEvents,Double_t v2); // ROOT method (a bit dangerous since we don't know exactly what happens!)


//________________________________________________________________________
void rootfuncgenerate(Int_t nEvents,Double_t v2) 
{
  
  cout << "Generating " << nEvents << " events" << endl << endl;

  // create histogram that we will fill with random values
  TH1D* hphi = new TH1D("hphi", "ROOT func generated v2 distribution; x; Counts", 100, 0, TMath::Pi());

  // Define the function we want to generate
  //TF1* sinFunc = new TF1("sinFunc", "sin(x)", 0, TMath::Pi());
  TF1* y= new TF1("y", "1+ [0]*cos(2*x)", 0, TMath::Pi());
   y->SetParameter(0,v2);
  // make a loop for the number of events
  for(Int_t n = 0; n < nEvents; n++) {
    
    if((n+1)%1000==0)
      cout << "event " << n+1 << endl;
    
    // fill our sin dist histogram
    hphi->Fill(y->GetRandom()); 
  }
  
  // Set ROOT drawing styles
  gStyle->SetOptStat(1111);
  gStyle->SetOptFit(1111);

  // create canvas for hSin
  TCanvas* c1 = new TCanvas("c1", "v2 canvas", 900, 600);
  hphi->SetMinimum(0);
  hphi->Draw();
  
  // create 1d function that we will use to fit our generated data to ensure
  // that the generation works
  TF1* fitFunc = new TF1("fitFunc", "[0]*(1+ [1]*cos(2*x))", 0, TMath::Pi());
  fitFunc->SetParameter(1,v2);
  fitFunc->SetParameter(0, 10);
  fitFunc->SetLineColor(kRed);
  hphi->Fit(fitFunc);
  
  // Save the canvas as a picture
  c1->SaveAs("v2_rootfunc.jpg");
}*/






#include <iostream>

using namespace std;

// ROOT library obejcts
#include <TF1.h> // 1d function class
#include <TH1.h> // 1d histogram classes
#include <TStyle.h>  // style object
#include <TMath.h>   // math functions
#include <TCanvas.h> // canvas object

void rootfuncgenerate(Int_t nEvents,Int_t nTracks,Double_t v2); // ROOT method (a bit dangerous since we don't know exactly what happens!)


//________________________________________________________________________
void rootfuncgenerate(Int_t nEvents,Int_t nTracks,Double_t v2) 
{
  
  cout << "Generating " << nEvents << " events" << endl << endl;

  // create histogram that we will fill with random values
  TH1D* hphi = new TH1D("hphi", "ROOT func generated v2 distribution; x; Counts", 100, 0, TMath::Pi());

  // Define the function we want to generate
  //TF1* sinFunc = new TF1("sinFunc", "sin(x)", 0, TMath::Pi());
  TF1* y= new TF1("y", "1+ [0]*cos(2*x)", 0, TMath::Pi());
   y->SetParameter(0,v2);

  // make a loop for the number of events
  for(Int_t n = 0; n < nEvents; n++) { 
        Double_t phi[nTracks]; // array to store phi angles
cout << "Event" << n << endl;
// generate nTracks phi angles
           for (Int_t nt = 0; nt < nTracks; nt++) {
          // Fill the array
             phi[nt] = (y->GetRandom());
             cout << "Tracks" << nTracks << endl;
                                                   }

           for(Int_t i = 0; i < nTracks; i++) {
             hphi->Fill(phi[i]);
                                              }
                                       }
//for(Int_t n = 0; n < nEvents; n++) { 



  
  // Set ROOT drawing styles
  gStyle->SetOptStat(1111);
  gStyle->SetOptFit(1111);

  // create canvas for hSin
  TCanvas* c1 = new TCanvas("c1", "v2 canvas", 900, 600);
  hphi->SetMinimum(0);
  hphi->Draw();
  
  // create 1d function that we will use to fit our generated data to ensure
  // that the generation works
  TF1* fitFunc = new TF1("fitFunc", "[0]*(1+ [1]*cos(2*x))", 0, TMath::Pi());
  fitFunc->SetParameter(1,v2);
  fitFunc->SetParameter(0, 10);
  fitFunc->SetLineColor(kRed);
  hphi->Fit(fitFunc);
  
  // Save the canvas as a picture
  c1->SaveAs("v2_rootfunc.jpg");

 // open output file
ofstream file("phi_dist.dat");
// write to file
//file << "Event " << ne << endl
for (Int_t bin = 1; bin <= hphi->GetNbinsX(); bin++) {
    Double_t binCenter = hphi->GetBinCenter(bin);
    Double_t binContent = hphi->GetBinContent(bin);
    file << binCenter << " " << binContent << endl;
  }

// close file
file.close();
}