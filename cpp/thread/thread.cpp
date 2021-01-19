#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <random>
#include <chrono>
#include <thread> 
#include <pthread.h>

class Driver{
    public:
        Driver(std::vector<int> values);
        Driver(int);
        Driver(){};
        virtual void ReverseSort(){std::cout << "sort base class called \n";};
        auto GetData() { return data;};
    protected:
        std::vector<int> data;
};

class SpecificDriver : public Driver{
    public:
        SpecificDriver(std::vector<int> values);
        void ReverseSort();
    private:
};
//std::vector<std::unique_ptr<Driver>> drivers;
std::vector<std::shared_ptr<Driver>> drivers;

SpecificDriver::SpecificDriver(std::vector<int> values) : Driver(values)
{

}

Driver::Driver(std::vector<int> values) : data(values)
{
    
}

Driver::Driver(int v) : data({v})
{

}

void SpecificDriver::ReverseSort()
{
    std::cout << "Specific driver sort called \n";
    std::sort(data.begin(),data.end(),[](int a, int b) {return a > b;} );
}

template<typename T>
void Print(const T& v)
{
    std::for_each(v.begin(),v.end(),[](const auto value){std::cout <<  value << " "; } );
    std::cout << std::endl;
}
template<typename T>
void PrintShort(const T& v)
{
    for(unsigned int i = 0; i<v.size(); i++)
    {
        std::cout << v.at(i) << " ";
        if(i>=9) break;
    }
    std::cout << std::endl;
}

int main(int, char**) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 10000);

    for(unsigned int i = 0; i < 4; i ++)
    {
        int size = 2000000;
        std::vector<int> v(size);
        for(unsigned int j=0; j<size; j++) { v[j]=distrib(gen); }
        drivers.emplace_back( std::make_shared<SpecificDriver>(v)); 
        //drivers.push_back(v);
    }

    for(auto& d: drivers)
    {
       PrintShort(d->GetData());
    }

    auto start = std::chrono::steady_clock::now();

    std::vector<std::thread> threads;
    for(auto& d: drivers)
    {
       threads.emplace_back( &Driver::ReverseSort,d );
      //  d->ReverseSort();
    }

    //https://stackoverflow.com/questions/10673585/start-thread-with-member-function

    //Driver d1({1,2,3});
    //std::thread gamma_thread( &Driver::ReverseSort, &d1);
    //gamma_thread.join();

    for(auto& t : threads) {    t.join(); }



    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

    for(auto& d: drivers)
    {
       PrintShort(d->GetData());
    }
    //drivers.emplace_back( std::make_unique<Driver>(v)); 
    //Print(d.GetData());





return 0;    

}