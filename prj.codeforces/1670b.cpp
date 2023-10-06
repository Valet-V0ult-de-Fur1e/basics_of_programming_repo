#include <iostream>
#include <string>
#include <vector>
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int count_data = 0;
    std::cin>>count_data;
    for (int i = 0; i < count_data; i++){
        int password_size = 0;
        int count_chars = 0;
        int count_operations = 0;
        std::string password;
        std::vector<int> find_list(255);
        std::cin>>password_size>>password>>count_chars;
        for (int j = 0; j < count_chars; j++){
            char error_char;
            std::cin>>error_char;
            find_list[error_char] = 1;
        }
        int last_best_char_index = -1;
        for (int j = 0; j < password_size; j++){
            if (find_list[password[j]] == 1){
                last_best_char_index = j;
            }
        }
        std::vector<int> password_chars_flags(100001);
        int condensate_chars = 0;
        for (int j = last_best_char_index - 1; j >= 0; j --){
            condensate_chars ++;
            password_chars_flags[j] = condensate_chars;
            if (find_list[password[j]] == 1){
                condensate_chars = 0;
            }
            if (count_operations < password_chars_flags[j]) {
                count_operations = password_chars_flags[j];
            }
        }
        std::cout<<count_operations<<"\n";
    }
}