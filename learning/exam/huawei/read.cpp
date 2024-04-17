#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    std::string s = "1 2 3 4 5";
    std::stringstream ss(s);
    int number;

    while (ss >> number)
    {
        std::cout << "Extracted number: " << number << std::endl;
    }

    return 0;
}
