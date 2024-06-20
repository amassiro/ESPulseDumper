// -*- C++ -*-
//
// Package:    ECALValidation/ESPulseDumper
// Class:      ESPulseDumper
//
/**\class ESPulseDumper ESPulseDumper.cc ECALValidation/ESPulseDumper/plugins/ESPulseDumper.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Andrea Massironi
//         Created:  Tue, 18 Jun 2024 13:33:02 GMT
//
//

// system include files
#include <memory>

// std::cout
#include <iostream>


// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
// #include "DataFormats/TrackReco/interface/Track.h"
// #include "DataFormats/TrackReco/interface/TrackFwd.h"


#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/ESGetToken.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"


#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "TTree.h"


//
// ECAL / ES specific
//

#include "DataFormats/EcalDigi/interface/ESDataFrame.h"
#include "DataFormats/EcalDigi/interface/EcalDigiCollections.h"


//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<>
// This will improve performance in multithreaded jobs.

// using reco::TrackCollection;

class ESPulseDumper : public edm::one::EDAnalyzer<edm::one::SharedResources> {
public:
  explicit ESPulseDumper(const edm::ParameterSet&);
  ~ESPulseDumper() override;

  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

private:
  void beginJob() override;
  void analyze(const edm::Event&, const edm::EventSetup&) override;
  void endJob() override;

  // ----------member data ---------------------------
  
  edm::EDGetTokenT<ESDigiCollection> _token_ESdigiCollection;
//   edm::EDGetTokenT<ESDigiCollection> ESdigiCollectionToken_;
  
  
//   edm::EDGetTokenT<EcalUncalibratedRecHitCollection> _token_ebrechits;
//   edm::EDGetTokenT<EcalUncalibratedRecHitCollection> _token_eerechits;
//   
//   edm::EDGetTokenT<EcalUncalibratedRecHitCollection> _token_second_ebrechits;
//   edm::EDGetTokenT<EcalUncalibratedRecHitCollection> _token_second_eerechits;
//   
//   edm::EDGetTokenT<EBDigiCollection> _token_ebdigi;
//   edm::EDGetTokenT<EEDigiCollection> _token_eedigi;
  
  
  
//   const EcalPedestals* _peds;
  
  
  TTree *_outTree;
  
  UInt_t _run;
  UShort_t _lumi;
  UShort_t _bx;
  UShort_t _event;      
  
  
//   float _time_EB[61200];
  
  float _digi_ES_1[6000]; // 6000 (estimate)
  float _digi_ES_2[6000]; // 6000 (estimate)
  float _digi_ES_3[6000]; // 6000 (estimate)
  
  int _ES_zside[6000]; // 
  int _ES_plane[6000]; // 
  int _ES_ix[6000]; // 
  int _ES_iy[6000]; // 
  int _ES_strip[6000]; // 
  
  int _ES_num; // 
  
  
  
  
// //   edm::EDGetTokenT<TrackCollection> tracksToken_;  //used to select what tracks to read from configuration file
// #ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
//   edm::ESGetToken<SetupData, SetupRecord> setupToken_;
// #endif
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
ESPulseDumper::ESPulseDumper(const edm::ParameterSet& iConfig) {

  //now do what ever initialization is needed
  usesResource("TFileService");
  
  
  //now do what ever initialization is needed
  usesResource("TFileService");
  edm::Service<TFileService> fs;
  
  _token_ESdigiCollection = consumes<ESDigiCollection>(iConfig.getParameter<edm::InputTag>("ESdigiCollection"));
  
//   
//   _token_ebrechits = consumes<EcalUncalibratedRecHitCollection>(iConfig.getParameter<edm::InputTag>("EcalUncalibRecHitsEBCollection"));
//   _token_eerechits = consumes<EcalUncalibratedRecHitCollection>(iConfig.getParameter<edm::InputTag>("EcalUncalibRecHitsEECollection"));
//   
//   _token_second_ebrechits = consumes<EcalUncalibratedRecHitCollection>(iConfig.getParameter<edm::InputTag>("EcalUncalibRecHitsEBCollectionSecond"));
//   _token_second_eerechits = consumes<EcalUncalibratedRecHitCollection>(iConfig.getParameter<edm::InputTag>("EcalUncalibRecHitsEECollectionSecond"));
//   
//   _token_ebdigi = consumes<EBDigiCollection>(iConfig.getParameter<edm::InputTag>("EBDigiCollection"));
//   _token_eedigi = consumes<EEDigiCollection>(iConfig.getParameter<edm::InputTag>("EEDigiCollection"));
//   
  
  
  _outTree = fs->make<TTree>("tree","tree");
  
  _outTree->Branch("run",               &_run,             "run/i");
  _outTree->Branch("lumi",              &_lumi,            "lumi/s");
  _outTree->Branch("bx",                &_bx,              "bx/s");
  _outTree->Branch("event",             &_event,           "event/i");
  
  _outTree->Branch("digi_ES_1",        _digi_ES_1,        "digi_ES_1[6000]/F"); // 
  _outTree->Branch("digi_ES_2",        _digi_ES_2,        "digi_ES_2[6000]/F"); // 
  _outTree->Branch("digi_ES_3",        _digi_ES_3,        "digi_ES_3[6000]/F"); // 

  _outTree->Branch("ES_zside",        _ES_zside,        "ES_zside[6000]/I"); // 
  _outTree->Branch("ES_plane",        _ES_plane,        "ES_plane[6000]/I"); // 
  _outTree->Branch("ES_ix",           _ES_ix,           "ES_ix[6000]/I"); // 
  _outTree->Branch("ES_iy",           _ES_iy,           "ES_iy[6000]/I"); // 
  _outTree->Branch("ES_strip",        _ES_strip,        "ES_strip[6000]/I"); // 
  
  _outTree->Branch("ES_num",          &_ES_num,         "ES_num/I"); // 
  
  
  
  
//   _outTree->Branch("time_EB",             _time_EB,             "time_EB[61200]/F");
  
  
  //now do what ever initialization is needed
}

ESPulseDumper::~ESPulseDumper() {
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
  //
  // please remove this method altogether if it would be left empty
}

//
// member functions
//

// ------------ method called for each event  ------------
void ESPulseDumper::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
//   using namespace edm;
// 
//   for (const auto& track : iEvent.get(tracksToken_)) {
//     // do something with track parameters, e.g, plot the charge.
//     // int charge = track.charge();
//   }
// 
// #ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
//   // if the SetupData is always needed
//   auto setup = iSetup.getData(setupToken_);
//   // if need the ESHandle to check if the SetupData was there or not
//   auto pSetup = iSetup.getHandle(setupToken_);
// #endif
  
  
  
  _run = iEvent.eventAuxiliary().run();
  _lumi = iEvent.eventAuxiliary().luminosityBlock();
  _bx = iEvent.eventAuxiliary().bunchCrossing();
  _event = iEvent.eventAuxiliary().event();
  
   
  
  //---- ES digi collections 
  edm::Handle<ESDigiCollection> esdigihandle;
  iEvent.getByToken(_token_ESdigiCollection, esdigihandle);
  
  if (!esdigihandle.isValid()) return;
  
  const ESDigiCollection* preshowerDigi = esdigihandle.product();
  
  
  std::vector<double> esADCCounts;
  esADCCounts.reserve(ESDataFrame::MAXSAMPLES);
  
//   std::cout << " ESDataFrame::MAXSAMPLES = " << ESDataFrame::MAXSAMPLES << std::endl;
//   std::cout << " esdigihandle->size() = " << esdigihandle->size() << std::endl;
//   https://cmssdt.cern.ch/lxr/source/DataFormats/EcalDetId/interface/ESDetId.h
//   https://cmssdt.cern.ch/lxr/source/DataFormats/EcalDetId/src/ESDetId.cc
  
  //---- setup default
  for (int ixtal=0; ixtal < 6000; ixtal++) {
    _digi_ES_1[ixtal] = -999;
    _digi_ES_2[ixtal] = -999;
    _digi_ES_3[ixtal] = -999;
   
    _ES_zside[ixtal] = -999;
    _ES_plane[ixtal] = -999;
    _ES_ix[ixtal] = -999;
    _ES_iy[ixtal] = -999;
    _ES_strip[ixtal] = -999;
    
  }
  
  _ES_num = 0;
  
  
  for (unsigned int digis = 0; digis < esdigihandle->size(); ++digis) {
    ESDataFrame esdf = (*preshowerDigi)[digis];
    int nrSamples = esdf.size();
    
    ESDetId esid = esdf.id();
 
//     int hashedIndex = esid.hashedIndex();
    
//   static const int IX_MIN = 1;
//   static const int IY_MIN = 1;
//   static const int IX_MAX = 40;
//   static const int IY_MAX = 40;
//   static const int ISTRIP_MIN = 1;
//   static const int ISTRIP_MAX = 32;
//   static const int PLANE_MIN = 1;
//   static const int PLANE_MAX = 2;
//   static const int IZ_NUM = 2;
    
    int hashedIndex = _ES_num;
    
//     std::cout << " hashedIndex = " << hashedIndex << std::endl;
    
    _ES_zside[hashedIndex] = esid.zside();
    _ES_plane[hashedIndex] = esid.plane();
    _ES_ix[hashedIndex] = esid.six();
    _ES_iy[hashedIndex] = esid.siy();
    _ES_strip[hashedIndex] = esid.strip();
    
    for (int sample = 0; sample < nrSamples; ++sample) {
      ESSample mySample = esdf[sample];
      if (sample==0) _digi_ES_1[hashedIndex] = (mySample.adc());
      if (sample==1) _digi_ES_2[hashedIndex] = (mySample.adc());
      if (sample==2) _digi_ES_3[hashedIndex] = (mySample.adc());
    }
    
    _ES_num++;
    
  }
  
  
  
  
  
  //---- dump digis
  
//   for (EBDigiCollection::const_iterator itdigi = ebdigis->begin(); itdigi != ebdigis->end(); itdigi++ ) {
//     
//     float pedestal = 0;    
//     DetId id = (EBDetId&)((*itdigi));
//     pedestal = float((_peds->find(id))->mean_x12);
//     
//     //                                                           0xFFF = 4095
//     for (int iSample = 0; iSample < 10; iSample++) {
//       float value = ( int( (*itdigi) [iSample] ) & 0xFFF );
//       _digi_ES[((EBDetId&)((*itdigi))).hashedIndex() *10 + iSample] = value - pedestal;
//     }
//   }
  
  
  _outTree->Fill();  
  
  
}

// ------------ method called once each job just before starting event loop  ------------
void ESPulseDumper::beginJob() {
  // please remove this method if not needed
}

// ------------ method called once each job just after ending the event loop  ------------
void ESPulseDumper::endJob() {
  // please remove this method if not needed
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void ESPulseDumper::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);

  //Specify that only 'tracks' is allowed
  //To use, remove the default given above and uncomment below
  //edm::ParameterSetDescription desc;
  //desc.addUntracked<edm::InputTag>("tracks", edm::InputTag("ctfWithMaterialTracks"));
  //descriptions.addWithDefaultLabel(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(ESPulseDumper);
