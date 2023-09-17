#include <iostream>

bool check(int num){
    int a = num / 1000, b = (num % 1000) / 100, c = (num % 100) / 10, d = num % 10;
    return (a == b) || (b == c) || (c == d) || (a == c) || (a == d) || (b == d);
}

int main()
{
    int year;
    std::cin>>year;
    year += 1;
    while (check(year)){
        year += 1;
    }
    std::cout<<year;
    return 0;
}
