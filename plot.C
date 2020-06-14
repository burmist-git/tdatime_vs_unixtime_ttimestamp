{
  TFile f("tDatime_vs_unixTime_tTimeStamp.root");
  //
  TTreeReader rdr_ut("T",&f);
  TTreeReaderValue<Int_t> ut_v(rdr_ut, "ut");
  //
  TTreeReader rdr_rdt("T",&f);
  TTreeReaderValue<UInt_t> rdt_v(rdr_rdt, "rdt");
  //
  TTreeReader rdr_tts("T",&f);
  TTreeReaderValue<Int_t> tts_v(rdr_tts, "tts");
  //
  TGraph *gr_ut = new TGraph();
  TGraph *gr_rdt = new TGraph();
  TGraph *gr_tts = new TGraph();

  //
  gr_ut->SetMinimum(0.0);
  gr_rdt->SetMinimum(0.0);
  gr_tts->SetMinimum(0.0);
  //
  gr_ut->SetMaximum(2.0);
  gr_rdt->SetMaximum(2.0);
  gr_tts->SetMaximum(2.0);

  while (rdr_ut.Next())
    gr_ut->SetPoint(gr_ut->GetN(), *ut_v, 1.0);
  while (rdr_rdt.Next())
    gr_rdt->SetPoint(gr_rdt->GetN(), *rdt_v, 1.0);
  while (rdr_tts.Next())
    gr_tts->SetPoint(gr_tts->GetN(), *tts_v, 1.0);

  gStyle->SetPalette(kRainBow);
  TCanvas *c1 = new TCanvas("c1","c1",10,10,800,1200);
  c1->SetTitle("tDatime_vs_unixTime_tTimeStamp");
  c1->SetName("tDatime_vs_unixTime_tTimeStamp");
  c1->SetRightMargin(0.12);
  c1->SetLeftMargin(0.12);
  c1->SetTopMargin(0.1);
  c1->SetBottomMargin(0.15);
  c1->Divide(1,3);
  //
  c1->cd(1);
  gr_ut->SetMarkerStyle(20);
  gr_ut->Draw("APL");
  gr_ut->GetXaxis()->SetTimeDisplay(1);
  gr_ut->GetXaxis()->SetTimeFormat("#splitline{%m/%d}{%H:%M:%S}%F1970-01-01 00:00:00");
  gr_ut->GetXaxis()->SetLabelOffset(0.025);
  //gr_ut->GetXaxis()->SetTitle("Time, h");
  //
  c1->cd(2);
  gr_rdt->SetMarkerStyle(20);
  gr_rdt->Draw("APL");
  gr_rdt->GetXaxis()->SetTimeDisplay(1);
  gr_rdt->GetXaxis()->SetTimeFormat("#splitline{%m/%d}{%H:%M:%S}%F1970-01-01 00:00:00"); 
  gr_rdt->GetXaxis()->SetLabelOffset(0.025);
  //
  c1->cd(3);
  gr_tts->SetMarkerStyle(20);
  gr_tts->Draw("APL");
  gr_tts->GetXaxis()->SetTimeDisplay(1);
  gr_tts->GetXaxis()->SetTimeFormat("#splitline{%m/%d}{%H:%M:%S}%F1970-01-01 00:00:00"); 
  gr_tts->GetXaxis()->SetLabelOffset(0.025);
}
