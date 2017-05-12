#include <iostream>
#include "Hit.h"
#include "Module.h"
#include <stdio.h>
#include "Global.h"

Global* gData; //

int main()
{
  std::cout << "starting main program" << std::endl;
  
  Hit* hit_0 = new Hit();
  Hit* hit_1 = new Hit();
  hit_1->SetTime(1.2);
  
  std::vector<Hit*> hits;
  hits.push_back(hit_0);
  hits.push_back(hit_1);
  
  gData = &Global::getInstance(); //
  
  
  Module* module = new Module();
  module->Process(&hits);
  
  
  std::cout << " hit time of hit 0 = " << hit_0->GetTime() << std::endl;
  std::cout << " hit time of hit 1 = " << hit_1->GetTime() << std::endl;
  std::cout << " number of hits : " << hits.size() << std::endl;
  std::cout << " Hits in gData : " << gData->GeHitsSize() << std::endl;
  
  return 0;
}
