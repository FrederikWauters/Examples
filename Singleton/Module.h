#ifndef Module_h
#define Module_h

#include "Hit.h"
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Module Class
////////////////////////////////////////////////////////////////////////////////

class Module {

 public:
  //constructor
  Module();
  ~Module();
  
  /* Methods */
    void Process(std::vector<Hit*>* hits);
    void Process();
  
 private:
   std::vector<Hit> localHits;

};

#endif
