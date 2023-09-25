#include <iostream>

int main(){
    int count_levels;
    std::cin>>count_levels;
    for (int i = 0; i < count_levels; i++){
        int height, width, lazer_x_coord, lazer_y_coord, lazer_radios;
        std::cin>>height>>width>>lazer_x_coord>>lazer_y_coord>>lazer_radios;
        if ((lazer_x_coord + lazer_radios >= height && lazer_x_coord - lazer_radios <= 1) 
        || (lazer_y_coord + lazer_radios >= width && lazer_y_coord - lazer_radios <= 1)
        || (lazer_x_coord - lazer_radios <= 1 && lazer_y_coord - lazer_radios <= 1)
        || (lazer_x_coord + lazer_radios >= height && lazer_y_coord + lazer_radios >= width)){
            std::cout<<-1<<std::endl;
        }
        else{
            std::cout<<height + width - 2<<std::endl;
        }
    }
}