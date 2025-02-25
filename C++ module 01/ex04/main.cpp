#include <iostream>
#include <fstream>

std::string SearchReplace(std::string content, std::string to_find, std::string to_replace)
{
    size_t i = 0;
    std::string front;
    std::string back;
    int len = to_find.length();
    
    while(content.find(to_find) != std::string::npos){
        i = content.find(to_find);
        front = content.substr(0, i);
        back = content.substr(i + len,content.length());
        content = front;
        content += to_replace;
        content += back;
    }
    return (content);
}

int main(int ac, char **av) {
    if (ac != 4){
        std::cerr << "ARGS ERROR" << std::endl;
        return 1;
    }
    std::ifstream file(av[1]);
    std::string line;
    std::string content;
    std::string to_find = av[2];
    std::string to_replace = av[3];
    
    if (!file.is_open()){
        std::cerr << "File can't open please enter a valide file" << std::endl;
        return (1);
    }

    while (getline(file, line))
            content += line;

    file.close();

    content = SearchReplace(content, to_find, to_replace);
    std::cout << "Result: " << content;
    return 0;
}