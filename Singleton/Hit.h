#ifndef Hit_h
#define Hit_h



////////////////////////////////////////////////////////////////////////////////
// Hit Class
////////////////////////////////////////////////////////////////////////////////

class Hit {

 public:
  //constructor
  Hit();
  ~Hit();
  
  /* Get Methods */
  double GetTime() {return time;}
  
  /* Set methods */
  void SetTime(double value) { time = value; }
  
 private:
   
   double time; //time in ns


};

#endif

