import pyroot_logon
import limits
import os
import sys

from array import *


from ROOT import *
from optparse import OptionParser
from ConfigParser import SafeConfigParser

l2nu2_bkgMC=[0,0,0,0,8.53, 8.38, 4.14]
l2nu2_bkgDD=[0.63,0.2,0.09,0.011,17.48, 7.58, 0.78]

l2nu2_signal=[27.93, 14.63, 9.28, 1.55, 13.55, 15.66, 10.14]

stat_signal_err=[0.24, 0.17, 0.14, 0.06, 0.22, 0.28, 0.14]
stat_bkgDD_err=[0.75, 0.24, 0.1, 0.01, 4.38, 2.69, 1.7]
syst_bkgDD_err=[0.48, 0.15, 0.07, 0.008, 1.12, 0.68, 0.19]
stat_bkgMC_err=[0., 0., 0., 0.0, 0.78, 0.74, 0.66]
syst_bkgMC_err=[0., 0., 0., 0.0, 0.19, 0.19, 0.09]
syst_signal_reco_err=[0.97, 0.55, 0.37, 0.07, 0.27, 0.48, 0.4]
syst_signal_th_err=[1.79, 1.04, 0.79, 0.25, 1.29, 1.64, 1.35]

stat_signal_err_rel_Up=[]
stat_bkgDD_err_rel_Up=[]
syst_bkgDD_err_rel_Up=[]
stat_bkgMC_err_rel_Up=[]
syst_bkgMC_err_rel_Up=[]
syst_signal_reco_err_rel_Up=[]
syst_signal_th_err_rel_Up=[]

stat_signal_err_rel_Down=[]
stat_bkgDD_err_rel_Down=[]
syst_bkgDD_err_rel_Down=[]
stat_bkgMC_err_rel_Down=[]
syst_bkgMC_err_rel_Down=[]
syst_signal_reco_err_rel_Down=[]
syst_signal_th_err_rel_Down=[]

for i in range(0,7):
    stat_signal_err_rel_Up.append([])
    stat_bkgDD_err_rel_Up.append([])
    syst_bkgDD_err_rel_Up.append([])
    stat_bkgMC_err_rel_Up.append([])
    syst_bkgMC_err_rel_Up.append([])
    syst_signal_reco_err_rel_Up.append([])
    syst_signal_th_err_rel_Up.append([])

    stat_signal_err_rel_Down.append([]) 
    stat_bkgDD_err_rel_Down.append([]) 
    syst_bkgDD_err_rel_Down.append([])
    stat_bkgMC_err_rel_Down.append([]) 
    syst_bkgMC_err_rel_Down.append([]) 
    syst_signal_reco_err_rel_Down.append([]) 
    syst_signal_th_err_rel_Down.append([])
    print 'i= ',i,'\t',stat_signal_err[i],'\t',l2nu2_signal[i]
    if l2nu2_signal[i]>0:
        if stat_signal_err[i]<l2nu2_signal[i]:
            stat_signal_err_rel_Down[i]=1.-stat_signal_err[i]/l2nu2_signal[i]
        else:
            stat_signal_err_rel_Down[i]=0.001

        stat_signal_err_rel_Up[i]=1.+stat_signal_err[i]/l2nu2_signal[i]
        syst_signal_reco_err_rel_Up[i]=1.+syst_signal_reco_err[i]/l2nu2_signal[i]
        syst_signal_th_err_rel_Up[i]=1.+syst_signal_th_err[i]/l2nu2_signal[i]
        syst_signal_reco_err_rel_Down[i]=1.-syst_signal_reco_err[i]/l2nu2_signal[i]
        syst_signal_th_err_rel_Down[i]=1.-syst_signal_th_err[i]/l2nu2_signal[i]
    else:
        stat_signal_err_rel_Up[i]=1.
        syst_signal_reco_err_rel_Up[i]=1.
        syst_signal_th_err_rel_Up[i]=1.
        stat_signal_err_rel_Down[i]=1.
        syst_signal_reco_err_rel_Down[i]=1.
        syst_signal_th_err_rel_Down[i]=1.
        

    if l2nu2_bkgDD[i]>0:
        if stat_bkgDD_err[i]<l2nu2_bkgDD[i]:
            stat_bkgDD_err_rel_Down[i]=1.-stat_bkgDD_err[i]/l2nu2_bkgDD[i]
        else:
            stat_bkgDD_err_rel_Down[i]=0.001
           
        stat_bkgDD_err_rel_Up[i]=1.+stat_bkgDD_err[i]/l2nu2_bkgDD[i]
        syst_bkgDD_err_rel_Up[i]=1.+syst_bkgDD_err[i]/l2nu2_bkgDD[i]
        syst_bkgDD_err_rel_Down[i]=1.-syst_bkgDD_err[i]/l2nu2_bkgDD[i]
    else:
        stat_bkgDD_err_rel_Up[i]=1.
        syst_bkgDD_err_rel_Up[i]=1.
        stat_bkgDD_err_rel_Down[i]=1.
        syst_bkgDD_err_rel_Down[i]=1.

    if l2nu2_bkgMC[i]>0:
        stat_bkgMC_err_rel_Up[i]=1.+stat_bkgMC_err[i]/l2nu2_bkgMC[i]
        syst_bkgMC_err_rel_Up[i]=1.+syst_bkgMC_err[i]/l2nu2_bkgMC[i]
        stat_bkgMC_err_rel_Down[i]=1.-stat_bkgMC_err[i]/l2nu2_bkgMC[i]
        syst_bkgMC_err_rel_Down[i]=1.-syst_bkgMC_err[i]/l2nu2_bkgMC[i]
    else:
        stat_bkgMC_err_rel_Up[i]=1.
        syst_bkgMC_err_rel_Up[i]=1.
        stat_bkgMC_err_rel_Down[i]=1.
        syst_bkgMC_err_rel_Down[i]=1.


