#include <iostream>
 
int get_fun(int f, int t, int k){
    return ((t > k)? f - (t - k) : f);
}
 
int main()
{
    int n, k, max_fun;
    bool is_first = true;
    std::cin>>n>>k;
    for (int i=0; i<n; i++){
        int f, t;
        std::cin>>f>>t;
        if (is_first){
            max_fun = get_fun(f, t, k);
            is_first = false;
        }
        else{
            max_fun = std::max(max_fun, get_fun(f, t, k));
        }
    }
    std::cout<<max_fun;
}
