#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::vector<int> v, v1;
    int n;
    std::cin>>n;
    for (int i= 0 ; i < n; i++){
        int a;
        std::cin>>a;
        v.push_back(a);
    }
    for (int i = n - 1; i >= 0; i--){
        if (std::find(v1.begin(), v1.end(), v.at(i)) == std::end(v1)) v1.push_back(v.at(i));
    }
    std::cout<<v1.size()<<std::endl;
    for (int i = v1.size() - 1; i >= 0; i--){
        std::cout<<v1.at(i)<<" ";
    }
}