syst_signal_sum_err = []
for i in range(0,7):
    syst_signal_sum_err.append([])
    print i
    syst_signal_sum_err[i]=sqrt(syst_signal_reco_err[i]*syst_signal_reco_err[i]+syst_signal_th_err[i]*syst_signal_th_err[i])
  


def isItCorrelated(name):
    print '\t ----> isItCorrelated: testing ',name
    if ('_MC_syst' in name or '_les' in name or '_DD_syst' in name or '_recoth' in name or '_reco' in name or '_th' in name):
        print '-> true'
        return True
    else:
        print '-> false'
        return False

doAllLnN=True

parser = OptionParser(description="%prog : A RooStats Implementation of Anomalous Triple Gauge Coupling Analysis.",
                      usage="buildWZworkspace --config=example_config.cfg")
cfgparse = SafeConfigParser()

parser.add_option("--config",dest="config",help="The name of the input configuration file.")
(options,args) = parser.parse_args()

miss_options = False

if options.config is None:
    print 'Need to specify --config'
    miss_options=True
    
if miss_options:
    exit(1)
        
cfgparse.read(options.config)
options.config = cfgparse # put the parsed config file into our options

cfg = options.config


#lType = sys.argv[1]
#codename = ""
#planeID = sys.argv[2]

norm_sig_sm = -1
norm_sig_sm_up = -1
norm_sig_sm_down = -1
norm_bkg = -1
norm_obs = -1


fit_sections = cfg.sections()
fit_sections.remove('Global') #don't need to iterate over the global configuration

basepath = '%s/src/CombinedEWKAnalysis/CommonTools/data/WV_semileptonic'%os.environ['CMSSW_BASE']

