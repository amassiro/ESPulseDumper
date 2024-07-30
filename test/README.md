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
    
    
Plot

    r99t  test.root  draw.cxx 
    
    r99t  test_MD.root  drawLS.cxx 
    
    
    
Test:

    - normalize to nominal ratio each channel
    - redo plot
    
    - NB: averaging between 2 layers should improve time resolution?
    
    
    
    