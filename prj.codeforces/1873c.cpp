#include <iostream>
#include <string>
#include <vector>
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int count_data = 0;
    std::cin>>count_data;
    std::vector<int> score_matrix = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 2, 2, 2, 2, 2, 2, 2, 2, 1,
        1, 2, 3, 3, 3, 3, 3, 3, 2, 1,
        1, 2, 3, 4, 4, 4, 4, 3, 2, 1,
        1, 2, 3, 4, 5, 5, 4, 3, 2, 1,
        1, 2, 3, 4, 5, 5, 4, 3, 2, 1,
        1, 2, 3, 4, 4, 4, 4, 3, 2, 1,
        1, 2, 3, 3, 3, 3, 3, 3, 2, 1,
        1, 2, 2, 2, 2, 2, 2, 2, 2, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1
        };
    for (int target_id = 0; target_id < count_data; target_id++){
        int score_count = 0;
        int matrix_size = 10;
        for (int i = 0; i < matrix_size; i++){
            for (int j = 0; j < matrix_size; j++){
                char pixel_result;
                std::cin>>pixel_result;
                if (pixel_result == 'X'){
                    score_count += score_matrix[i * matrix_size + j];
                }
            }
        }
        std::cout<<score_count<<"\n";
    }
}