for section in fit_sections:
    codename = section
    lType = codename
    print '\n\tlType=',lType
    f = TFile('%s/%s_boosted_withSignalSyst_adjustedUnc.root'%(basepath,codename))

    Nbkg = cfg.get(codename,'Nbkg')
    print "Nbkg= ",Nbkg
    Nbkg_int=int(Nbkg)

    bkg_name = []
    for i in range(1,Nbkg_int+1):
        bkg_name.append(cfg.get(codename,'bkg%i_name'%i))

    background = []

    for i in range(0,Nbkg_int):
        background.append(f.Get(bkg_name[i]))


    print 'backgrounds= ',background
    background_shapeSyst = []
    for i in range(0,Nbkg_int):
        background_shapeSyst.append([])
        for name in cfg.get(codename,'bkg%i_shape_syst'%(i+1)).split(','):
            background_shapeSyst[i].append(name)



    background_backshapeUp = []
    background_backshapeDown = []

    for j in range(0,Nbkg_int):
        background_backshapeUp.append([])
        background_backshapeDown.append([])
        for i in range(0,len(background_shapeSyst[j])):
            print ' bkg shape syst: ',background_shapeSyst[j]
            print ' getting bkgUp ','%sUp'%background_shapeSyst[j][i]
            background_backshapeUp[j].append(f.Get('%sUp'%background_shapeSyst[j][i]))
            background_backshapeDown[j].append(f.Get('%sDown'%background_shapeSyst[j][i]))


    data_obs = f.Get('data_obs')
    diboson = f.Get('diboson')

    doSignalShape_unc=False
    cfg_items=cfg.items(codename)
    for cfg_item in cfg_items:
        if 'signal_shape_syst' in cfg_item:
            doSignalShape_unc = True

    print 'doSignalShape_unc=',doSignalShape_unc

    if (doSignalShape_unc):
        diboson_up = {}
        diboson_down = {}
        norm_sig_sm_up = {}
        norm_sig_sm_down = {}
        signal_shapeSyst = [string(i) for i in cfg.get(codename,'signal_shape_syst').split(',')]
        for i in range(0,len(signal_shapeSyst)):
            print ' signal shape syst: ',signal_shapeSyst[i]
            diboson_up[i] = f.Get('%sUp'%signal_shapeSyst[i])
            diboson_down[i] = f.Get('%sDown'%signal_shapeSyst[i])
            norm_sig_sm_up[i] = diboson_up[i].Integral()
            norm_sig_sm_down[i] = diboson_down[i].Integral()


    
    norm_sig_sm = diboson.Integral()
    norm_bkg = []
    for i in range(0,Nbkg_int):
        norm_bkg.append(background[i].Integral())
    norm_obs = data_obs.Integral()
    print 'bkg integral: ',norm_bkg
    
    if (doSignalShape_unc):
        print 'signal shape unc: ',norm_sig_sm_down,' ',norm_sig_sm,' ',norm_sig_sm_up
    
    theWS = RooWorkspace('WV_%sboosted'%codename, 'WV_%sboosted'%codename)
    
    wpt = theWS.factory('W_pt_%s[%f,%f]' % (codename,data_obs.GetBinLowEdge(1), 
                                         data_obs.GetBinLowEdge(data_obs.GetNbinsX())+data_obs.GetBinWidth(data_obs.GetNbinsX())))

    binning=array('d',[])

    for i in range(1, data_obs.GetNbinsX()+1):
        binning.append(data_obs.GetBinLowEdge(i))
    binning.append(data_obs.GetBinLowEdge(data_obs.GetNbinsX()+1))

    print "bining: "
    for i in range(0, len(binning)):
        print binning[i]

    bins=RooBinning(len(binning)-1, binning)

    wpt.setBinning(bins)
    lz = theWS.factory('lZ[0., -0.025, 0.025]')
    lz.setConstant(False)
    dkg = theWS.factory('dkg[0.,-0.025, 0.025]')
    dg1 = theWS.factory('dg1[0.,-0.025, 0.025]')


    vars = RooArgList(wpt)
    varSet = RooArgSet(wpt)

    data = RooDataHist('data_obs', 'data_obs_WV_%s'%codename, vars, data_obs)
    bkgHist = {}
    for i in range(0,Nbkg_int):
        bkgHist[i] = RooDataHist('WV_semileptonic_bkg%i_%s'%(i+1,codename),
                              'WV_semileptonic_bkg%i_%s'%(i+1,codename),
                              vars,
                              background[i])
    
    bkgHist_systUp = []
    bkgHist_systDown = []

    for j in range(0,Nbkg_int):
        bkgHist_systUp.append([])
        bkgHist_systDown.append([])
        for i in range(0,len(background_shapeSyst[j])):
            if (isItCorrelated(background_shapeSyst[j][i])):
                print ' \n\t\t ==================================> <=========================== '
                name_forCorr=background_shapeSyst[j][i]
                print ' name_forCorr= ',name_forCorr
                if ('_DD_syst' in name_forCorr and ('ch1' in name_forCorr or 'ch3' in name_forCorr)):
                    name_forCorr=name_forCorr.replace('l2nu2_','')                    
                    name_forCorr=name_forCorr.replace('l4_','')                    
                    name_forCorr=name_forCorr.replace('ch1_','odd_')                    
                    name_forCorr=name_forCorr.replace('ch3_','odd_')                    
                elif ('_DD_syst' in name_forCorr and ('ch2' in name_forCorr or 'ch4' in name_forCorr)):
                    name_forCorr=name_forCorr.replace('l2nu2_','')                    
                    name_forCorr=name_forCorr.replace('l4_','')                    
                    name_forCorr=name_forCorr.replace('ch2_','even_')                    
                    name_forCorr=name_forCorr.replace('ch4_','even_')                    
                else:
                    name_forCorr=name_forCorr.replace('l2nu2_','')
                    name_forCorr=name_forCorr.replace('l4_','')
                    name_forCorr=name_forCorr.replace('ch1_','')
                    name_forCorr=name_forCorr.replace('ch2_','')
                    name_forCorr=name_forCorr.replace('ch3_','')
                    name_forCorr=name_forCorr.replace('ch4_','')
                print ' -> name_forCorr= ',name_forCorr
                bkgHist_systUp[j].append(RooDataHist('WV_semileptonic_bkg%i_%s_%sUp'%(j+1,codename,name_forCorr),
                                                     'WV_semileptonic_bkg%i_%s_%sUp'%(j+1,codename,name_forCorr),
                                                     vars,
                                                     background_backshapeUp[j][i]))
                bkgHist_systDown[j].append(RooDataHist('WV_semileptonic_bkg%i_%s_%sDown'%(j+1,codename,name_forCorr),
                                                       'WV_semileptonic_bkg%i_%s_%sDown'%(j+1,codename,name_forCorr),
                                                       vars,
                                                       background_backshapeDown[j][i]))
            else:
                bkgHist_systUp[j].append(RooDataHist('WV_semileptonic_bkg%i_%s_%sUp'%(j+1,codename,background_shapeSyst[j][i]),
                                                     'WV_semileptonic_bkg%i_%s_%sUp'%(j+1,codename,background_shapeSyst[j][i]),
                                                     vars,
                                                     background_backshapeUp[j][i]))
                bkgHist_systDown[j].append(RooDataHist('WV_semileptonic_bkg%i_%s_%sDown'%(j+1,codename,background_shapeSyst[j][i]),
                                                       'WV_semileptonic_bkg%i_%s_%sDown'%(j+1,codename,background_shapeSyst[j][i]),
                                                       vars,
                                                       background_backshapeDown[j][i]))

   
    dibosonHist = RooDataHist('WV_semileptonic_SM_%s_rawshape'%codename,
                              'WV_semileptonic_SM_%s_rawshape'%codename,
                              vars,
                              diboson)

    if (doSignalShape_unc):
        dibosonHist_up = {}
        dibosonHist_down = {}
        for i in range(0,len(signal_shapeSyst)):

            if (isItCorrelated(str(signal_shapeSyst[i]))):
                print ' \n\t\t ==================================> <=========================== '
                name_forCorr=str(signal_shapeSyst[i])
                print ' name_forCorr= ',name_forCorr
                name_forCorr=name_forCorr.replace('l2nu2_','')
                name_forCorr=name_forCorr.replace('l4_','')
                name_forCorr=name_forCorr.replace('ch1_','')
                name_forCorr=name_forCorr.replace('ch2_','')
                name_forCorr=name_forCorr.replace('ch3_','')
                name_forCorr=name_forCorr.replace('ch4_','')
                print ' -> name_forCorr= ',name_forCorr
                dibosonHist_up[i] = RooDataHist('WV_semileptonic_SM_%s_rawshape_%sUp'%(codename,name_forCorr),
                                                'WV_semileptonic_SM_%s_rawshape_%sUp'%(codename,name_forCorr),
                                                vars,
                                                diboson_up[i])
                dibosonHist_down[i] = RooDataHist('WV_semileptonic_SM_%s_rawshape_%sDown'%(codename,name_forCorr),
                                                  'WV_semileptonic_SM_%s_rawshape_%sDown'%(codename,name_forCorr),
                                                  vars,
                                                  diboson_down[i])
            else:
                dibosonHist_up[i] = RooDataHist('WV_semileptonic_SM_%s_rawshape_%sUp'%(codename,signal_shapeSyst[i]),
                                                'WV_semileptonic_SM_%s_rawshape_%sUp'%(codename,signal_shapeSyst[i]),
                                                vars,
                                                diboson_up[i])
                dibosonHist_down[i] = RooDataHist('WV_semileptonic_SM_%s_rawshape_%sDown'%(codename,signal_shapeSyst[i]),
                                                  'WV_semileptonic_SM_%s_rawshape_%sDown'%(codename,signal_shapeSyst[i]),
                                                  vars,
                                                  diboson_down[i])
                

