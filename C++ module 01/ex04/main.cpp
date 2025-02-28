#include <iostream>
#include <fstream>

int SearchReplace(std::string inputName, std::string content, std::string to_find, std::string to_replace)
{
    inputName.append(".replace");
    std::ofstream output(inputName);
    if(!output.is_open()){
        std::cout << "failed to open the output file" << std::endl;
        return (1);
    }
    if (to_find.empty()){
        std::cout << "to_find is empty" << std::endl; 
        return (1);
    }
    size_t i = 0;
    size_t position = content.find(to_find, i);
    while(position != std::string::npos){
        output << content.substr(i, position - i) << to_replace;
        i = position + to_find.length();
        position = content.find(to_find, i);
    }
    output << content.substr(i);
    output.close();
    return (0);
}

int main(int ac, char **av) {
    if (ac != 4){
        std::cerr << "ARGS ERROR" << std::endl;
        return 1;
    }
    std::ifstream file(av[1]);
    std::string line;
    std::string to_find = av[2];
    std::string to_replace = av[3];
    std::string content;
    
    if (!file.is_open()){
        std::cerr << "File can't open please enter a valide file" << std::endl;
        return (1);
    }

    while (getline(file, line)){
        content.append(line);
        if (!file.eof())
            content.append("\n");
    }
    file.close();

    if (SearchReplace(av[1], content, to_find, to_replace))
        return (1);
    return 0;
}