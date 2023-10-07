#include <iostream>
#include <string>
#include <vector>
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int count_times = 0;
    std::cin>>count_times;
    for (int palidrom_id = 0; palidrom_id < count_times; palidrom_id++){
        int count_1 = 0;
        int count_0 = 0;
        std::string palidrom;
        std::cin>>count_0>>count_1>>palidrom;
        int palidrom_size = count_0 + count_1;
        bool is_palidrom = true;
        int reserv_count_0 = count_0;
        int reserv_count_1 = count_1;
        std::vector<int> where_index = {};
        for (int char_id = 0; char_id < palidrom_size / 2 + palidrom_size % 2; char_id ++){
            if (palidrom[char_id] != '?' && palidrom[palidrom_size - char_id + 1] == '?'){
                if (palidrom[char_id] == '0' && reserv_count_0 != 0){
                    palidrom[palidrom_size - char_id + 1] = '0';
                    reserv_count_0 -= 1;
                }
                if (palidrom[char_id] == '1' && reserv_count_1 != 0){
                    palidrom[palidrom_size - char_id + 1] = '1';
                    reserv_count_1 -= 1;
                }
            }
            if (palidrom[char_id] == '?' && palidrom[palidrom_size - char_id + 1] != '?'){
                if (palidrom[char_id] == '0' && reserv_count_0 != 0){
                    palidrom[char_id] = '0';
                    reserv_count_0 -= 1;
                }
                if (palidrom[palidrom_size - char_id + 1] == '1' && reserv_count_1 != 0){
                    palidrom[char_id] = '1';
                    reserv_count_1 -= 1;
                }
            }
            if (palidrom[char_id] == '?' && palidrom[palidrom_size - char_id + 1] == '?'){
                where_index.push_back(char_id);
            }
        }
        for (int item : where_index){
            if (reserv_count_0 + reserv_count_1 == 0){
                is_palidrom = false;
                break;
            }
            else {
                if (item == palidrom_size - item + 1){
                    if (reserv_count_0 > 0){
                        palidrom[item] = '0';
                        reserv_count_0 -= 1;
                    }
                    else {
                        if (reserv_count_1 > 0){
                            palidrom[item] = '1';
                            reserv_count_1 -= 1;
                        }
                    }
                }
            }
        }
    }
}