#            dibosonHist_up[i] = RooDataHist('WV_semileptonic_SM_%s_rawshape_%sUp'%(codename,signal_shapeSyst[i]),
#                                         'WV_semileptonic_SM_%s_rawshape_%sUp'%(codename,signal_shapeSyst[i]),
#                                         vars,
#                                         diboson_up[i])
#            dibosonHist_down[i] = RooDataHist('WV_semileptonic_SM_%s_rawshape_%sDown'%(codename,signal_shapeSyst[i]),
#                                           'WV_semileptonic_SM_%s_rawshape_%sDown'%(codename,signal_shapeSyst[i]),
#                                           vars,
#                                           diboson_down[i])

    dibosonPdf = RooHistFunc('WV_semileptonic_SM_%s_shape'%codename,
                             'WV_semileptonic_SM_%s_shape'%codename,
                             varSet,
                             dibosonHist)

    if (doSignalShape_unc):
        dibosonPdf_up = {}
        dibosonPdf_down = {}
        for i in range(0,len(signal_shapeSyst)):

            if (isItCorrelated(str(signal_shapeSyst[i]))):
                name_forCorr=str(signal_shapeSyst[i])
                name_forCorr=name_forCorr.replace('l2nu2_','')
                name_forCorr=name_forCorr.replace('l4_','')
                name_forCorr=name_forCorr.replace('ch1_','')
                name_forCorr=name_forCorr.replace('ch2_','')
                name_forCorr=name_forCorr.replace('ch3_','')
                name_forCorr=name_forCorr.replace('ch4_','')
                dibosonPdf_up[i] = RooHistFunc('WV_semileptonic_SM_%s_shape_%sUp'%(codename,name_forCorr),
                                               'WV_semileptonic_SM_%s_shape_%sUp'%(codename,name_forCorr),
                                               varSet,
                                               dibosonHist_up[i])
                dibosonPdf_down[i] = RooHistFunc('WV_semileptonic_SM_%s_shape_%sDown'%(codename,name_forCorr),
                                                 'WV_semileptonic_SM_%s_shape_%sDown'%(codename,name_forCorr),
                                                 varSet,
                                                 dibosonHist_down[i])

            else:
                dibosonPdf_up[i] = RooHistFunc('WV_semileptonic_SM_%s_shape_%sUp'%(codename,signal_shapeSyst[i]),
                                               'WV_semileptonic_SM_%s_shape_%sUp'%(codename,signal_shapeSyst[i]),
                                               varSet,
                                               dibosonHist_up[i])
                dibosonPdf_down[i] = RooHistFunc('WV_semileptonic_SM_%s_shape_%sDown'%(codename,signal_shapeSyst[i]),
                                                 'WV_semileptonic_SM_%s_shape_%sDown'%(codename,signal_shapeSyst[i]),
                                                 varSet,
                                                 dibosonHist_down[i])

