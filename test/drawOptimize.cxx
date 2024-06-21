
void drawOptimize(){
  
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
  

  TH1F* h_LS = new TH1F("h_LS", "h_LS", 1000, 0, 1000 );
  
  
  TH2F* h_all = new TH2F("h_all", "all", 3,0,3, 2000,0,2000 );
  TH2F* h_all_normalized = new TH2F("h_all_normalized", "all normalized", 3,0,3, 100,0,1.1 );
  TH1F* h_all_ratio = new TH1F("h_all_ratio", "all ratio",300,0,100.0 );
  TH1F* h_all_ratio2 = new TH1F("h_all_ratio2", "all ratio 2/3", 900,0,100.0 );
  TH2F* h2_all_ratio = new TH2F("h2_all_ratio", "all ratio", 400,0,40.0 ,  400,0,40.0 );
  
  TH2F* h_one = new TH2F("h_one", "one", 3,0,3, 2000,0,2000 );
  TH2F* h_one_normalized = new TH2F("h_one_normalized", "one normalized", 3,0,3, 100,0,1.1 );
  TH1F* h_one_ratio = new TH1F("h_one_ratio", "one ratio", 300,0,100.0 );
  TH1F* h_one_ratio2 = new TH1F("h_one_ratio2", "one ratio 2/3", 300,0,100.0 );
  TH2F* h2_one_ratio = new TH2F("h2_one_ratio", "one ratio", 100,0,40.0 ,  100,0,40.0 );
  
  //   static const int IX_MIN = 1;
  //   static const int IY_MIN = 1;
  //   static const int IX_MAX = 40;
  //   static const int IY_MAX = 40;
  //   static const int ISTRIP_MIN = 1;
  //   static const int ISTRIP_MAX = 32;
  //   static const int PLANE_MIN = 1;
  //   static const int PLANE_MAX = 2;
  //   static const int IZ_NUM = 2;
  
  
//   
//   w0:w1:w2 = 0 : 0.7381 : 0.4667
//   0.7381 / 0.4667
//   (double) 1.5815299
//   
  
  
  int max_entries = mytree->GetEntries(); // 4000; // total = 84069
//   mytree->GetEntries()
// for (int iEvent=0; iEvent<max_entries; iEvent++) {
  
  for (int iEvent=0; iEvent<max_entries; iEvent++) {
    mytree->GetEntry(iEvent);
    
    if (lumi > 35) continue; // only first period of fill, with beamspot at ~ 0
    
    h_LS->Fill(lumi);
    
//     std::cout << " ES_num = " << ES_num << std::endl;
    
    for (int iES=0; iES<ES_num; iES++) {
      h_all->Fill (0., 1. * digi_ES_1[iES]);
      h_all->Fill (1., 1. * digi_ES_2[iES]);
      h_all->Fill (2., 1. * digi_ES_3[iES]);
      
      if (digi_ES_2[iES] > 5) {
        h_all_normalized->Fill (0., 1. * digi_ES_1[iES] / digi_ES_2[iES] );
        h_all_normalized->Fill (1., 1. * digi_ES_2[iES] / digi_ES_2[iES] );
        h_all_normalized->Fill (2., 1. * digi_ES_3[iES] / digi_ES_2[iES] );
      }
      
      
      if (digi_ES_2[iES] > 5) {
        h_all_ratio->Fill (1. * digi_ES_2[iES] / digi_ES_1[iES] );
        h_all_ratio2->Fill (1. * digi_ES_2[iES] / digi_ES_3[iES] );
       }
      
      if (digi_ES_2[iES] > 5 && digi_ES_2[iES] < 40) {
        h2_all_ratio->Fill (1. * digi_ES_2[iES] / digi_ES_1[iES] , 1. * digi_ES_2[iES] / digi_ES_3[iES] );
      }
      
      
      if (ES_ix[iES] == 12 && ES_iy[iES] == 10 &&  ES_plane[iES] == 1 && ES_zside[iES] == 1) {
//       if (ES_ix[iES] == 10 && ES_iy[iES] == 10 && ES_strip[iES] == 10 &&  ES_plane[iES] == 1 && ES_zside[iES] == 1) {
        h_one->Fill (0., 1. * digi_ES_1[iES]);
        h_one->Fill (1., 1. * digi_ES_2[iES]);
        h_one->Fill (2., 1. * digi_ES_3[iES]);
        
        if (digi_ES_2[iES] < 30) {
          h_one_normalized->Fill (0., 1. * digi_ES_1[iES] / digi_ES_2[iES] );
          h_one_normalized->Fill (1., 1. * digi_ES_2[iES] / digi_ES_2[iES] );
          h_one_normalized->Fill (2., 1. * digi_ES_3[iES] / digi_ES_2[iES] );
        }
        
        if (digi_ES_2[iES] < 1000) {
          h_one_ratio->Fill (1. * digi_ES_2[iES] / digi_ES_1[iES] );
          h_one_ratio2->Fill (1. * digi_ES_2[iES] / digi_ES_3[iES] );
        }
        
        if (digi_ES_2[iES] < 1000) {
          h2_one_ratio->Fill (1. * digi_ES_2[iES] / digi_ES_1[iES] , 1. * digi_ES_2[iES] / digi_ES_3[iES] );
        }
        
        
        
      }
      
      
    }
    
  }
  
  
  h_all-> Draw ("colz");
  
  h_all->GetXaxis()->SetTitle("num sample");
  h_all->GetYaxis()->SetTitle("ADC");
  
  
  TCanvas* ccNorm = new TCanvas ("ccNorm", "", 800, 600);
  
  h_all_normalized-> Draw ("colz");
  
  h_all_normalized->GetXaxis()->SetTitle("num sample");
  h_all_normalized->GetYaxis()->SetTitle("ADC");


  
  
  TCanvas* ccNorm_one = new TCanvas ("ccNorm_one", "", 800, 600);
  
  h_one_normalized-> Draw ("colz");
  
  h_one_normalized->GetXaxis()->SetTitle("num sample");
  h_one_normalized->GetYaxis()->SetTitle("ADC");

  
  
  TCanvas* cc_one = new TCanvas ("cc_one", "", 800, 600);
  
  h_one-> Draw ("colz");
  
  h_one->GetXaxis()->SetTitle("num sample");
  h_one->GetYaxis()->SetTitle("ADC");

  
  
  
  
  
  
  
  
  TCanvas* ccRatio = new TCanvas ("ccRatio", "", 800, 600);
  
  h_all_ratio-> Draw ();
  
  h_all_ratio->GetXaxis()->SetTitle("ratio 1/0");
  h_all_ratio->GetYaxis()->SetTitle("Events");
  
  
  
  
  TCanvas* ccRatio_one = new TCanvas ("ccRatio_one", "", 800, 600);
  
  h_one_ratio-> Draw ();
  
  h_one_ratio->GetXaxis()->SetTitle("ratio 1/0");
  h_one_ratio->GetYaxis()->SetTitle("Events");
  
  


  
  TCanvas* ccRatioPost_one = new TCanvas ("ccRatioPost_one", "", 800, 600);
  
  h_one_ratio2-> Draw ();
  
  h_one_ratio2->GetXaxis()->SetTitle("ratio 1/2");
  h_one_ratio2->GetYaxis()->SetTitle("Events");
  
  
  
  
  TCanvas* ccRatioPost_all = new TCanvas ("ccRatioPost_all", "", 800, 600);
  
  h_all_ratio2-> Draw ();
  
  h_all_ratio2->GetXaxis()->SetTitle("ratio 1/2");
  h_all_ratio2->GetYaxis()->SetTitle("Events");
  
  
  
  
  
  
  TCanvas* ccRatio2_one = new TCanvas ("ccRatio2_one", "", 800, 600);
  
  h2_one_ratio-> Draw ("colz");
  
  h2_one_ratio->GetXaxis()->SetTitle("ratio 1/0");
  h2_one_ratio->GetYaxis()->SetTitle("ratio 1/2");
  
  
  
  
  TCanvas* ccRatio2_all = new TCanvas ("ccRatio2_all", "", 800, 600);
  
  h2_all_ratio-> Draw ("colz");
  
  h2_all_ratio->GetXaxis()->SetTitle("ratio 1/0");
  h2_all_ratio->GetYaxis()->SetTitle("ratio 1/2");
  
  
  TCanvas* ccLumi = new TCanvas ("ccLumi", "", 800, 600);
  
  h_LS->Draw();
  h_LS->GetXaxis()->SetTitle("LS");
  
  
  
  
  
}

