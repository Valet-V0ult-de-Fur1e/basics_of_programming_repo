#include <iostream>
#include <vector>

int main(){
    int count_lines = 0;
    std::cin>>count_lines;
    for (int line_id = 0; line_id < count_lines; ++ line_id){
        int line_lenght = 0;
        int eraser_lenght = 0;
        int comulitive_count_black_pixels = 0;
        int count_eraser_use = 0;
        std::cin>>line_lenght>>eraser_lenght;
        std::vector<int> black_pixels_count_on_line = {0};
        std::vector<int> line(line_lenght);
        int first_black_pixel_id = -1;
        for (int line_item_id = 0; line_item_id < line_lenght; ++ line_item_id){
            char pixel;
            std::cin>>pixel;
            if (pixel == 'B'){
                comulitive_count_black_pixels += 1;
                if (first_black_pixel_id == -1){
                    first_black_pixel_id = line_item_id;
                }
                line[line_item_id] = 1;
            }
            else{
                line[line_item_id] = 0;
            }
            black_pixels_count_on_line.push_back(comulitive_count_black_pixels);
        }
        if (first_black_pixel_id != -1){
            int line_item_id = first_black_pixel_id;
            while (line_item_id < line_lenght){
                if (line[line_item_id] == 0){
                    line_item_id += 1;
                    continue;
                }
                if (line_item_id + eraser_lenght < line_lenght){
                    int a = (black_pixels_count_on_line[line_item_id + eraser_lenght] - black_pixels_count_on_line[line_item_id]);
                    if ((black_pixels_count_on_line[line_item_id + eraser_lenght] - black_pixels_count_on_line[line_item_id]) > 0){
                        count_eraser_use += 1;
                    }
                    line_item_id += eraser_lenght;
                }
                else {
                    int b = (black_pixels_count_on_line[line_lenght] - black_pixels_count_on_line[line_item_id]);
                    if ((black_pixels_count_on_line[line_lenght] - black_pixels_count_on_line[line_item_id]) > 0){
                        count_eraser_use += 1;
                    }
                    line_item_id = line_lenght;
                }
            }
        }
        std::cout<<count_eraser_use<<"\n";
    }
}