#            dibosonPdf_up[i] = RooHistFunc('WV_semileptonic_SM_%s_shape_%sUp'%(codename,signal_shapeSyst[i]),
#                                        'WV_semileptonic_SM_%s_shape_%sUp'%(codename,signal_shapeSyst[i]),
#                                        varSet,
#                                        dibosonHist_up[i])
#            dibosonPdf_down[i] = RooHistFunc('WV_semileptonic_SM_%s_shape_%sDown'%(codename,signal_shapeSyst[i]),
#                                          'WV_semileptonic_SM_%s_shape_%sDown'%(codename,signal_shapeSyst[i]),
#                                          varSet,
#                                          dibosonHist_down[i])
    

    print '\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ reading RooATGCFunction\n'
#    aTGC = RooATGCFunction_wz('ATGC_shapescale_WWgammaZ_WV_atgc_semileptonic_%s'%codename,
#                              'ATGC_shapescale_%s'%codename,
#                              wpt,
#                              lz,
#                              dkg,
#                              dg1, 
#                              '%s/signal_%s_f4.root'%(basepath,codename))
    
    print '\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ read RooATGCFunction\n'
    limtype = -1

    
    planeID = 'dkglZ'
    print 'setting up for %s plane!'%planeID
    if ( planeID == 'dkglZ' ):
        limtype = 0
    elif ( planeID == 'dg1lZ' ):
        limtype = 1
    elif ( planeID == 'dkgdg1'):
        limtype = 2
    else:
        raise RuntimeError('InvalidCouplingChoice',
                           'We can only use [dkg,lZ], [dg1,lZ], and [dkg,dg1]'\
                           ' as POIs right now!')
    
    print limtype

    print '\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ reading RooATGCSemi\n'

    if (doSignalShape_unc):
        kappaLow = {}
        kappaHigh = {}
        aTGCPdf_norm = {}
        theta = {}
        kappaLow_sum_d = 1.
        kappaHigh_sum_d = 1.
        
        for i in range(0,len(signal_shapeSyst)):
            kappaLow[i] = RooRealVar("kappaL_%s_%s"%(i+1,codename),"kappaL_%s_%s"%(i+1,codename),norm_sig_sm_down[i]/norm_sig_sm)
            kappaLow[i].setConstant(True)
            kappaHigh[i] = RooRealVar("kappaH_%s_%s"%(i+1,codename),"kappaH_%s_%s"%(i+1,codename),norm_sig_sm_up[i]/norm_sig_sm)
            kappaHigh[i].setConstant(True)
            kappaLow_sum_d = kappaLow_sum_d*norm_sig_sm_down[i]/norm_sig_sm
            kappaHigh_sum_d = kappaHigh_sum_d*norm_sig_sm_up[i]/norm_sig_sm
            
