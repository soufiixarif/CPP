#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;


int main(int argc, char **argv)
{
    string s;
    if (argc > 1)
    {
        for(int j = 1; j < argc; j++){
            s = argv[j];
            for (size_t i = 0; i < s.length(); i++)
                cout << (char)toupper(s[i]);
        }
        cout << endl;
    }
    else
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
}
