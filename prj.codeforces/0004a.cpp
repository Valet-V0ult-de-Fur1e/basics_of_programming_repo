#include <iostream>

int main()
{
    int watermelon_weight;
    std::cin>>watermelon_weight;
    std::cout<<((watermelon_weight>2)?((watermelon_weight%2==0)?"YES":"NO"):"NO");
    return 0;
}
