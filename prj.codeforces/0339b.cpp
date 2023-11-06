#include <iostream>
int main(){
    int count_buildings = 0;
    int count_cases = 0;
    std::cin>>count_buildings>>count_cases;
    int count_time = 0;
    int point_id_now = 1;
    for (int case_id = 0; case_id < count_cases; case_id += 1) {
        int target_id = 0;
        std::cin>>target_id;
        count_time += ((point_id_now == target_id) ? 0 : ((point_id_now < target_id) ? (target_id - point_id_now) : (count_buildings - point_id_now + target_id)));
        point_id_now = target_id;
    }
    std::cout<<count_time;
}