void getYieldsFromWS(){

   TFile * file=new TFile("Example_ATGC_WV_elmu_workspace_dkglZ_f5_CMS_adjustedUnc_noUnc.root","read");
  gROOT->ProcessLine(".L /afs/cern.ch/work/s/senka/public/plotsForVgammaPaper/ptg/CMSstyle_YuriStyle.C");
  gROOT->ProcessLine("CMSstyle()");

  cout <<"open" << endl;
  file->cd();
  gSystem->Load("libHiggsAnalysisCombinedLimit");
  w->cd();
  
  

}