#            theWS.factory("%s[-7,7]"%signal_shapeSyst[i])
#            theta[i] = theWS.var("%s"%signal_shapeSyst[i])

            if (isItCorrelated(str(signal_shapeSyst[i]))):
                name_forCorr=str(signal_shapeSyst[i])
                name_forCorr=name_forCorr.replace('l2nu2_','')
                name_forCorr=name_forCorr.replace('l4_','')
                name_forCorr=name_forCorr.replace('ch1_','')
                name_forCorr=name_forCorr.replace('ch2_','')
                name_forCorr=name_forCorr.replace('ch3_','')
                name_forCorr=name_forCorr.replace('ch4_','')
                if not doAllLnN:
                    theWS.factory("%s[-7,7]"%name_forCorr)
                    theta[i] = theWS.var("%s"%name_forCorr)

            else:
                if not doAllLnN:
                    theWS.factory("%s[-7,7]"%signal_shapeSyst[i])
                    theta[i] = theWS.var("%s"%signal_shapeSyst[i])
            

            
            if not doAllLnN:
                aTGCPdf_norm[i] = AsymPow('ATGCPdf_WWgammaZ_WV_atgc_semileptonic_%s_integral%s'%(codename,i+1),
                                          'ATGCPdf_WV_%s_integral%s'%(codename,i+1),
                                          kappaLow[i],
                                          kappaHigh[i],
                                          theta[i])
        if not doAllLnN:
            if (len(signal_shapeSyst)==1):
                aTGCPdf_norm_sum = aTGCPdf_norm[0]
            else:
                for i in range(0,len(signal_shapeSyst)):
                    if (i==0): prodset=RooArgList(aTGCPdf_norm[i])
                    else: prodset.add(RooArgList(aTGCPdf_norm[i]))
                aTGCPdf_norm_sum = RooProduct("aTGCPdf_norm_sum","aTGCPdf_norm_sum",prodset)

            kappaLow_sum = RooRealVar("kappaLow_sum","kappaLow_sum",kappaLow_sum_d)
            kappaHigh_sum = RooRealVar("kappaHigh_sum","kappaHigh_sum",kappaHigh_sum_d)                
            aTGCPdf_norm_sum.SetNameTitle('ATGCPdf_WWgammaZ_WV_atgc_semileptonic_%s_norm'%codename,
                                              'ATGCPdf_WV_%s_norm'%codename)
        
        
    aTGCPdf = RooATGCSemiAnalyticPdf_wz('ATGCPdf_WWgammaZ_WV_atgc_semileptonic_%s'%codename,
                                        'ATGCPdf_WV_%s'%codename,
                                        wpt,
                                        dkg,
                                        lz,                                 
                                        dg1,
                                        dibosonPdf,
                                        '%s/signal_%s_f4.root'%(basepath,codename),
                                        limtype
                                        )

    if (doSignalShape_unc):
        aTGCPdf_up = {}
        aTGCPdf_down = {}
        for i in range(0,len(signal_shapeSyst)):
            if (isItCorrelated(str(signal_shapeSyst[i]))):
                name_forCorr=str(signal_shapeSyst[i])
                name_forCorr=name_forCorr.replace('l4_','')
                name_forCorr=name_forCorr.replace('l2nu2_','')
                name_forCorr=name_forCorr.replace('ch1_','')
                name_forCorr=name_forCorr.replace('ch2_','')
                name_forCorr=name_forCorr.replace('ch3_','')
                name_forCorr=name_forCorr.replace('ch4_','')
                aTGCPdf_up[i] = RooATGCSemiAnalyticPdf_wz('ATGCPdf_WWgammaZ_WV_atgc_semileptonic_%s_%sUp'%(codename,name_forCorr),
                                                          'ATGCPdf_WV_%s'%codename,
                                                          wpt,
                                                          dkg,
                                                          lz,                                 
                                                          dg1,
                                                          dibosonPdf_up[i],
                                                          '%s/signal_%s_f4.root'%(basepath,codename),
                                                          limtype
                                                          )
                aTGCPdf_down[i] = RooATGCSemiAnalyticPdf_wz('ATGCPdf_WWgammaZ_WV_atgc_semileptonic_%s_%sDown'%(codename,name_forCorr),
                                                            'ATGCPdf_WV_%s'%codename,
                                                            wpt,
                                                            dkg,
                                                            lz,                                 
                                                            dg1,
                                                            dibosonPdf_down[i],
                                                            '%s/signal_%s_f4.root'%(basepath,codename),
                                                            limtype
                                                            )

            else:
                aTGCPdf_up[i] = RooATGCSemiAnalyticPdf_wz('ATGCPdf_WWgammaZ_WV_atgc_semileptonic_%s_%sUp'%(codename,signal_shapeSyst[i]),
                                                          'ATGCPdf_WV_%s'%codename,
                                                          wpt,
                                                          dkg,
                                                          lz,                                 
                                                          dg1,
                                                          dibosonPdf_up[i],
                                                          '%s/signal_%s_f4.root'%(basepath,codename),
                                                          limtype
                                                          )
                aTGCPdf_down[i] = RooATGCSemiAnalyticPdf_wz('ATGCPdf_WWgammaZ_WV_atgc_semileptonic_%s_%sDown'%(codename,signal_shapeSyst[i]),
                                                            'ATGCPdf_WV_%s'%codename,
                                                            wpt,
                                                            dkg,
                                                            lz,                                 
                                                            dg1,
                                                            dibosonPdf_down[i],
                                                            '%s/signal_%s_f4.root'%(basepath,codename),
                                                            limtype
                                                            )

#            aTGCPdf_up[i] = RooATGCSemiAnalyticPdf_wz('ATGCPdf_WWgammaZ_WV_atgc_semileptonic_%s_%sUp'%(codename,signal_shapeSyst[i]),
#                                                   'ATGCPdf_WV_%s'%codename,
#                                                   wpt,
#                                                   dkg,
#                                                   lz,                                 
#                                                   dg1,
#                                                   dibosonPdf_up[i],
#                                                   '%s/signal_%s_f4.root'%(basepath,codename),
#                                                   limtype
#                                                   )
#            aTGCPdf_down[i] = RooATGCSemiAnalyticPdf_wz('ATGCPdf_WWgammaZ_WV_atgc_semileptonic_%s_%sDown'%(codename,signal_shapeSyst[i]),
#                                                     'ATGCPdf_WV_%s'%codename,
#                                                     wpt,
#                                                     dkg,
#                                                     lz,                                 
#                                                     dg1,
#                                                     dibosonPdf_down[i],
#                                                     '%s/signal_%s_f4.root'%(basepath,codename),
#                                                     limtype
#                                                     )
    
    
    print '\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ read RooATGCSemi\n'
    
    getattr(theWS, 'import')(data)
    for i in range(0,Nbkg_int):
        getattr(theWS, 'import')(bkgHist[i])
    getattr(theWS, 'import')(aTGCPdf)

    if not doAllLnN:
        for j in range(0,Nbkg_int):
            for i in range(0,len(background_shapeSyst[j])):
                getattr(theWS, 'import')(bkgHist_systUp[j][i])
                getattr(theWS, 'import')(bkgHist_systDown[j][i])
        if (doSignalShape_unc):
            for i in range(0,len(signal_shapeSyst)):
                getattr(theWS, 'import')(aTGCPdf_up[i])
                getattr(theWS, 'import')(aTGCPdf_down[i])
                #            getattr(theWS, 'import')(aTGCPdf_norm[i])
            getattr(theWS, 'import')(aTGCPdf_norm_sum)
    
    theWS.Print()
    
    fout = TFile('%s_boosted_ws.root'%(codename), 'recreate')
    theWS.Write()
    fout.Close()

    leptons=""
    ch=100

