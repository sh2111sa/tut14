#include "My_class.h"
#include "ClassDef.h"
#include "My_class.cxx"

Double_t MyClass::CalculateMagnitude() {
    // Calculate the magnitude of the momentum vector
    return TMath::Sqrt(px * px + py * py + pz * pz);
}

void write() {
    // Initialize object, e.g., as a pointer
    MyClass* myObject = nullptr;

    // Create ROOT file
    TFile* rootFile = new TFile("tree_file.root", "RECREATE");

    // Create TTree
    TTree* tree = new TTree("MyTree", "My Tree Title");

    // Create associated branches
    Double_t px, py, pz; // Variables for momentum

    tree->Branch("px", &px);
    tree->Branch("py", &py);
    tree->Branch("pz", &pz);

    // Define how many events we want
    Int_t nEvents = 100;

    // For loop to fill the tree with random data
    for (Int_t i = 0; i < nEvents; i++) {
        // Initialize new object here
        myObject = new MyClass();

        // Generate random values for momentum
        px = gRandom->Gaus(0, 0.02);
        py = gRandom->Gaus(0, 0.02);
        pz = gRandom->Gaus(0, 0.02);

         // Calculate the magnitude of the momentum vector
        Double_t magnitude = myObject->CalculateMagnitude()

        // Fill the tree with the current values
        tree->Fill();

        // Deleting the object to avoid memory leaks
        delete myObject;
    }

    // Save the tree and close the file
    rootFile->Write();
    rootFile->Close();
}