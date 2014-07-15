void getYieldsFromInputFile(){

  gROOT->ProcessLine(".L /afs/cern.ch/work/s/senka/public/plotsForVgammaPaper/ptg/CMSstyle_YuriStyle.C");
  gROOT->ProcessLine("CMSstyle()");

  //  TFile * file_mu=new TFile("/afs/cern.ch/work/s/senka/newgit_atgc_testing_28022014/CMSSW_6_1_1/src/CombinedEWKAnalysis/CommonTools/data/WV_semileptonic/mu_boosted_withSignalSyst_adjustedUnc_c.root","read");
  //  TFile * file_mu=new TFile("/afs/cern.ch/work/s/senka/newgit_atgc_testing_28022014/CMSSW_6_1_1/src/CombinedEWKAnalysis/CommonTools/data/WV_semileptonic/elmu_boosted_withSignalSyst_adjustedUnc_c.root","read");
  TFile * file_mu=new TFile("/afs/cern.ch/work/s/senka/newgit_atgc_testing_28022014/CMSSW_6_1_1/src/CombinedEWKAnalysis/CommonTools/data/WV_semileptonic/el_boosted_withSignalSyst_adjustedUnc_c.root","read");
  file_mu->cd();
  TH1F * histo_SM=(TH1F*)(diboson->Clone("name_x"));
  
  //  TFile * file_mu_signal=new TFile("/afs/cern.ch/work/s/senka/newgit_atgc_testing_28022014/CMSSW_6_1_1/src/CombinedEWKAnalysis/CommonTools/data/WV_semileptonic/signal_mu_f5_c.root","read");
  //  TFile * file_mu_signal=new TFile("/afs/cern.ch/work/s/senka/newgit_atgc_testing_28022014/CMSSW_6_1_1/src/CombinedEWKAnalysis/CommonTools/data/WV_semileptonic/signal_elmu_f5_c.root","read");
  TFile * file_mu_signal=new TFile("/afs/cern.ch/work/s/senka/newgit_atgc_testing_28022014/CMSSW_6_1_1/src/CombinedEWKAnalysis/CommonTools/data/WV_semileptonic/signal_el_f5_c.root","read");

  file_mu_signal->cd();

  double f5z,f5g;
  int N_bin;

  double yield_bin1,yield_bin2,yield_bin3,yield_bin4,yield_bin5,yield_bin6;


  f5z=0.;
  f5g=0.;


  N_bin=1;
  yield_bin1=getYields(histo_SM,N_bin,bin_content_lam_dk_1,f5z,f5g);
  N_bin=2;
  yield_bin2=getYields(histo_SM,N_bin,bin_content_lam_dk_2,f5z,f5g);
  N_bin=3;
  yield_bin3=getYields(histo_SM,N_bin,bin_content_lam_dk_3,f5z,f5g);
  N_bin=4;
  yield_bin4=getYields(histo_SM,N_bin,bin_content_lam_dk_4,f5z,f5g);
  N_bin=5;
  yield_bin5=getYields(histo_SM,N_bin,bin_content_lam_dk_5,f5z,f5g);

  
  cout <<"\n\tpoint f5z: "<<f5z<<" f5g: "<< f5g << endl;
  cout << "mu: "<<yield_bin1<<"\t"<<yield_bin2<<"\t"<<yield_bin3<<"\t"<<yield_bin4<<"\t"<<yield_bin5 << endl;

  f5z=0.01;
  f5g=0.;
  N_bin=1;
  yield_bin1=getYields(histo_SM,N_bin,bin_content_lam_dk_1,f5z,f5g);
  N_bin=2;
  yield_bin2=getYields(histo_SM,N_bin,bin_content_lam_dk_2,f5z,f5g);
  N_bin=3;
  yield_bin3=getYields(histo_SM,N_bin,bin_content_lam_dk_3,f5z,f5g);
  N_bin=4;
  yield_bin4=getYields(histo_SM,N_bin,bin_content_lam_dk_4,f5z,f5g);
  N_bin=5;
  yield_bin5=getYields(histo_SM,N_bin,bin_content_lam_dk_5,f5z,f5g);  
  cout <<"\n\tpoint f5z: "<<f5z<<" f5g: "<< f5g << endl;
  cout << "mu: "<<yield_bin1<<"\t"<<yield_bin2<<"\t"<<yield_bin3<<"\t"<<yield_bin4<<"\t"<<yield_bin5 << endl;

  f5z=-0.01;
  f5g=0.;
  N_bin=1;
  yield_bin1=getYields(histo_SM,N_bin,bin_content_lam_dk_1,f5z,f5g);
  N_bin=2;
  yield_bin2=getYields(histo_SM,N_bin,bin_content_lam_dk_2,f5z,f5g);
  N_bin=3;
  yield_bin3=getYields(histo_SM,N_bin,bin_content_lam_dk_3,f5z,f5g);
  N_bin=4;
  yield_bin4=getYields(histo_SM,N_bin,bin_content_lam_dk_4,f5z,f5g);
  N_bin=5;
  yield_bin5=getYields(histo_SM,N_bin,bin_content_lam_dk_5,f5z,f5g);  
  cout <<"\n\tpoint f5z: "<<f5z<<" f5g: "<< f5g << endl;
  cout << "mu: "<<yield_bin1<<"\t"<<yield_bin2<<"\t"<<yield_bin3<<"\t"<<yield_bin4<<"\t"<<yield_bin5 << endl;

  f5z=0.;
  f5g=0.015;
  N_bin=1;
  yield_bin1=getYields(histo_SM,N_bin,bin_content_lam_dk_1,f5z,f5g);
  N_bin=2;
  yield_bin2=getYields(histo_SM,N_bin,bin_content_lam_dk_2,f5z,f5g);
  N_bin=3;
  yield_bin3=getYields(histo_SM,N_bin,bin_content_lam_dk_3,f5z,f5g);
  N_bin=4;
  yield_bin4=getYields(histo_SM,N_bin,bin_content_lam_dk_4,f5z,f5g);
  N_bin=5;
  yield_bin5=getYields(histo_SM,N_bin,bin_content_lam_dk_5,f5z,f5g);  
  cout <<"\n\tpoint f5z: "<<f5z<<" f5g: "<< f5g << endl;
  cout << "mu: "<<yield_bin1<<"\t"<<yield_bin2<<"\t"<<yield_bin3<<"\t"<<yield_bin4<<"\t"<<yield_bin5 << endl;

  f5z=0.;
  f5g=-0.015;
  N_bin=1;
  yield_bin1=getYields(histo_SM,N_bin,bin_content_lam_dk_1,f5z,f5g);
  N_bin=2;
  yield_bin2=getYields(histo_SM,N_bin,bin_content_lam_dk_2,f5z,f5g);
  N_bin=3;
  yield_bin3=getYields(histo_SM,N_bin,bin_content_lam_dk_3,f5z,f5g);
  N_bin=4;
  yield_bin4=getYields(histo_SM,N_bin,bin_content_lam_dk_4,f5z,f5g);
  N_bin=5;
  yield_bin5=getYields(histo_SM,N_bin,bin_content_lam_dk_5,f5z,f5g);  
  cout <<"\n\tpoint f5z: "<<f5z<<" f5g: "<< f5g << endl;
  cout << "mu: "<<yield_bin1<<"\t"<<yield_bin2<<"\t"<<yield_bin3<<"\t"<<yield_bin4<<"\t"<<yield_bin5 << endl;

}

double getYields(TH1F * histo_SM,int N_bin,TH2D * histo_signal, double f5z, double f5g){

  int N_bin_2d=histo_signal->FindBin(f5z, f5g);
  double factor=histo_signal->GetBinContent(N_bin_2d);
  double yield=0.;
  yield=histo_SM->GetBinContent(N_bin)*factor;

  return yield;

}