## calculate relative error:
    if (codename=="ch1"):
        ch=0
        leptons="l4"
        codename_forBKGDDsyst="odd"
    if (codename=="ch2"):
        ch=1
        leptons="l4"
        codename_forBKGDDsyst="even"
    if (codename=="ch3"):
        ch=2
        leptons="l4"
        codename_forBKGDDsyst="odd"
    if (codename=="ch4"):
        ch=3
        leptons="l4"
        codename_forBKGDDsyst="even"
    if (codename=="ch5"):
        ch=4
        codename_forBKGDDsyst="odd"
        leptons="l2nu2"
        Nbkg_int=2
        norm_bkg.append([])
        norm_bkg[0]=l2nu2_bkgMC[4]
        norm_bkg[1]=l2nu2_bkgDD[4]
    if (codename=="ch6"):
        ch=5
        codename_forBKGDDsyst="even"
        Nbkg_int=2
        leptons="l2nu2"
        norm_bkg.append([])
        norm_bkg[0]=l2nu2_bkgMC[5]
        norm_bkg[1]=l2nu2_bkgDD[5]
    if (codename=="ch7"):
        ch=6
        leptons="l2nu2"
        codename_forBKGDDsyst="odd"
        Nbkg_int=2
        norm_bkg.append([])
        norm_bkg[0]=l2nu2_bkgMC[6]
        norm_bkg[1]=l2nu2_bkgDD[6]
       
    print "===================> channel: ",ch+1


