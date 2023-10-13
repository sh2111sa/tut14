{
   //Draw a simple graph
   // To see the output of this macro, click begin_html <a href="gif/graph.gif">here</a>. end_html
   //Author: Rene Brun
   
   TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,700,500);

   c1->SetFillColor(42);
   c1->SetGrid();

   const Int_t n = 20;
   Double_t x[n], y[n];
   for (Int_t i=0;i<n;i++) {
     x[i] = i*0.1;
     y[i] = 10*sin(x[i]+0.2);
     printf(" i %i %f %f \n",i,x[i],y[i]);
   }
   gr = new TGraph(n,x,y);
   gr->AddPoint(2.5, 6); 
   gr->AddPoint(3,4);
   gr->SetLineColor(2);
   gr->SetLineWidth(4);
   gr->SetMarkerColor(4);
   gr->SetMarkerStyle(21);
   gr->SetTitle("a simple graph");
   gr->GetXaxis()->SetTitle("X title");
   gr->GetYaxis()->SetTitle("Y title");
   gr->GetXaxis()->CenterTitle(true);
   gr->Draw();
   TArrow *ar1 = new TArrow(1,5,x[6],y[6]);
   ar1->SetAngle(40);
   ar1->SetLineWidth(2);
   ar1->Draw("same");
   
   TArrow *ar2 = new TArrow(1,5,x[19],y[19]);
   ar2->SetAngle(40);
   ar2->SetLineWidth(2);
   ar2->Draw("same");
  

   // TCanvas::Update() draws the frame, after which one can change it
   c1->Update();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);
   c1->Modified();
   TFile f1("graph2.root","RECREATE");
   gr->Write("graph2");
}