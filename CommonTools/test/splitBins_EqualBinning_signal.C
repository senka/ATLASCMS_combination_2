void splitBins_EqualBinning_signal(TString file_name){

  TFile * file_in=new TFile(file_name,"read");
  file_in->cd();
  file_in.ls();

  //  TList * input_p=file_in->GetList();
  TList * list_histos=file_in->GetListOfKeys();

  TString histo_name_1= list_histos->At(0)->GetName();
  TH1D * plot_1=file_in->Get(histo_name_1);
  int N_bins_1=plot_1->GetNbinsX();
  TString file_out_start=file_name.Remove(file_name.Length() - 5, 5);

  //  for (int k=1;k<N_bins_1+1;k++){
    
    for (int i=0;i<list_histos->GetEntries();i++){
    TString file_out=file_out_start;
    file_out+="_signal_splitted_bin";

   //    j=(i/2)
      TString histo_name= list_histos->At(i)->GetName();
      cout << "\n\n\t\t========> new histo: "<< histo_name<< endl;
      if (histo_name=="bin_content_lam_dk_1")
	{
	  char b[2];
	  sprintf(b,"%f",1);
	  b[1]=0;
	  file_out+=string(b);
	  file_out+=".root";    
	  cout <<" ----> output: "<< file_out<<"\n" << endl;
	}
      else if (histo_name=="bin_content_lam_dk_2")
	{
	  char b[2];
	  sprintf(b,"%f",2);
	  b[1]=0;
	  file_out+=string(b);
	  file_out+=".root";    
	  cout <<" ----> output: "<< file_out<<"\n" << endl;
	}
      else if (histo_name=="bin_content_lam_dk_3")
	{
	  char b[2];
	  sprintf(b,"%f",3);
	  b[1]=0;
	  file_out+=string(b);
	  file_out+=".root";    
	  cout <<" ----> output: "<< file_out<<"\n" << endl;
	}
      else if (histo_name=="bin_content_lam_dk_4")
	{
	  char b[2];
	  sprintf(b,"%f",4);
	  b[1]=0;
	  file_out+=string(b);
	  file_out+=".root";    
	  cout <<" ----> output: "<< file_out<<"\n" << endl;
	}
      else {
	  char b[3];
	  sprintf(b,"%f",100);
	  b[2]=0;
	  file_out+=string(b);
	  file_out+=".root";    
	  cout <<" ----> output: "<< file_out<<"\n" << endl;	
      }

    TFile *outFile=new TFile(file_out,"recreate");
    outFile->cd();

       //      TString histo_name_2= list_histos->At(i)->GetName();
      
      TH2D * plot=file_in->Get(histo_name);
      //    cout << " plot \""<<histo_name<<"\""<< endl;
      cout <<"\treading histo \""<< histo_name<< "\" and rebinning.." << endl;
      int N_bins=plot->GetNbinsX();
      //      TH2D * plot_rebin=new TH2D();
      //      for (int j=1;j<=N_bins;j++)
      plot_rebin=(TH2D*)(plot->Clone("somename"));
      cout <<"\t\tbin yield starting: "<< plot->Integral()<<" after rebinning: "<<plot_rebin->Integral()  << endl;
      histo_name=histo_name.ReplaceAll("_2","_1");
      histo_name=histo_name.ReplaceAll("_3","_1");
      histo_name=histo_name.ReplaceAll("_4","_1");
      plot_rebin->Write(histo_name);
      delete plot_rebin;
    outFile->Close();
    }
    
    //    file_in->Close();
    //  }

}
