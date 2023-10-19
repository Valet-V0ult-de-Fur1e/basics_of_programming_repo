#include <iostream>
#include <vector>
int main(){
    int count_iters = 0;
    std::cin>>count_iters;
    for (int iter_id = 0; iter_id < count_iters; ++ iter_id){
        int count_nums = 0;
        int max_elem_from_nums = 0;
        std::cin>>count_nums;
        std::vector<int> nums;
        for (int num_id = 0; num_id < count_nums; ++ num_id){
            int num;
            std::cin>>num;
            if (max_elem_from_nums < num){
                max_elem_from_nums = num;
            }
            nums.push_back(num);
        }
        int min_result = max_elem_from_nums;
        for (int item : nums){
            int result = item & max_elem_from_nums;
            min_result = std::min(result, min_result);
        }
        std::cout<<min_result<<"\n";
    }
}
