
void drawLS(){
  
  TTree* mytree = (TTree*) _file0->Get("PulseTreeProducer/tree");
  
  TCanvas* cc = new TCanvas ("cc", "", 800, 600);
  
  UInt_t          run;
  UShort_t        lumi;
  UShort_t        bx;
  UInt_t          event;
  Float_t         digi_ES_1[6000];
  Float_t         digi_ES_2[6000];
  Float_t         digi_ES_3[6000];
  Int_t           ES_zside[6000];
  Int_t           ES_plane[6000];
  Int_t           ES_ix[6000];
  Int_t           ES_iy[6000];
  Int_t           ES_strip[6000];
  
  Int_t           ES_num;
  
  
  
  mytree->SetBranchAddress("run", &run);
  mytree->SetBranchAddress("lumi", &lumi);
  mytree->SetBranchAddress("bx", &bx);
  mytree->SetBranchAddress("event", &event);
  mytree->SetBranchAddress("digi_ES_1", digi_ES_1);
  mytree->SetBranchAddress("digi_ES_2", digi_ES_2);
  mytree->SetBranchAddress("digi_ES_3", digi_ES_3);
  mytree->SetBranchAddress("ES_zside", ES_zside);
  mytree->SetBranchAddress("ES_plane", ES_plane);
  mytree->SetBranchAddress("ES_ix", ES_ix);
  mytree->SetBranchAddress("ES_iy", ES_iy);
  mytree->SetBranchAddress("ES_strip", ES_strip);
  mytree->SetBranchAddress("ES_num", &ES_num);

  TH2F* h_all_ratio2_vs_lumi = new TH2F("h_all_ratio2_vs_lumi", "all ratio 2/3", 1000, 0, 1000, 900, 0 ,20.0 );
  TH2F* h_some_ratio2_vs_lumi = new TH2F("h_some_ratio2_vs_lumi", "some ratio 2/3", 1000, 0, 1000, 900, 0 ,20.0 );


  TH2F* h_plus_ratio2_vs_lumi = new TH2F("h_plus_ratio2_vs_lumi", "plus ratio 2/3", 1000, 0, 1000, 900, 0 ,20.0 );
  TH2F* h_minus_ratio2_vs_lumi = new TH2F("h_minus_ratio2_vs_lumi", "minus ratio 2/3", 1000, 0, 1000, 900, 0 ,20.0 );
  
  //   static const int IX_MIN = 1;
  //   static const int IY_MIN = 1;
  //   static const int IX_MAX = 40;
  //   static const int IY_MAX = 40;
  //   static const int ISTRIP_MIN = 1;
  //   static const int ISTRIP_MAX = 32;
  //   static const int PLANE_MIN = 1;
  //   static const int PLANE_MAX = 2;
  //   static const int IZ_NUM = 2;
  
  std::cout << " mytree->GetEntries() = " << mytree->GetEntries() << std::endl;
  
  for (int iEvent=0; iEvent<mytree->GetEntries(); iEvent++) {
    mytree->GetEntry(iEvent);
    
//     std::cout << " ES_num = " << ES_num << std::endl;
    
    for (int iES=0; iES<ES_num; iES++) {

      if (digi_ES_2[iES] > 5) {
        h_all_ratio2_vs_lumi->Fill (lumi,   1. * digi_ES_2[iES] / digi_ES_3[iES] );
      }

      if (digi_ES_2[iES] > 5 && ((ES_ix[iES] >0 || ES_ix[iES] < 20) && (ES_iy[iES] > 5 && ES_iy[iES] < 20) &&  ES_plane[iES] == 1 && ES_zside[iES] == 1) ) {
        h_some_ratio2_vs_lumi->Fill (lumi,   1. * digi_ES_2[iES] / digi_ES_3[iES] );
      }
      
      
      if (digi_ES_2[iES] > 5 &&   ES_zside[iES] == 1 ) {
        h_plus_ratio2_vs_lumi->Fill (lumi,   1. * digi_ES_2[iES] / digi_ES_3[iES] );
      }
      
      if (digi_ES_2[iES] > 5 &&   ES_zside[iES] == -1 ) {
        h_minus_ratio2_vs_lumi->Fill (lumi,   1. * digi_ES_2[iES] / digi_ES_3[iES] );
      }
      
    }
    
  }
    
  
  
  h_all_ratio2_vs_lumi-> Draw ("colz");
  
  h_all_ratio2_vs_lumi->GetXaxis()->SetTitle("LS");
  h_all_ratio2_vs_lumi->GetYaxis()->SetTitle("Ratio 2/3");
  
  
  
  
  
  TCanvas* cc_some_ratio2 = new TCanvas ("cc_some_ratio2", "", 800, 600);
  
  h_some_ratio2_vs_lumi-> Draw ("colz");
  
  h_some_ratio2_vs_lumi->GetXaxis()->SetTitle("LS");
  h_some_ratio2_vs_lumi->GetYaxis()->SetTitle("Ratio 2/3");
  
  
  
  
  
  TCanvas* cc_plus_ratio2 = new TCanvas ("cc_plus_ratio2", "", 800, 600);
  
  h_plus_ratio2_vs_lumi-> Draw ("colz");
  
  h_plus_ratio2_vs_lumi->GetXaxis()->SetTitle("LS");
  h_plus_ratio2_vs_lumi->GetYaxis()->SetTitle("Ratio 2/3");
  
  h_plus_ratio2_vs_lumi->ProfileX()->Draw("same");
  
  
  
  TCanvas* cc_minus_ratio2 = new TCanvas ("cc_minus_ratio2", "", 800, 600);
  
  h_minus_ratio2_vs_lumi-> Draw ("colz");
  
  h_minus_ratio2_vs_lumi->GetXaxis()->SetTitle("LS");
  h_minus_ratio2_vs_lumi->GetYaxis()->SetTitle("Ratio 2/3");
  
  h_minus_ratio2_vs_lumi->ProfileX()->Draw("same");
  
  
  
  
}

