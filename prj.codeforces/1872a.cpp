#include <iostream>
#include <cmath>
int main()
{
    int t;
    std::cin>>t;
    for (int i = 0; i < t; i ++){
        int a, b, c;
        std::cin>>a>>b>>c;
        std::cout<< std::ceil(abs(a - b) / 2.f / c) <<std::endl;
    }
}