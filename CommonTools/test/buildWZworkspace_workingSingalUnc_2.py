import pyroot_logon
import limits
import os
import sys

from array import *


from ROOT import *
from optparse import OptionParser
from ConfigParser import SafeConfigParser

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
#if( lType == "muon" ) :
#    codename = "mu"
#elif( lType == "electron" ):
#    codename = "el"
#else:
#    raise RuntimeError('InvalidLepton','You may only choose between "muon" and "electron" channels.')

#if( lType == "ch1" ) :
#    codename = "ch1"
#elif( lType == "ch2" ):
#    codename = "ch2"
#elif( lType == "ch3" ):
#    codename = "ch3"
#elif( lType == "ch4" ):
#    codename = "ch4"
#else:
#    raise RuntimeError('InvalidLepton','You may only choose between "ch1","ch2","ch3","ch4" channels.')

fit_sections = cfg.sections()
fit_sections.remove('Global') #don't need to iterate over the global configuration

#lType = fit_sections
#codename = fit_sections

#par1Name=cfg.get('Global','par1Name')
#par2Name=cfg.get('Global','par2Name')


basepath = '%s/src/CombinedEWKAnalysis/CommonTools/data/WV_semileptonic'%os.environ['CMSSW_BASE']

for section in fit_sections:
    codename = section
#    lType = section
    lType = codename
    print 'lType=',lType
    f = TFile('%s/%s_boosted.root'%(basepath,codename))

    background = f.Get('background')

    background_shapeSyst = [string(i) for i in cfg.get(codename,'bkg_shape_syst').split(',')]

    print 'using bkg shape syst = ',background_shapeSyst

    background_backshapeUp = {}
    background_backshapeDown = {}

    for i in range(0,len(background_shapeSyst)):
        print ' bkg shape syst: ',background_shapeSyst[i]
        background_backshapeUp[i] = f.Get('%sUp'%background_shapeSyst[i])
        background_backshapeDown[i] = f.Get('%sDown'%background_shapeSyst[i])

#    background_backshapeUp = f.Get('background_%sboosted_backshapeUp'%codename)
#    background_backshapeDown = f.Get('background_%sboosted_backshapeDown'%codename)
    data_obs = f.Get('data_obs')
    diboson = f.Get('diboson')

    doSignalShape_unc=False
    print 'doSignalShape_unc=',doSignalShape_unc

    cfg_items=cfg.items(codename)
    for cfg_item in cfg_items:
        if 'signal_shape_syst' in cfg_item:
            doSignalShape_unc = True

#    if (cfg.get(codename,'signal_shape_syst')):
#        doSignalShape_unc = True

#    for line in cfg.get(codename,'signal_shape_syst'):
#        if 'signal_shape_syst' in line:
#            doSignalShape_unc = True
    print 'doSignalShape_unc=',doSignalShape_unc

    if (doSignalShape_unc):
        signal_shapeSyst = cfg.get(codename,'signal_shape_syst')
#        signal_shapeSyst = [string(i) for i in cfg.get(codename,'signal_shape_syst').split(',')]
        #par1Name=cfg.get('Global','par1Name')
        print 'signalshapeName=',signal_shapeSyst
        print 'signalshapeName=%sUp'%signal_shapeSyst
        diboson_up = f.Get('%sUp'%signal_shapeSyst)
        diboson_down = f.Get('%sDown'%signal_shapeSyst)
        norm_sig_sm_up = signal_shapeUp.Integral()
        norm_sig_sm_down = signal_shapeDown.Integral()

#    diboson_up = f.Get('signal_shapeUp')
#    diboson_down = f.Get('signal_shapeDown')
    
    norm_sig_sm = diboson.Integral()
