#include <iostream>
#include <vector>

int main(){
    int count_input_dates;
    std::cin>>count_input_dates;
    for (int i = 0; i < count_input_dates; i ++){
        int start_count_rounds, next_count_rounds, round_result;
        std::cin>>start_count_rounds>>next_count_rounds;
        std::vector<int> results_data(350);
        for (int i = 0; i < start_count_rounds; i ++){
            std::cin>>round_result;
            results_data[round_result] = 1;
        }
        int index = 1;
        while (next_count_rounds > 0 || results_data[index] != 0){
            if (results_data[index] == 0){
                next_count_rounds -= 1;
                results_data[index] = 1;
            }
            index += 1;
        }
        if (results_data[index] != 1){
            index -= 1;
        }
        std::cout<<index<<std::endl;
    }
}