### make the card for this channel and plane ID
    card = """
# Simple counting experiment, with one signal and a few background processes 
imax 1  number of channels
jmax {Nbkg_int}  number of backgrounds
kmax *  number of nuisance parameters (sources of systematical uncertainties)
------------""".format(codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg,norm_obs=norm_obs,Nbkg_int=Nbkg_int)
    for i in range(0,Nbkg_int):
        card += """
shapes WV_semileptonic_bkg{Nbkg_int}_{codename}  {codename}boosted ./{codename}_boosted_ws.root WV_{codename}boosted:$PROCESS WV_{codename}boosted:$PROCESS""".format(Nbkg_int=i+1,codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg,norm_obs=norm_obs)
    card += """
shapes data_obs                {codename}boosted ./{codename}_boosted_ws.root WV_{codename}boosted:$PROCESS """.format(codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg,norm_obs=norm_obs,Nbkg_int=Nbkg_int)
    if (doSignalShape_unc):
        card += """   
shapes WWgammaZ_WV_atgc_semileptonic_{codename} {codename}boosted ./{codename}_boosted_ws.root WV_{codename}boosted:ATGCPdf_$PROCESS WV_{codename}boosted:ATGCPdf_$PROCESS """.format(codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg,norm_obs=norm_obs)
    else:
        card += """   
shapes WWgammaZ_WV_atgc_semileptonic_{codename} {codename}boosted ./{codename}_boosted_ws.root WV_{codename}boosted:ATGCPdf_$PROCESS
""".format(codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg,norm_obs=norm_obs)
        
    card += """   
------------
bin {codename}boosted 
observation {norm_obs}
------------
bin                         {codename}boosted\t\t""".format(codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg,norm_obs=norm_obs)

    for i in range(0,Nbkg_int):
        card += """\t\t\t{codename}boosted""".format(codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg[i],norm_obs=norm_obs)

    card += """       
process\t\t\t    WWgammaZ_WV_atgc_semileptonic_{codename}    """.format(codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg[i],norm_obs=norm_obs)

    for i in range(0,Nbkg_int):
        card += """\tWV_semileptonic_bkg{Nbkg_int}_{codename}""".format(Nbkg_int=i+1,codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg[i],norm_obs=norm_obs)

    card += """       
process                     0	  	      """.format(codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg[i],norm_obs=norm_obs)

    for i in range(0,Nbkg_int):
        card += """ \t\t\t\t{i}""".format(i=i+1,codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg[i],norm_obs=norm_obs)
        
    card += """       
rate                        {norm_sig_sm}\t""".format(codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg[i],norm_obs=norm_obs)

    for i in range(0,Nbkg_int):
        card += """ \t\t\t{norm_bkg}""".format(codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg[i],norm_obs=norm_obs)

    if (codename=="mu" or codename=="el" or codename=="elmu"):
        card += """           
------------
lumi_8TeV           trG     0.022             """
        for i in range(0,Nbkg_int):
            card += """\t\t\t\t-"""
        card += """           
sig_other           trG      0.1342            """
        for i in range(0,Nbkg_int):
            card += """\t\t\t\t-"""
        card += """           
background_{codename}boosted_backshape          trG      -            """.format(codename=codename)
        for i in range(0,Nbkg_int):
            card += """\t\t\t\t0.3"""
        card += """           
signal_th          trG      0.04            """.format(codename=codename)
        for i in range(0,Nbkg_int):
            card += """\t\t\t\t-"""

    else:
        if (leptons=="l2nu2"):
            card += """           
------------
lumi_8TeV           trG     0.039\t\t\t0.039\t\t\t-"""
        else:
            card += """           
------------
lumi_8TeV           trG     0.039\t\t\t-"""
        if (leptons=="l2nu2"):
            card += """
{leptons}_{codename}_background_MC_stat        trG     -                           {err_up}                             -""".format(leptons=leptons,codename=codename,err_down=stat_bkgMC_err_rel_Down[ch],err_up=stat_bkgMC_err_rel_Up[ch]-1.)
            card += """
background_MC_syst        trG     -                           {err_up}                             -""".format(leptons=leptons,codename=codename,err_down=syst_bkgMC_err_rel_Down[ch],err_up=syst_bkgMC_err_rel_Up[ch]-1.)

        if (leptons=="l2nu2"):
            card += """
{leptons}_{codename}_background_DD_factor2p5_stat        trG     -                           -                             {err_up}""".format(leptons=leptons,codename=codename,err_down=stat_bkgDD_err_rel_Down[ch],err_up=stat_bkgDD_err_rel_Up[ch]-1.)

            if (codename_forBKGDDsyst=="odd"):
                card += """
odd_background_DD_syst       trG     -                           -                             {err_up}""".format(leptons=leptons,codename=codename,err_down=syst_bkgDD_err_rel_Down[ch],err_up=syst_bkgDD_err_rel_Up[ch]-1.)
            else:
                card += """
even_background_DD_syst       trG     -                           -                             {err_up}""".format(leptons=leptons,codename=codename,err_down=syst_bkgDD_err_rel_Down[ch],err_up=syst_bkgDD_err_rel_Up[ch]-1.)
            card += """
{leptons}_{codename}_signal_stat       trG     {err_up}                           -                             -""".format(leptons=leptons,codename=codename,err_down=stat_signal_err_rel_Down[ch],err_up=stat_signal_err_rel_Up[ch]-1.)
            card += """
signal_reco       trG     {err_up}                           -                             -""".format(leptons=leptons,codename=codename,err_down=syst_signal_reco_err_rel_Down[ch],err_up=syst_signal_reco_err_rel_Up[ch]-1.)
            card += """
signal_th       trG     {err_up}                           -                             -""".format(leptons=leptons,codename=codename,err_down=syst_signal_th_err_rel_Down[ch],err_up=syst_signal_th_err_rel_Up[ch]-1.)

        else:
            card += """
{leptons}_{codename}_background_DD_factor1p5_stat        trG     -                             {err_up}""".format(leptons=leptons,codename=codename,err_down=stat_bkgDD_err_rel_Down[ch],err_up=stat_bkgDD_err_rel_Up[ch]-1.)

            if (codename_forBKGDDsyst=="odd"):
                card += """
odd_background_DD_syst       trG     -                                   {err_up}""".format(leptons=leptons,codename=codename,err_down=syst_bkgDD_err_rel_Down[ch],err_up=syst_bkgDD_err_rel_Up[ch]-1.)
            else:
                card += """
even_background_DD_syst       trG     -                                        {err_up}""".format(leptons=leptons,codename=codename,err_down=syst_bkgDD_err_rel_Down[ch],err_up=syst_bkgDD_err_rel_Up[ch]-1.)
            card += """
{leptons}_{codename}_signal_stat       trG     {err_up}                                           -""".format(leptons=leptons,codename=codename,err_down=stat_signal_err_rel_Down[ch],err_up=stat_signal_err_rel_Up[ch]-1.)
            card += """
signal_reco       trG     {err_up}                                              -""".format(leptons=leptons,codename=codename,err_down=syst_signal_reco_err_rel_Down[ch],err_up=syst_signal_reco_err_rel_Up[ch]-1.)
            card += """
signal_th       trG     {err_up}                                             -""".format(leptons=leptons,codename=codename,err_down=syst_signal_th_err_rel_Down[ch],err_up=syst_signal_th_err_rel_Up[ch]-1.)

#lumi_8TeV           trG     {err_up}39                                       {err_up}39                           -
#l2nu2_ch3_background_MC_stat shape  -                           {err_up}                       .format(err_down=stat_bkgMC_err_rel_Down[ch],err_up=stat_bkgMC_err_rel_Up[ch])      -
#background_MC_syst shape  -                             {err_up}                             -
#l2nu2_ch3_background_DD_factor2p5_stat shape  -                         -                               1.845 
#odd_background_DD_syst shape  -                         -                               {err_up} 
#l2nu2_ch3_signal_stat        shape1  {err_up}                                        -                               -
#signal_reco        shape1  {err_up}                                          -                               -
#signal_th        shape1  {err_up}                                     -                               -

#lumi_8TeV           trG     1.039             				-
#l4_ch1_background_DD_factor1p5_stat shape  -				1.335 
#odd_background_DD_syst shape  -				1.0 
#l4_ch1_signal_stat        shape1  1.0          				-
#signal_reco        shape1  1.0          				-
#signal_th        shape1  1.0          				-

    print card

    cardfile = open('wv_semil_%sboosted.txt'%(codename),'w')
    cardfile.write(card)
    cardfile.close