#    norm_sig_sm_up = diboson_up.Integral()
#    norm_sig_sm_down = diboson_down.Integral()
    norm_bkg = background.Integral()
    norm_obs = data_obs.Integral()

    if (doSignalShape_unc):
        print 'signal shape unc: ',norm_sig_sm_down,' ',norm_sig_sm,' ',norm_sig_sm_up
    
    theWS = RooWorkspace('WV_%sboosted'%codename, 'WV_%sboosted'%codename)
    
    wpt = theWS.factory('W_pt[%f,%f]' % (data_obs.GetBinLowEdge(1), 
                                         data_obs.GetBinLowEdge(data_obs.GetNbinsX())+data_obs.GetBinWidth(data_obs.GetNbinsX())))

    binning=array('d',[])

    for i in range(1, data_obs.GetNbinsX()+1):
        print i," ",data_obs.GetBinLowEdge(i)
        binning.append(data_obs.GetBinLowEdge(i))
    binning.append(data_obs.GetBinLowEdge(data_obs.GetNbinsX()+1))
    print data_obs.GetBinLowEdge(data_obs.GetNbinsX()+1)

    print "bining: "
    for i in range(0, len(binning)):
        print binning[i]

    bins=RooBinning(len(binning)-1, binning)

    wpt.setBinning(bins)
    lz = theWS.factory('lZ[0., -1., 1.]')
    lz.setConstant(False)
    dkg = theWS.factory('dkg[0.,-0.15, 0.15]')
    dg1 = theWS.factory('dg1[0.,-0.1,0.1]')

#    par2 = theWS.factory('%s[0.,-1.,1.]'%(par2Name))
#    par2.setConstant(False)
#    par1 = theWS.factory('%s[0.,-0.15, 0.15]'%(par1Name))

#    par1.SetName('par1')
#    par2.SetName('par2')
#    par2 = theWS.factory('par2[0.,-1.,1.]')
#    par2.setConstant(False)
#    par1 = theWS.factory('par1[0.,-0.15, 0.15]')
#    dg1 = theWS.factory('dg1[0.,-0.1,0.1]')


    vars = RooArgList(wpt)
    varSet = RooArgSet(wpt)

    data = RooDataHist('data_obs', 'data_obs_WV_%s'%codename, vars, data_obs)
    bkgHist = RooDataHist('WV_semileptonic_bkg_%s'%codename,
                          'WV_semileptonic_bkg_%s'%codename,
                          vars,
                          background)
    
    bkgHist_systUp = {}
    bkgHist_systDown = {}
    for i in range(0,len(background_shapeSyst)):

        bkgHist_systUp[i] = RooDataHist('WV_semileptonic_bkg_%s_%sUp'%(codename,background_shapeSyst[i]),
                                     'WV_semileptonic_bkg_%s_%sUp'%(codename,background_shapeSyst[i]),
                                     vars,
                                     background_backshapeUp[i])
        bkgHist_systDown[i] = RooDataHist('WV_semileptonic_bkg_%s_%sDown'%(codename,background_shapeSyst[i]),
                                       'WV_semileptonic_bkg_%s_%sDown'%(codename,background_shapeSyst[i]),
                                       vars,
                                       background_backshapeDown[i])
