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
            nums.push_back(num);
        }
        int result = nums[0];
        for (int num_id = 1; num_id < count_nums; ++ num_id){
            result = result & nums[num_id];
        }
        std::cout<<result<<"\n";
    }
}
