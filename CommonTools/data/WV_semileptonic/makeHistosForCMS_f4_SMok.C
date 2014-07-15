void makeHistosForCMS_f4_SMok(){

  ///////////////////////////////////////////////////
  //
  //             muons
  //

  TH1D * diboson_mu_tmp=new TH1D();
  TH1D * data_obs_mu_tmp=new TH1D();
  TH1D * background_mu_tmp=new TH1D();
  TH1D * background_muboosted_backshapeUp_mu_tmp=new TH1D();
  TH1D * background_muboosted_backshapeDown_mu_tmp=new TH1D();
  TH1D * signal_mu_thUp=new TH1D("signal_mu_thUp","signal_mu_thUp",5,0,5.);
  TH1D * signal_mu_thDown=new TH1D("signal_mu_thDown","signal_mu_thDown",5,0,5.);
  

  TFile * file_mu=new TFile("mu_boosted_withSignalSyst_adjustedUnc_c.root","read");
  file_mu->cd();
  diboson_mu_tmp=(TH1D*)(diboson->Clone("name_1"));
  data_obs_mu_tmp=(TH1D*)(data_obs->Clone("naem_2"));
  background_mu_tmp=(TH1D*)(background->Clone("name_3"));
  background_muboosted_backshapeUp_mu_tmp=(TH1D*)(background_muboosted_backshapeUp->Clone("background_muboosted_backshapeUp_x"));
  background_muboosted_backshapeDown_mu_tmp=(TH1D*)(background_muboosted_backshapeDown->Clone("background_muboosted_backshapeDown_x"));

  diboson_mu_tmp->SetBinContent(1,2.78309693783);
  diboson_mu_tmp->SetBinContent(2,8.67996193618);
  diboson_mu_tmp->SetBinContent(3,2.06339973775);
  diboson_mu_tmp->SetBinContent(4,0.844626936488);
  diboson_mu_tmp->SetBinContent(5,0.214578290026);

  for (int i=1;i<6;i++){
    double yield=diboson_mu_tmp->GetBinContent(i);
    signal_mu_thUp->SetBinContent(i,yield*1.04);
    signal_mu_thDown->SetBinContent(i,yield*0.96);
  }

  /*
# Fij weights per bin (F00, F01, F02, F03, F04, F11, F12, F13, F14, F22, F23, F24, F33, F34, F44)
2.78309693783	0.0915546834948	0.695338794577	0.0	0.0	207.979851246	12.9221681452	0.0	0.0	101.671064284	0.0	0.0	0.0	0.0	0.0
8.67996193618	2.34549076759	-3.2207212521	0.0	0.0	321.944939257	-22.6826939995	0.0	0.0	240.9606163	0.0	0.0	0.0	0.0	0.0
2.06339973775	-0.763609194497	0.864552912977	0.0	0.0	145.719185034	82.5314001408	0.0	0.0	183.041483692	0.0	0.0	0.0	0.0	0.0
0.844626936488	-0.77001489122	0.0935490685487	0.0	0.0	471.20937805	384.338573508	0.0	0.0	575.295471938	0.0	0.0	0.0	0.0	0.0
0.214578290026	-0.245270119428	-3.52376388639	0.0	0.0	3575.3607009	3195.36457216	0.0	0.0	4780.18845802	0.0	0.0	0.0	0.0	0.0
  */


  TFile * file_mu_out=new TFile("mu_boosted_withSignalSyst_signalSyst_adjustedUnc_f4_SMok.root","recreate");
  file_mu_out->cd();
  diboson_mu_tmp->Write("diboson");
  data_obs_mu_tmp->Write("data_obs");
  background_mu_tmp->Write("background");
  background_muboosted_backshapeUp_mu_tmp->Write("background_muboosted_backshapeUp");
  background_muboosted_backshapeDown_mu_tmp->Write("background_muboosted_backshapeDown");
  signal_mu_thUp->Write("signal_thUp");
  signal_mu_thDown->Write("signal_thDown");



  ///////////////////////////////////////////////////
  //
  //             electrons
  //

  TH1D * diboson_el_tmp=new TH1D();
  TH1D * data_obs_el_tmp=new TH1D();
  TH1D * background_el_tmp=new TH1D();
  TH1D * background_elboosted_backshapeUp_el_tmp=new TH1D();
  TH1D * background_elboosted_backshapeDown_el_tmp=new TH1D();
  TH1D * signal_el_thUp=new TH1D("signal_el_thUp","signal_el_thUp",5,0,5.);
  TH1D * signal_el_thDown=new TH1D("signal_el_thDown","signal_el_thDown",5,0,5.);
  

  TFile * file_el=new TFile("el_boosted_withSignalSyst_adjustedUnc_c.root","read");
  file_el->cd();
  diboson_el_tmp=(TH1D*)(diboson->Clone("name_1y"));
  data_obs_el_tmp=(TH1D*)(data_obs->Clone("data_obsy"));
  background_el_tmp=(TH1D*)(background->Clone("data_oy"));
  background_elboosted_backshapeUp_el_tmp=(TH1D*)(background_elboosted_backshapeUp->Clone("background_elboosted_backshapeUpy"));
  background_elboosted_backshapeDown_el_tmp=(TH1D*)(background_elboosted_backshapeDown->Clone("background_elboosted_backshapeDowny"));

  diboson_el_tmp->SetBinContent(1,2.02380870661);
  diboson_el_tmp->SetBinContent(2,5.52438796359);
  diboson_el_tmp->SetBinContent(3,1.240831915);
  diboson_el_tmp->SetBinContent(4,0.517862150855);
  diboson_el_tmp->SetBinContent(5,0.0995512020637);

  for (int i=1;i<6;i++){
    double yield=diboson_el_tmp->GetBinContent(i);
    signal_el_thUp->SetBinContent(i,yield*1.04);
    signal_el_thDown->SetBinContent(i,yield*0.96);
  }

  /*
# Fij weights per bin (F00, F01, F02, F03, F04, F11, F12, F13, F14, F22, F23, F24, F33, F34, F44)
2.02380870661	0.301265079627	-0.813752762468	0.0	0.0	107.550549796	3.84746730342	0.0	0.0	69.6063145287	0.0	0.0	0.0	0.0	0.0
5.52438796359	-0.0821540919863	0.583268562788	0.0	0.0	256.47429797	20.805614858	0.0	0.0	97.978839954	0.0	0.0	0.0	0.0	0.0
1.240831915	-0.439357400801	-0.156215752517	0.0	0.0	115.206763679	31.7742768061	0.0	0.0	119.31238533	0.0	0.0	0.0	0.0	0.0
0.517862150855	-0.145569502105	0.0549800737342	0.0	0.0	274.825149796	258.411275938	0.0	0.0	391.681396593	0.0	0.0	0.0	0.0	0.0
0.0995512020637	-4.10682592739	-1.82735116774	0.0	0.0	2138.3377182	1947.19150855	0.0	0.0	2939.33047705	0.0	0.0	0.0	0.0	0.0


  */



  TFile * file_el_out=new TFile("el_boosted_withSignalSyst_signalSyst_adjustedUnc_f4_SMok.root","recreate");
  file_el_out->cd();
  diboson_el_tmp->Write("diboson");
  data_obs_el_tmp->Write("data_obs");
  background_el_tmp->Write("background");
  background_elboosted_backshapeUp_el_tmp->Write("background_elboosted_backshapeUp");
  background_elboosted_backshapeDown_el_tmp->Write("background_elboosted_backshapeDown");
  signal_el_thUp->Write("signal_thUp");
  signal_el_thDown->Write("signal_thDown");



  ///////////////////////////////////////////////////
  //
  //             electronMuon
  //

  TH1D * diboson_elmu_tmp=new TH1D();
  TH1D * data_obs_elmu_tmp=new TH1D();
  TH1D * background_elmu_tmp=new TH1D();
  TH1D * background_elmuboosted_backshapeUp_elmu_tmp=new TH1D();
  TH1D * background_elmuboosted_backshapeDown_elmu_tmp=new TH1D();
  TH1D * signal_elmu_thUp=new TH1D("signal_elmu_thUp","signal_elmu_thUp",5,0,5.);
  TH1D * signal_elmu_thDown=new TH1D("signal_elmu_thDown","signal_elmu_thDown",5,0,5.);
  

  TFile * file_elmu=new TFile("elmu_boosted_withSignalSyst_adjustedUnc_c.root","read");
  file_elmu->cd();
  diboson_elmu_tmp=(TH1D*)(diboson->Clone("name_1z"));
  data_obs_elmu_tmp=(TH1D*)(data_obs->Clone("data_obsz"));
  background_elmu_tmp=(TH1D*)(background->Clone("data_oz"));
  background_elmuboosted_backshapeUp_elmu_tmp=(TH1D*)(background_elmuboosted_backshapeUp->Clone("background_elmuboosted_backshapeUpz"));
  background_elmuboosted_backshapeDown_elmu_tmp=(TH1D*)(background_elmuboosted_backshapeDown->Clone("background_elmuboosted_backshapeDownz"));


  diboson_elmu_tmp->SetBinContent(1,5.02945739738);
  diboson_elmu_tmp->SetBinContent(2,14.1271463846);
  diboson_elmu_tmp->SetBinContent(3,3.19685647326);
  diboson_elmu_tmp->SetBinContent(4,1.44241262784);
  diboson_elmu_tmp->SetBinContent(5,0.329822973279);

  for (int i=1;i<6;i++){
    double yield=diboson_elmu_tmp->GetBinContent(i);
    signal_elmu_thUp->SetBinContent(i,yield*1.04);
    signal_elmu_thDown->SetBinContent(i,yield*0.96);
  }

  /*
# Fij weights per bin (F00, F01, F02, F03, F04, F11, F12, F13, F14, F22, F23, F24, F33, F34, F44)
5.02945739738	-1.04671015987	0.56601532765	0.0	0.0	142.755884943	-12.8348503188	0.0	0.0	127.193010224	0.0	0.0	0.0	0.0	0.0
14.1271463846	-3.15816960833	-2.16267258979	0.0	0.0	451.616001629	34.9805122953	0.0	0.0	313.317116383	0.0	0.0	0.0	0.0	0.0
3.19685647326	0.330560500551	-0.340082832046	0.0	0.0	314.354239137	151.821953103	0.0	0.0	289.176445613	0.0	0.0	0.0	0.0	0.0
1.44241262784	-1.14758048322	-2.93148234915	0.0	0.0	657.02927732	617.620248582	0.0	0.0	1025.62573142	0.0	0.0	0.0	0.0	0.0
0.329822973279	-7.98611271558	-3.19871517589	0.0	0.0	5395.21721182	4836.82341159	0.0	0.0	7511.06752359	0.0	0.0	0.0	0.0	0.0

  */


  TFile * file_elmu_out=new TFile("elmu_boosted_withSignalSyst_signalSyst_adjustedUnc_f4_SMok.root","recreate");
  file_elmu_out->cd();
  diboson_elmu_tmp->Write("diboson");
  data_obs_elmu_tmp->Write("data_obs");
  background_elmu_tmp->Write("background");
  background_elmuboosted_backshapeUp_elmu_tmp->Write("background_elmuboosted_backshapeUp");
  background_elmuboosted_backshapeDown_elmu_tmp->Write("background_elmuboosted_backshapeDown");
  signal_elmu_thUp->Write("signal_thUp");
  signal_elmu_thDown->Write("signal_thDown");




}