#        bkgHist_systUp[i] = RooDataHist('WV_semileptonic_bkg_%s_%sboosted_%s_backshapeUp'%(codename,codename,background_shapeSyst[i]),
#                                     'WV_semileptonic_bkg_%s_%sboosted_%s_backshapeUp'%(codename,codename,background_shapeSyst[i]),
#                                     vars,
#                                     background_backshapeUp[i])
#        bkgHist_systDown[i] = RooDataHist('WV_semileptonic_bkg_%s_%sboosted_%s_backshapeDown'%(codename,
#                                                                                         codename,background_shapeSyst[i]),
#                                       'WV_semileptonic_bkg_%s_%sboosted_%s_backshapeDown'%(codename,
#                                                                                         codename,background_shapeSyst[i]),
#                                       vars,
#                                       background_backshapeDown[i])
    
    dibosonHist = RooDataHist('WV_semileptonic_SM_%s_rawshape'%codename,
                              'WV_semileptonic_SM_%s_rawshape'%codename,
                              vars,
                              diboson)

    if (doSignalShape_unc):
        dibosonHist_up = RooDataHist('WV_semileptonic_SM_%s_rawshape_signalshapeUp'%codename,
                                     'WV_semileptonic_SM_%s_rawshape_signalshapeUp'%codename,
                                     vars,
                                     diboson_up)
        dibosonHist_down = RooDataHist('WV_semileptonic_SM_%s_rawshape_signalshapeDown'%codename,
                                       'WV_semileptonic_SM_%s_rawshape_signalshapeDown'%codename,
                                       vars,
                                       diboson_down)

    dibosonPdf = RooHistFunc('WV_semileptonic_SM_%s_shape'%codename,
                             'WV_semileptonic_SM_%s_shape'%codename,
                             varSet,
                             dibosonHist)

    if (doSignalShape_unc):
        dibosonPdf_up = RooHistFunc('WV_semileptonic_SM_%s_shape_signalshapeUp'%codename,
                                    'WV_semileptonic_SM_%s_shape_signalshapeUp'%codename,
                                    varSet,
                                    dibosonHist_up)
        dibosonPdf_down = RooHistFunc('WV_semileptonic_SM_%s_shape_signalshapeDown'%codename,
                                      'WV_semileptonic_SM_%s_shape_signalshapeDown'%codename,
                                      varSet,
                                      dibosonHist_down)
    

    print '\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ reading RooATGCFunction\n'
    aTGC = RooATGCFunction_wz('ATGC_shapescale_WWgammaZ_WV_atgc_semileptonic_%s'%codename,
                              'ATGC_shapescale_%s'%codename,
                              wpt,
                              lz,
                              dkg,
                              dg1, 
                              '%s/signal_WV_%s.root'%(basepath,codename))
    
    print '\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ read RooATGCFunction\n'
    limtype = -1

    
#    planeID = cfg.get('Global','par1Name')+cfg.get('Global','par2Name')
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
        #    kappaLow = RooRealVar("kappaL","kappaL",0.9)
        kappaLow = RooRealVar("kappaL","kappaL",norm_sig_sm_down/norm_sig_sm)
        kappaLow.setConstant(True)
        #    kappaHigh = RooRealVar("kappaH","kappaH",1.1)
        kappaHigh = RooRealVar("kappaH","kappaH",norm_sig_sm_up/norm_sig_sm)
        kappaHigh.setConstant(True)

        theWS.factory("signalshape[-7,7]")
        theta = theWS.var("signalshape")
        #    theta = RooRealVar("signalshape","signalshape",0.,-4.,4.)
        #    theta = RooRealVar("signalshape","theta",0.,-4.,4.)
        #    theta = RooRealVar("theta","signalshape",0.,-4.,4.)
        #    theta = RooRealVar("th","th",0.,-4.,4.)
        
        aTGCPdf_norm = AsymPow('ATGCPdf_WWgammaZ_WV_atgc_semileptonic_%s_norm'%codename,
                               'ATGCPdf_WV_%s_norm'%codename,
                               kappaLow,
                               kappaHigh,
                               theta)
        
    aTGCPdf = RooATGCSemiAnalyticPdf_wz('ATGCPdf_WWgammaZ_WV_atgc_semileptonic_%s'%codename,
                                        'ATGCPdf_WV_%s'%codename,
                                        wpt,
                                        dkg,
                                        lz,                                 
                                        dg1,
                                        dibosonPdf,
                                        '%s/signal_WV_%s.root'%(basepath,codename),
                                        limtype
                                        )

    if (doSignalShape_unc):
        aTGCPdf_up = RooATGCSemiAnalyticPdf_wz('ATGCPdf_WWgammaZ_WV_atgc_semileptonic_%s_signalshapeUp'%codename,
                                               'ATGCPdf_WV_%s'%codename,
                                               wpt,
                                               dkg,
                                               lz,                                 
                                               dg1,
                                               dibosonPdf_up,
                                               '%s/signal_WV_%s.root'%(basepath,codename),
                                               limtype
                                               )
        aTGCPdf_down = RooATGCSemiAnalyticPdf_wz('ATGCPdf_WWgammaZ_WV_atgc_semileptonic_%s_signalshapeDown'%codename,
                                                 'ATGCPdf_WV_%s'%codename,
                                                 wpt,
                                                 dkg,
                                                 lz,                                 
                                                 dg1,
                                                 dibosonPdf_down,
                                                 '%s/signal_WV_%s.root'%(basepath,codename),
                                                 limtype
                                                 )
    
    
    print '\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ read RooATGCSemi\n'
    
    getattr(theWS, 'import')(data)
    getattr(theWS, 'import')(bkgHist)
    for i in range(0,len(background_shapeSyst)):
        getattr(theWS, 'import')(bkgHist_systUp[i])
        getattr(theWS, 'import')(bkgHist_systDown[i])
    getattr(theWS, 'import')(aTGCPdf)
    if (doSignalShape_unc):
        getattr(theWS, 'import')(aTGCPdf_norm)
        getattr(theWS, 'import')(aTGCPdf_up)
        getattr(theWS, 'import')(aTGCPdf_down)
    
    theWS.Print()
    
    fout = TFile('%s_boosted_ws.root'%(codename), 'recreate')
    theWS.Write()
    fout.Close()

