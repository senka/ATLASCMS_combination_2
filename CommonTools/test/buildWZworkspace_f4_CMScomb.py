import pyroot_logon
import limits
import os
import sys

from array import *


from ROOT import *

lType = sys.argv[1]
codename = ""
planeID = sys.argv[2]

norm_sig_sm = -1
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

if( lType == "muon" ) :
    codename = "mu"
elif( lType == "electron" ):
    codename = "el"
elif( lType == "electronmuon" ):
    codename = "elmu"
else:
    raise RuntimeError('InvalidLepton','You may only choose between "muon" and "electron" channels.')

basepath = '%s/src/CombinedEWKAnalysis/CommonTools/data/WV_semileptonic'%os.environ['CMSSW_BASE']

f = TFile('%s/%s_boosted.root'%(basepath,codename))

background = f.Get('background')
background_backshapeUp = f.Get('background_%sboosted_backshapeUp'%codename)
background_backshapeDown = f.Get('background_%sboosted_backshapeDown'%codename)
data_obs = f.Get('data_obs')
diboson = f.Get('diboson')

#background.Add(diboson, -1.)

norm_sig_sm = diboson.Integral()
norm_bkg = background.Integral()
norm_obs = data_obs.Integral()

theWS = RooWorkspace('WV_%sboosted'%codename, 'WV_%sboosted'%codename)

wpt = theWS.factory('W_pt_%s[%f,%f]' % (codename,data_obs.GetBinLowEdge(1), 
                                     data_obs.GetBinLowEdge(data_obs.GetNbinsX())+data_obs.GetBinWidth(data_obs.GetNbinsX())))

#binning=data_obs.getBinning()
binning=array('d',[])
#a.append(6)

#binning=[]
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
#wpt.setBinning(RooBinning(binning))
#wpt.setBinning(RooBinning(len(binning)-1,binning))
#{ setBinning(RooUniformBinning(getMin(name),getMax(name),nBins),name) ; }
#RooBinning(Int_t nBins, const Double_t* boundaries, const char* name = 0)

#wpt.setBins(data_obs.GetNbinsX())

lz = theWS.factory('lZ[0., -0.06, 0.06]')
# lz = theWS.factory('lZ[0.]')
lz.setConstant(False)
dkg = theWS.factory('dkg[0.,-0.06, 0.06]')
dg1 = theWS.factory('dg1[0.,-0.06, 0.06]')


vars = RooArgList(wpt)
varSet = RooArgSet(wpt)

data = RooDataHist('data_obs', 'data_obs_WV_%s'%codename, vars, data_obs)
bkgHist = RooDataHist('WV_semileptonic_bkg_%s'%codename,
                      'WV_semileptonic_bkg_%s'%codename,
                      vars,
                      background)
bkgHist_systUp = RooDataHist('WV_semileptonic_bkg_%s_%sboosted_backshapeUp'%(codename,codename),
                             'WV_semileptonic_bkg_%s_%sboosted_backshapeUp'%(codename,codename),
                             vars,
                             background_backshapeUp)
bkgHist_systDown = RooDataHist('WV_semileptonic_bkg_%s_%sboosted_backshapeDown'%(codename,
                                                                                 codename),
                               'WV_semileptonic_bkg_%s_%sboosted_backshapeDown'%(codename,
                                                                                 codename),
                               vars,
                               background_backshapeDown)

dibosonHist = RooDataHist('WV_semileptonic_SM_%s_rawshape'%codename,
                          'WV_semileptonic_SM_%s_rawshape'%codename,
                          vars,
                          diboson)
dibosonPdf = RooHistFunc('WV_semileptonic_SM_%s_shape'%codename,
                         'WV_semileptonic_SM_%s_shape'%codename,
                         varSet,
                         dibosonHist)


print '\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ read RooATGCFunction ', '%s/signal_%s_f4.root'%(basepath,codename)
print '\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ reading RooATGCFunction\n'
aTGC = RooATGCFunction_wz('ATGC_shapescale_WWgammaZ_WV_atgc_semileptonic_%s'%codename,
                       'ATGC_shapescale_%s'%codename,
                       wpt,
                       lz,
                       dkg,
                       dg1, 
                       '%s/signal_%s_f4.root'%(basepath,codename))

