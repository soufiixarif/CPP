#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av) {
    if (ac != 4)
    {
        std::cerr << "ARGS ERROR" << std::endl;
        return 1;
    }
    std::ifstream file(av[1]);
    std::string line;
    std::string content;
    
    if (!file.is_open()) {
        std::cerr << "File can't open" << std::endl;
        
    }
    getline(file, line);
    if (std::cin.eof())
        exit(0);
    content += line;
    while (1) {
            content += line;
            if (getline(file,line))
                content += "\n";
            else
                break;
    }
    file.close();
    size_t i = 0;
    std::string front;
    std::string back;
    std::string to_find;
    std::string to_replace;
    to_find = av[2];
    to_replace = av[3];
    int len = to_find.length();
    
    while(content.find(av[2]) != std::string::npos){
        i = content.find(av[2]);
        front = content.substr(0,i);
        back = content.substr(i + len,content.length());
        content = front;
        content += to_replace;
        content += back;
    }
    std::cout << "Result: " << content;
    return 0;
}