### make the card for this channel and plane ID
    card = """
# Simple counting experiment, with one signal and a few background processes 
imax 1  number of channels
jmax 1  number of backgrounds
kmax *  number of nuisance parameters (sources of systematical uncertainties)
------------
shapes WV_semileptonic_bkg_{codename}  {codename}boosted ./{codename}_boosted_ws.root WV_{codename}boosted:$PROCESS WV_{codename}boosted:$PROCESS_$SYSTEMATIC
shapes data_obs                {codename}boosted ./{codename}_boosted_ws.root WV_{codename}boosted:$PROCESS """.format(codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg,norm_obs=norm_obs,background_shapeSyst=background_shapeSyst[i])
    if (doSignalShape_unc):
        card += """   
shapes WWgammaZ_WV_atgc_semileptonic_{codename} {codename}boosted ./{codename}_boosted_ws.root WV_{codename}boosted:ATGCPdf_$PROCESS WV_{codename}boosted:ATGCPdf_$PROCESS_$SYSTEMATIC """.format(codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg,norm_obs=norm_obs,background_shapeSyst=background_shapeSyst[i])
    else:
        card += """   
shapes WWgammaZ_WV_atgc_semileptonic_{codename} {codename}boosted ./{codename}_boosted_ws.root WV_{codename}boosted:ATGCPdf_$PROCESS WV_{codename}boosted:ATGCPdf_$PROCESS_$SYSTEMATIC
""".format(codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg,norm_obs=norm_obs,background_shapeSyst=background_shapeSyst[i])
        
    card += """   
------------
bin {codename}boosted 
observation {norm_obs}
------------
bin                         {codename}boosted		      {codename}boosted
process                     WWgammaZ_WV_atgc_semileptonic_{codename}   WV_semileptonic_bkg_{codename}
process                     0			      1		
rate                        {norm_sig_sm}		      {norm_bkg}	
    
------------
lumi_8TeV           lnN     1.044		      -
CMS_eff_{codename[0]}           lnN     1.02                      -
CMS_trigger_{codename[0]}       lnN     1.01                      -""".format(codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg,norm_obs=norm_obs,background_shapeSyst=background_shapeSyst[i])

    for i in range(0,len(background_shapeSyst)):
        card += """
{background_shapeSyst} shape  -                         1.0 """.format(codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg,norm_obs=norm_obs,i=i,background_shapeSyst=background_shapeSyst[i])
    card += """
sigXSsyst           lnN     1.034                     -""".format(codename=codename,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg,norm_obs=norm_obs,i=i,background_shapeSyst=background_shapeSyst[i])
    if (doSignalShape_unc):
        card += """
signalshape         shape1  1.0                       -
"""
    
    print card

    cardfile = open('wv_semil_%sboosted.txt'%(codename),'w')
    cardfile.write(card)
    cardfile.close
