#include <iostream>

int main()
{
    int element;
    for (int i = 0; i < 5; i ++){
        for (int j = 0; j < 5; j++){
            std::cin>>element;
            if (element){
                std::cout<<abs(i - 2) + abs(j - 2);
            }
        }
    }
}
