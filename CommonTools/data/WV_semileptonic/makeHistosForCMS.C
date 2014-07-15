void makeHistosForCMS(){

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

  for (int i=1;i<6;i++){
    double yield=diboson_mu_tmp->GetBinContent(i);
    signal_mu_thUp->SetBinContent(i,yield*1.04);
    signal_mu_thDown->SetBinContent(i,yield*0.96);
  }

  TFile * file_mu_out=new TFile("mu_boosted_withSignalSyst_signalSyst_adjustedUnc.root","recreate");
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

  for (int i=1;i<6;i++){
    double yield=diboson_el_tmp->GetBinContent(i);
    signal_el_thUp->SetBinContent(i,yield*1.04);
    signal_el_thDown->SetBinContent(i,yield*0.96);
  }

  TFile * file_el_out=new TFile("el_boosted_withSignalSyst_signalSyst_adjustedUnc.root","recreate");
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

  for (int i=1;i<6;i++){
    double yield=diboson_elmu_tmp->GetBinContent(i);
    signal_elmu_thUp->SetBinContent(i,yield*1.04);
    signal_elmu_thDown->SetBinContent(i,yield*0.96);
  }

  TFile * file_elmu_out=new TFile("elmu_boosted_withSignalSyst_signalSyst_adjustedUnc.root","recreate");
  file_elmu_out->cd();
  diboson_elmu_tmp->Write("diboson");
  data_obs_elmu_tmp->Write("data_obs");
  background_elmu_tmp->Write("background");
  background_elmuboosted_backshapeUp_elmu_tmp->Write("background_elmuboosted_backshapeUp");
  background_elmuboosted_backshapeDown_elmu_tmp->Write("background_elmuboosted_backshapeDown");
  signal_elmu_thUp->Write("signal_thUp");
  signal_elmu_thDown->Write("signal_thDown");




}
