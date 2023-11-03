#include <iostream>
#include <vector>

int main(){
    int count_lines = 0;
    std::cin>>count_lines;
    for (int line_id = 0; line_id < count_lines; ++ line_id){
        int line_size = 0;
        int pre_line_size = 0;
        std::string line;
        std::cin>>line_size>>pre_line_size>>line;
        int count_white_now = 0;
        for (int line_item_id = 0; line_item_id < pre_line_size; ++ line_item_id){
            if (line[line_item_id] == 'W'){
                count_white_now += 1;
            }
        }
        int output_count = count_white_now;
        for (int line_item_id = 1; line_item_id < line_size - pre_line_size; ++ line_item_id){
            if (line[line_item_id - 1] == 'W'){
                count_white_now -= 1;
            }
            if (line[line_item_id + pre_line_size - 1] == 'W'){
                count_white_now += 1;
            }
            if (count_white_now < 0){
                count_white_now = 0;
            }
            output_count = std::min(count_white_now, output_count);
        }
        std::cout<<output_count<<"\n";
    }
}