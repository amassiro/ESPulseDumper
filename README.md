ESPulseDumper
====

Kate:

    lxplus-ECAL-ES

Where:

    /afs/cern.ch/user/a/amassiro/work/ECAL/
    /afs/cern.ch/user/a/amassiro/work/ECAL/CMSSW_14_0_7_patch2/src/ECALValidation/ESPulseDumper
    /afs/cern.ch/user/a/amassiro/work/ECAL/CMSSW_15_0_5/src/ECALValidation/ESPulseDumper/test

Where local:

    /home/amassiro/Cern/Code/ECAL/ESPulseDumper


To install:

    mkdir ECALValidation
    cd ECALValidation/
    git clone git@github.com:amassiro/ESPulseDumper.git

    cmsenv
    scramv1 b -j 20
    
    
    
    
    
Test on:

    https://cmsoms.cern.ch/cms/runs/report?cms_run=381594
    
    
Other possible fills with cogging tests, i.e. Z-posizion of beamspot changed, thus indirectly a time scan for ES

    5/6/2024: https://cmsoms.cern.ch/cms/fills/report?cms_fill=9717
            data skimmed:


    5/5/2025: beginning of the fill, 3 cm effect: https://cmsoms.cern.ch/cms/fills/report?cms_fill=10590
            data skimmed: /eos/user/a/amassiro/ECAL/2026/test_Run391668.root
            about 0.3 GB


    18/8/2025: Towards the end of the fill, https://cmsoms.cern.ch/cms/fills/report?cms_fill=10959
            data skimmed: /eos/user/a/amassiro/ECAL/2026/test_Run395987.root
            about 16 GB


    27/8/2025: for about 10 minutes test by LHC: https://cmsoms.cern.ch/cms/fills/report?cms_fill=10984
            data skimmed: /eos/user/a/amassiro/ECAL/2026/test_Run396260.root
            about 1 GB (but not all files analysed ... not enough time to run in local yet)

    


