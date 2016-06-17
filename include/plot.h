#pragma once
#include "TH1F.h"
#include "TApplication.h"
#include "TRint.h"

void init_plot()
{
	TApplication *myapp=new TApplication("myapp",0,0);
TH1F *h=new TH1F("h","Test",100,-10,10);
h->FillRandom("gaus",100000);
h->Draw();
myapp->Run();

}