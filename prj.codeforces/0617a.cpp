#include <iostream>

int main()
{
    int friend_home_coord;
    std::cin>>friend_home_coord;
    std::cout<<friend_home_coord / 5 + ((friend_home_coord % 5)? 1:0 );
    return 0;
}
