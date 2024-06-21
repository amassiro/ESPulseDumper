
void draw(){
  
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
  
    
  TH2F* h_all = new TH2F("h_all", "all", 3,0,3, 2000,0,2000 );
  
  for (int iEvent=0; iEvent<mytree->GetEntries(); iEvent++) {
    mytree->GetEntry(iEvent);
    
    std::cout << " ES_num = " << ES_num << std::endl;
    
    for (int iES=0; iES<ES_num; iES++) {
      h_all->Fill (0., 1. * digi_ES_1[iES]);
      h_all->Fill (1., 1. * digi_ES_2[iES]);
      h_all->Fill (2., 1. * digi_ES_3[iES]);
      
    }
    
  }
  
  
  h_all-> Draw ("colz");
  
  h_all->GetXaxis()->SetTitle("num sample");
  h_all->GetYaxis()->SetTitle("ADC");
  
  
}