print '\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ read RooATGCFunction\n'
limtype = -1

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
print '\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ read RooATGCFunction ', '%s/signal_%s_f4.root'%(basepath,codename)
aTGCPdf = RooATGCSemiAnalyticPdf_wz('ATGCPdf_WWgammaZ_WV_atgc_semileptonic_%s'%codename,
                                 'ATGCPdf_WV_%s'%codename,
                                 wpt,
                                 dkg,
                                 lz,                                 
                                 dg1,
                                 dibosonPdf,
#                                 dibosonHist,
                                 '%s/signal_%s_f4.root'%(basepath,codename),
                                 limtype)

#aTGCPdf = RooHistPdf('ATGCPdf_WWgammaZ_WV_atgc_semileptonic_%s'%codename,
#                     'ATGCPdf_WV_%s'%codename,
#                     ,varSet,*hist1,0
#                     )

#	RooHistPdf(const RooHistPdf& other, const char* name = 0)
#	RooHistPdf(const char* name, const char* title, const RooArgSet& vars, const RooDataHist& dhist, Int_t intOrder = 0)
#	RooHistPdf(const char* name, const char* title, const RooArgList& pdfObs, const RooArgList& histObs, const RooDataHist& dhist, Int_t intOrder = 0)
#vars = RooArgList(wpt)
#varSet = RooArgSet(wpt)

#aTGCPdf = RooHistPdf()
#// Sample 500 events from p
#  x.setBins(20) ;
#  RooDataSet* data1 = p.generate(x,500) ;
#  
#  // Create a binned dataset with 20 bins and 500 events
#  RooDataHist* hist1 = data1->binnedClone() ;
#
#  // Represent data in dh as pdf in x
#  RooHistPdf histpdf1("histpdf1","histpdf1",x,*hist1,0) ;


print '\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ read RooATGCSemi\n'

getattr(theWS, 'import')(data)
getattr(theWS, 'import')(bkgHist)
getattr(theWS, 'import')(bkgHist_systUp)
getattr(theWS, 'import')(bkgHist_systDown)
getattr(theWS, 'import')(aTGCPdf)

theWS.Print()

fout = TFile('%s_boosted_%s_ws.root'%(codename,planeID), 'recreate')
theWS.Write()
fout.Close()

### make the card for this channel and plane ID
card = """
# Simple counting experiment, with one signal and a few background processes 
imax 1  number of channels
jmax 1  number of backgrounds
kmax *  number of nuisance parameters (sources of systematical uncertainties)
------------
shapes WV_semileptonic_bkg_{codename}  {codename}boosted ./{codename}_boosted_{planeID}_ws.root WV_{codename}boosted:$PROCESS WV_{codename}boosted:$PROCESS_$SYSTEMATIC
shapes data_obs                {codename}boosted ./{codename}_boosted_{planeID}_ws.root WV_{codename}boosted:$PROCESS
shapes WWgammaZ_WV_atgc_semileptonic_{codename} {codename}boosted ./{codename}_boosted_{planeID}_ws.root WV_{codename}boosted:ATGCPdf_$PROCESS
------------
bin {codename}boosted 
observation {norm_obs}
------------
bin                         {codename}boosted		      {codename}boosted
process                     WWgammaZ_WV_atgc_semileptonic_{codename}   WV_semileptonic_bkg_{codename}
process                     0			      1		
rate                        {norm_sig_sm}		      {norm_bkg}	

------------
lumi_8TeV           lnN     1.022		      -
{codename}boosted_backshape shape1  -                         1.0 
sig_th           lnN     1.04                    -
sig_other           lnN     1.1342                     -
""".format(codename=codename,planeID=planeID,norm_sig_sm=norm_sig_sm,norm_bkg=norm_bkg,norm_obs=norm_obs)

print card

cardfile = open('wv_semil_%sboosted_%s.txt'%(codename,planeID),'w')
cardfile.write(card)
cardfile.close
