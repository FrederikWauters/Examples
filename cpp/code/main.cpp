#include <iostream>
#include <vector>
#include <algorithm>

float op_increase (int i) { return 1.2*i; }

int main(int, char**) {
    std::cout << "Hello, world!\n";

    int word = 8;

    if( (word & 0x8)  != 0) std::cout << " bit set " << std::endl;
    else std::cout << "bit not set " << std::endl; 

    std::vector<int> vec1 = {1,2,3,4};
    std::vector<bool> flags {true,false,false,true};
    std::vector<float> vec2;
    //vec2.resize(vec1.size());        
    std::transform( vec1.begin(), vec1.end(), std::back_inserter(vec2) , [](int i) { return i>2 ? i*1.2 : 0 ;} );
    std::for_each( vec2.begin(),vec2.end(),[](float v){std::cout << v << " " << std::endl;} );
    std::transform( vec2.begin(), vec2.end(), flags.begin(), vec2.begin() , [](float i,bool f) { return f ? i : -1; } );
    std::for_each( vec2.begin(),vec2.end(),[](float v){std::cout << v << " " << std::endl;} );

    

    return 1;
}
