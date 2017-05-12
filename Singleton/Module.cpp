#include "Module.h"
#include "Global.h"
#include "Hit.h"
#include <stdio.h>

extern Global* gData;

Module::Module() 
{
  printf("Construction Module\n");
}

Module::~Module()
{

}

void Module::Process(std::vector<Hit*>* hits)
{
  printf("Processing hits\n");
  if(hits->size() > 0)
  {
    hits->at(0)->SetTime(1.34);
  }
  
  printf("Singleton test: %d \n", gData->Test());
  gData->ClearHits();

  //gData->ClearHits();
  for(int i = 0; i < hits->size(); i ++)
  {
     gData->AddHit(*hits->at(i));
  }
  
  
}

void Module::Process()
{

}
