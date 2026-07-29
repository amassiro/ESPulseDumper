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
     https://cmsoms.cern.ch/cms/runs/report?cms_run=395987
     LS 750 - 878


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


Get Lumisections:

    https://cmsoms.cern.ch
    https://cmsoms.cern.ch/agg/api/v1/lumisections?fields=lumisection_number,start_time,end_time,physics_flag&page[offset]=0&page[limit]=10&filter[cms_active][EQ]=true&filter[start_time][GT]=2026-05-08T13:41:46Z&filter[end_time][LT]=2026-05-11T11:04:58Z&sort=-lumisection_number&include=meta,presentation_timestamp

    https://cmsoms.cern.ch/agg/api/v1/lumisections?fields=lumisection_number,start_time,end_time,physics_flag&page[offset]=0&page[limit]=10&filter[cms_active][EQ]=true&filter[start_time][GT]=2026-05-08T13:41:46Z&filter[end_time][LT]=2026-05-11T11:04:58Z&sort=-lumisection_number&include=meta,presentation_timestamp

Transfer:

    https://cmsdmops.docs.cern.ch/Users/Subscribe%20data/




    source /cvmfs/cms.cern.ch/rucio/setup-py3.sh
    voms-proxy-init -voms cms -rfc -valid 192:00
    export RUCIO_ACCOUNT=`whoami`


Rule asking for a dataset to be replicated at CERN DISK for a 1 month

    rucio rule add \
        --copies 1 \
        --rses T2_CH_CERN \
        --lifetime 2592000 \
        --activity "User AutoApprove" \
        --ask-approval \
        --comment "ECAL ES studies" \
        cms:/store/data/Run2025B/EGamma0/RAW/v1/000/391/668/00000/5f4e6111-8754-4591-8107-91721de31c5d.root


    rucio rule add \
        --copies 1 \
        --rses T2_CH_CERN \
        --lifetime 2592000 \
        --activity "User AutoApprove" \
        --ask-approval \
        --comment "ECAL ES studies" \
        cms:/store/data/Run2025B/EGamma1/RAW/v1/000/391/668/00000/467b13c2-8084-4827-8f19-0007a4e45de0.root


    rucio rule add \
        --copies 1 \
        --rses T2_CH_CERN \
        --lifetime 2592000 \
        --activity "User AutoApprove" \
        --ask-approval \
        --comment "ECAL ES studies" \
        cms:/store/data/Run2025B/EGamma2/RAW/v1/000/391/668/00000/21ce2e2c-d654-435a-93b0-f9968e0d2f41.root


    rucio rule add \
        --copies 1 \
        --rses T2_CH_CERN \
        --lifetime 2592000 \
        --activity "User AutoApprove" \
        --ask-approval \
        --comment "ECAL ES studies" \
        cms:/store/data/Run2025B/EGamma3/RAW/v1/000/391/668/00000/53d1bd12-e3fd-4b8d-9495-1810c789004f.root


Automatically from list of files ...


while read -r file; do
[ -z "$file" ] && continue

cat <<EOF
rucio rule add \\
        --copies 1 \\
        --rses T2_CH_CERN \\
        --lifetime 2592000 \\
        --activity "User AutoApprove" \\
        --ask-approval \\
        --comment "ECAL ES studies" \\
        cms:$file

EOF
done < test.txt > add_rules.sh





while read -r file; do
[ -z "$file" ] && continue

cat <<EOF
rucio rule add \\
        --copies 1 \\
        --rses T2_CH_CERN \\
        --lifetime 2592000 \\
        --activity "User AutoApprove" \\
        --ask-approval \\
        --comment "ECAL ES studies" \\
        cms:$file

EOF
done < test2.txt > add_rules_2.sh



A bit too much:

        cms:/EGamma0/Run2025B-v1/RAW

On DAS:

        file dataset=/EGamma0/Run2025B-v1/RAW run=391668
        file dataset=/EGamma1/Run2025B-v1/RAW run=391668
        file dataset=/EGamma2/Run2025B-v1/RAW run=391668
        file dataset=/EGamma3/Run2025B-v1/RAW run=391668


        file dataset=/EGamma0/Run2025E-v1/RAW run=395987  lumi=750

        dasgoclient -query="file,lumi dataset=/EGamma0/Run2025E-v1/RAW run=395987" -json >> test.txt

        dasgoclient -query="file,lumi dataset=/EGamma0/Run2025E-v1/RAW run=395987 | grep file.name, lumi.number" | tr "[" " " | tr "]" " " | awk '$2 >= 750 && $2 <= 878 {print $1}' | sort -u
        dasgoclient -query="file,lumi dataset=/EGamma0/Run2025E-v1/RAW run=395987 | grep file.name, lumi.number" | tr "[" " " | tr "]" " " | awk '$2 >= 750 && $2 <= 878 {print $1}' | sort -u > test.txt

        dasgoclient -query="file,lumi dataset=/EGamma0/Run2025E-v1/RAW run=395987 | grep file.name, lumi.number" | tr "[" " " | tr "]" " " | awk '$2 >= 750 && $2 <= 878 {print $1 $2}' | sort -u



        dasgoclient -query="file,lumi dataset=/EGamma0/Run2025E-v1/RAW run=396260 | grep file.name, lumi.number" | tr "[" " " | tr "]" " " | awk '$2 >= 550 && $2 <= 600 {print $1}' | sort -u > test2.txt




On eos:

    /eos/cms/store/data/Run2025B/EGamma0/RAW/v1/000/391/668/00000/5f4e6111-8754-4591-8107-91721de31c5d.root
    /eos/cms/store/data/Run2025B/EGamma1/RAW/v1/000/391/668/00000/467b13c2-8084-4827-8f19-0007a4e45de0.root
    /eos/cms/store/data/Run2025B/EGamma2/RAW/v1/000/391/668/00000/21ce2e2c-d654-435a-93b0-f9968e0d2f41.root
    /eos/cms/store/data/Run2025B/EGamma3/RAW/v1/000/391/668/00000/53d1bd12-e3fd-4b8d-9495-1810c789004f.root



    cmsRun runDump.py outputFile=/tmp/amassiro/test_Run2025B.root inputFiles_load=myFilesRun2025B.txt


    cmsRun runDump.py outputFile=/tmp/amassiro/test_Run391668.root inputFiles_load=myFilesRun2025B_run391668.txt
    cmsRun runDump.py outputFile=/tmp/amassiro/test_Run395987.root inputFiles_load=myFilesRun2025E_Run395987.txt
    cmsRun runDump.py outputFile=/tmp/amassiro/test_Run396260.root inputFiles_load=myFilesRun2025E_Run396260.txt

