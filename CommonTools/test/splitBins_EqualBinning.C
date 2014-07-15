void splitBins_EqualBinning(TString file_name){

  TFile * file_in=new TFile(file_name,"read");
  file_in->cd();
  file_in.ls();

  //  TList * input_p=file_in->GetList();
  TList * list_histos=file_in->GetListOfKeys();

  TString histo_name_1= list_histos->At(0)->GetName();
  TH1D * plot_1=file_in->Get(histo_name_1);
  int N_bins_1=plot_1->GetNbinsX();
  TString file_out_start=file_name.Remove(file_name.Length() - 5, 5);

  for (int k=1;k<N_bins_1+1;k++){
    TString file_out=file_out_start;
    file_out+="_splitted_bin";

    char b[2];
    sprintf(b,"%f",k);
    //    if (lambda<0) b[4]=0;
    //    else b[3]=0;
    b[1]=0;
    //    root_in_name_71="ime_";
    //    root_in_name_71+=string(b);  // na kraju je moje root_in_name_71 = "ime_-0.2"

    file_out+=string(b);
    file_out+=".root";
    
    cout <<" ----> output: "<< file_out<<"\n" << endl;
    TFile *outFile=new TFile(file_out,"recreate");
    outFile->cd();
    
    for (int i=0;i<list_histos->GetEntries();i++){
      TString histo_name= list_histos->At(i)->GetName();
      
      TH1D * plot=file_in->Get(histo_name);
      //    cout << " plot \""<<histo_name<<"\""<< endl;
      cout <<"\treading histo \""<< histo_name<< "\" and rebinning.." << endl;
      int N_bins=plot->GetNbinsX();
      TH1D * plot_rebin=new TH1D("plot_rebin","plot_rebin",1,0,1);
      //      for (int j=1;j<=N_bins;j++)
      plot_rebin->SetBinContent(1,plot->GetBinContent(k));
      cout <<"\t\tbin yield starting: "<< plot->Integral()<<" after rebinning: "<<plot_rebin->Integral()  << endl;
      plot_rebin->Write(histo_name);
      delete plot_rebin;
    }
    
    outFile->Close();
    //    file_in->Close();
  }

}
