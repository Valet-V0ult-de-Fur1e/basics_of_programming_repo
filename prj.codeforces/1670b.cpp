#include <iostream>
#include <string>
#include <vector>
int main(){
    int count_data = 0;
    std::cin>>count_data;
    for (int i = 0; i < count_data; i++){
        int password_size = 0;
        int count_chars = 0;
        std::string password;
        std::vector<int> find_list(255);
        std::cin>>password_size>>password>>count_chars;
        for (int j = 0; j < count_chars; j++){
            char error_char;
            std::cin>>error_char;
            find_list[error_char] = 1;
        }
        int count_work = 0;
        int count_error_chars = 0;
        bool first_is_error = false;
        for (int k = 0; k < password_size; k++){
            std::string new_password;
            for (int j = 0; j < password.length(); j++){
                if (j + 1 < password.length()){
                    if ((find_list[password[j]] == 0 || find_list[password[j]] == 1) && find_list[password[j + 1]] == 0){
                        new_password.push_back(password[j]);
                    }
                }
                else{
                    new_password.push_back(password[j]);
                }
            }
            for (int j = 0; j < new_password.length(); j++){
                if (find_list[new_password[j]] == 1){
                    if (j == 0){
                        first_is_error = true;
                    }
                    count_error_chars += 1;
                }
            }
            password = new_password;
            if (count_error_chars == 1 && first_is_error){
                break;
            }
            count_work += 1;
            count_error_chars = 0;
        }
        std::cout<<count_work<<std::endl;
    }
}