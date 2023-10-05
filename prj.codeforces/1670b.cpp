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
        int index_last_best_element = 0;
        std::string password;
        std::vector<int> find_list(255);
        std::cin>>password_size>>password>>count_chars;
        for (int j = 0; j < count_chars; j++){
            char error_char;
            std::cin>>error_char;
            find_list[error_char] = 1;
        }
        for (int j = 0; j < password_size; j++){
            if (find_list[password[j]] == 1){
                index_last_best_element = j;
            }
        }
        std::vector<int> password_chars_flags(100001);
        int count_deleted_chars = -1;
        int count_operations = 0;
        int last_best_char_status = -1;
        bool char_to_delete = false;
        while (count_deleted_chars != 0){
            count_deleted_chars = 0;
            last_best_char_status = -1;
            for (int char_id = 0; char_id <= index_last_best_element; char_id++){
                if (password_chars_flags[char_id] == -1){
                    continue;
                }
                if (char_to_delete && find_list[password[char_id]] == 0){
                    continue;
                }
                if (find_list[password[char_id]] == 0){
                    char_to_delete = true;
                    password_chars_flags[char_id] = -1;
                    if (last_best_char_status != -1){
                        last_best_char_status = -1;
                    }
                }
                else {
                    if (char_to_delete){
                        count_deleted_chars ++;
                        char_to_delete = false;
                    }
                    if (last_best_char_status == -1 && char_id != index_last_best_element){
                            last_best_char_status = char_id;
                    }
                    else{
                        if (last_best_char_status != -1){
                            password_chars_flags[last_best_char_status] = -1;
                            count_deleted_chars ++;
                            last_best_char_status = -1;
                            if (char_id != index_last_best_element){
                                last_best_char_status = char_id;
                            }
                        }
                    }
                    if (index_last_best_element == char_id){
                        break;
                    }
                }
            }
            count_operations += 1;
        }
        std::cout<<count_operations - 1<<"\n";
    }
}