#include <iostream>
#include <vector>
#include <string>

int main() {
    int output = 0;
    std::string code;
    std::cin>>code;
    char lastItem = 'a';
    for (char item : code){
        int first_variant = std::abs(lastItem - item);
        int second_variant = std::abs(26 - first_variant);
        output += std::min(first_variant, second_variant);
        lastItem = item;
    }
    std::cout<<output;
}