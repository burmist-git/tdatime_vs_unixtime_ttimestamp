/***********************************************************************
* Copyright(C) 2019 - LBS - (Single person developer.)                 *
* Thu Apr 25 13:57:52 JST 2019                                         *
* Autor: Leonid Burmistrov                                             *
***********************************************************************/

//c, c++
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <time.h>

//root
#include <TTree.h>
#include <TFile.h>
#include <TDatime.h>
#include <TTimeStamp.h>

using namespace std;

void tDatime_vs_unixTime_tTimeStamp (TString outRootFile) {

  //cout<<"tDatime_vs_unixTime_tTimeStamp"<<endl;

  Int_t ut = time(0);
  UInt_t rdt = TDatime().Convert(); ;
  auto t=new TTimeStamp();
  Int_t tts = t->GetSec();

  cout<<"TDatime     ut "<<ut<<endl
      <<"Unix Time  rdt "<<rdt<<endl
      <<"TTimeStamp tts "<<tts<<endl;
  
  TFile *hfile = new TFile( outRootFile, "UPDATE", "TDatime vs Unix Time vs TTimeStamp", 1);
  if (hfile->IsZombie()) {
    std::cout << "PROBLEM with the initialization of the output ROOT ntuple " 
         << outRootFile << ": check that the path is correct!!!"
         <<std::endl;
    assert(0);
  }
  //
  TTree *tree;
  if(!(TTree*)hfile->Get("T")){
    //cout<<" FIRST TIME"<<endl;
    tree = new TTree("T", "pc stat log tree");
    tree->Branch("ut",&ut, "ut/I");
    tree->Branch("rdt",&rdt, "rdt/i");
    tree->Branch("tts",&tts, "tts/I");
  }
  else {
    //cout<<" NOT FIRST TIME"<<endl;
    tree = (TTree*)hfile->Get("T");
    tree->SetBranchAddress("ut",&ut);
    tree->SetBranchAddress("rdt",&rdt);
    tree->SetBranchAddress("tts",&tts);
  }
  //
  hfile->SetCompressionLevel(2);
  tree->SetAutoSave(1000000);
  // Create new event
  TTree::SetBranchStyle(0);
  tree->Fill();
  hfile->Write();
  hfile->Close(); 
}

int main(int argc, char *argv[]) {
  if(argc == 2 && atoi(argv[1]) == 0 ){
    //cout<<"argv[0] = "<<argv[0]<<endl
    //	<<"argv[1] = "<<argv[1]<<endl;
    TString outRootFile = argv[0]; outRootFile += ".root";
    tDatime_vs_unixTime_tTimeStamp(outRootFile);
  }
  else{
    std::cout<<" ---> ERROR in input arguments "<<std::endl;
    assert(0);
  }
  return 0;
}
