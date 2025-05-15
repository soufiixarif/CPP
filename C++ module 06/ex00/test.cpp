#include <iostream>

int main(){
    std::string s = "++434343";
    int i = 0;
    if (s[0] == '+' || s[0] == '-')
        i++;
    while (s[i]){
        if (!isdigit(s[i])){
            std::cout << "la" << std::endl;
            return 1;
        }
        i++;
    }
    std::cout << "ah" << std::endl;
};