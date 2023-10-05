#include <iostream>
int main(){
    int count_data = 0;
    std::cin>>count_data;
    for (int i = 0; i < count_data; i++){
        int matrix_size = 0;
        int shift = 0;
        int first_element_x_coord = 0;
        int first_element_y_coord = 0;
        std::cin>>matrix_size>>shift>>first_element_x_coord>>first_element_y_coord;
        for (int i = 1; i <= matrix_size; i++){
            for (int j = 1; j <= matrix_size; j++){
                if (((i - first_element_x_coord) + (j - first_element_y_coord)) % shift == 0){
                    std::cout<<"X";
                }
                else{
                    std::cout<<".";
                }
            }
            std::cout<<std::endl;
        }
    }
}