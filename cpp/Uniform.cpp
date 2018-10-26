#include <random>
#include <iostream>

//test to use std_uniform_distribution in a class context

class Generator
{
  public:
    Generator();
    ~Generator();
    
    int GetNumber();
    
  private:
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;  
};

Generator::Generator() : gen(rd()), dis(1,6)
{
}

Generator::~Generator()
{
}

int Generator::GetNumber()
{
  int value = dis(gen);
  return value;
}



 
int main()
{
    Generator gen;
 
    for (int n=0; n<10; ++n)
        std::cout << gen.GetNumber() << ' ';
    std::cout << '\n';
    
    return 0;
}
