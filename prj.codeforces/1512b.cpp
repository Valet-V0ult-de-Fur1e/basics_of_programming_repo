#include <iostream>
#include <vector>

void writeMatrix(int first_point_x, int first_point_y, int second_point_x, int second_point_y, int threth_point_x, int threth_point_y,  int fouth_point_x, int fouth_point_y, int matrix_size){
    for (int i = 0; i < matrix_size; ++ i){
        for (int j = 0; j < matrix_size; ++ j){
            if (i == first_point_y && j == first_point_x){
                std::cout<<'*';
                continue;
            }
            if (i == second_point_y && j == second_point_x){
                std::cout<<'*';
                continue;
            }
            if (i == threth_point_y && j == threth_point_x){
                std::cout<<'*';
                continue;
            }
            if (i == fouth_point_y && j == fouth_point_x){
                std::cout<<'*';
                continue;
            }
            std::cout<<'.';
        }
        std::cout<<std::endl;
    }
}

int main(){
    int count_matrix = 0;
    std::cin>>count_matrix;
    for (int matrix_id = 0; matrix_id < count_matrix; ++ matrix_id){
        int matrix_a_size = 0;
        int first_point_x = 0;
        int first_point_y = 0;
        int second_point_x = 0;
        int second_point_y = 0;
        bool first_item_not_find = true;
        int first_custom_point_x = 0;
        int first_custom_point_y = 0;
        int second_custom_point_x = 0;
        int second_custom_point_y = 0;
        std::cin>>matrix_a_size;
        for (int i = 0; i < matrix_a_size; ++ i){
            for (int j = 0; j < matrix_a_size; ++ j){
                char item;
                std::cin>>item;
                if (item == '*'){
                    if (first_item_not_find){
                        first_item_not_find = false;
                        first_point_x = j;
                        first_point_y = i;
                    }
                    else{
                        second_point_x = j;
                        second_point_y = i;
                    }
                }
            }
        }
        if (first_point_x == second_point_x){
            first_custom_point_x = ((first_point_x == 0)? 1 : 0);
            first_custom_point_y = first_point_y;
            second_custom_point_x = ((first_point_x == 0)? 1 : 0);
            second_custom_point_y = second_point_y;
            writeMatrix(first_point_x, first_point_y, second_point_x, second_point_y, first_custom_point_x, first_custom_point_y, second_custom_point_x, second_custom_point_y, matrix_a_size);
            continue;
        }
        if (first_point_y == second_point_y){
            first_custom_point_x = first_point_x;
            first_custom_point_y = ((first_point_y == 0)? 1 : 0);
            second_custom_point_x = second_point_x;
            second_custom_point_y = ((first_point_y == 0)? 1 : 0);
            writeMatrix(first_point_x, first_point_y, second_point_x, second_point_y, first_custom_point_x, first_custom_point_y, second_custom_point_x, second_custom_point_y, matrix_a_size);
            continue;
        }
        first_custom_point_x = second_point_x;
        first_custom_point_y = first_point_y;
        second_custom_point_x = first_point_x;
        second_custom_point_y = second_point_y;
        writeMatrix(first_point_x, first_point_y, second_point_x, second_point_y, first_custom_point_x, first_custom_point_y, second_custom_point_x, second_custom_point_y, matrix_a_size);
    }
}