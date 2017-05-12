#ifndef Global_h__
#define Global_h__
#include "Hit.h"
#include <vector>
#include <iostream>
#include <stdio.h>

class Global
{


    public:
    
      //Hits		
      std::vector<Hit> hits;
      void AddHit(Hit hit) { hits.push_back(hit);}
      std::vector<Hit> GetHits() { return hits; }
      int GeHitsSize() { return hits.size(); }
      void ClearHits() { hits.clear(); }
      
      void ClearAll();
      
      int a = 2;
      int Test() {return a;}
      
      
    /* weird singleton stuff here, grabbed it from http://stackoverflow.com/questions/1008019/c-singleton-design-pattern */       

    public:
        static Global& getInstance()
        {
            static Global instance; // Guaranteed to be destroyed.
                                  // Instantiated on first use.
            return instance;
        }
        
        
    private:
        Global() {}                    // Constructor? (the {} brackets) are needed here.


        // C++ 11
        // =======
        // We can use the better technique of deleting the methods
        // we don't want.
    public:
        Global(Global const&) = delete;
        void operator=(Global const&)  = delete;

        // Note: Scott Meyers mentions in his Effective Modern
        //       C++ book, that deleted functions should generally
        //       be public as it results in better error messages
        //       due to the compilers behavior to check accessibility
        //       before deleted status
};

#endif
