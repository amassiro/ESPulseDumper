Test
====


    cmsRun runDump.py  inputFiles=file:/eos/user/a/amassiro/ECAL/2024/49c2a175-5eb6-4377-98c8-31895c4367b5.root   outputFile=test.root   maxEvents=20

    cmsRun runDump.py  inputFiles=file:/eos/user/a/amassiro/ECAL/2024/49c2a175-5eb6-4377-98c8-31895c4367b5.root   outputFile=test.root

    
    
    EGamma1/Run2024E-EGMJME-PromptReco-v1/RAW-RECO
    
    /eos/cms/store/data/Run2024E/EGamma1/RAW-RECO/EGMJME-PromptReco-v1/000/381/365/00000/49c2a175-5eb6-4377-98c8-31895c4367b5.root
    still on eos and copied here
    /eos/user/a/amassiro/ECAL/2024/49c2a175-5eb6-4377-98c8-31895c4367b5.root
    
    
    
    Interesting run:
    /eos/cms/store/data/Run2024E/JetMET0/RAW/v1/000/381/594/00000/
    
    copied here:   /eos/user/a/amassiro/ECAL/2024/Run381594/
    
    cmsRun runDump.py outputFile=test_MD.root inputFiles_load=myFiles.txt
    cmsRun runDump.py outputFile=/tmp/amassiro/test_MD.root inputFiles_load=myFiles.txt

    
    
     w0:w1:w2 = 0 : 0.7381 : 0.4667
    

     5/5/2025: beginning of the fill, 3 cm effect: https://cmsoms.cern.ch/cms/fills/report?cms_fill=10590
     /eos/cms/store/data/Run2025B/*/RA*/*/*/391/668/*/*.root
     run 391668

     /eos/cms/store/data/Run2025B/ZeroBias/RAW/v1/000/391/668/00000/a01a5be6-7d9a-44ab-8dec-db99b72fce22.root
     copied here:   /eos/user/a/amassiro/ECAL/2025/Run391668/
     cmsRun runDump.py outputFile=/tmp/amassiro/test_MD_2025.root inputFiles_load=myFiles2025.txt


     18/8/2025: Towards the end of the fill, https://cmsoms.cern.ch/cms/fills/report?cms_fill=10959
     /eos/cms/store/data/Run2025E/*/RA*/*/*/395/987/*/*.root
     run 395987
     --> no RAW on disk


     27/8/2025: for about 10 minutes test by LHC: https://cmsoms.cern.ch/cms/fills/report?cms_fill=10984
     /eos/cms/store/data/Run2025E/*/RA*/*/*/396/260/*/*.root
     run 396260
     --> no RAW on disk





Plot

    r99t  test.root  draw.cxx 
    
    r99t  test_MD.root  drawLS.cxx 
    
    
    
Test:

    - normalize to nominal ratio each channel
    - redo plot
    
    - NB: averaging between 2 layers should improve time resolution?
    
    
    
    
