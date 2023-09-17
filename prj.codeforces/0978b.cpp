#include <iostream>

int main()
{
    int count, out = 0;
    std::cin>>count;
    bool flag1=false, flag2=false;
    for (int i = 0; i < count; i++){
        char item;
        std::cin>>item;
        if (item == 'x'){
            if (flag1){
                if (flag2){
                    out += 1;
                }
                else{
                    flag2 = true;
                }
            }
            else{
                flag1 = true;
            }
        }
        else{
            flag1 = false;
            flag2 = false;
        }
    }
    std::cout<<out;
    return 0;
}