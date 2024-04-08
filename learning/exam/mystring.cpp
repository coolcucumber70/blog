#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";

    // append(str), += 或 push_back(ch)
    str.append(" Welcome");
    std::cout << "Appended string: " << str << std::endl;

    // insert(pos, str) 或 insert(pos, ch)
    str.insert(5, " C++");
    std::cout << "Inserted string: " << str << std::endl;

    // erase(pos, len)
    str.erase(7, 7);
    std::cout << "String after erasing: " << str << std::endl;

    // replace(pos, len, str)
    str.replace(7, 4, "Coders");
    std::cout << "String after replacement: " << str << std::endl;

    // substr(pos, len)
    std::string substr = str.substr(7, 6);
    std::cout << "Substring: " << substr << std::endl;

    // find(str, pos)
    size_t found = str.find("AAAA");
    std::cout<<found<<std::endl;
    if (found != std::string::npos) {
        std::cout << "Substring found at position: " << found << std::endl;
    } else {
        std::cout << "Substring not found" << std::endl;
    }
    // rfind(str, pos)
    size_t lastFound = str.rfind("o");
    if (lastFound != std::string::npos) {
        std::cout << "Last occurrence found at position: " << lastFound << std::endl;
    } else {
        std::cout << "Substring not found" << std::endl;
    }
    //查找首先出现的字符
    size_t findfirst=str.find_first_of("Ao");
    if (findfirst!=std::string::npos){
        std::cout<<findfirst<<std::endl;
    }
    else{
        std::cout<<"not findfirst"<<std::endl;
    }
    std::string str2="a+216i";
    std::cout<<str2<<std::endl;
    size_t posfuhao=str2.find_first_of("+-");
    size_t posi=str2.find_first_of('i');
    if (posfuhao!=std::string::npos&&posi!=std::string::npos)
    {
        /* code */
        int len=posi-posfuhao-1;
        if (len>0)
        {
            /* code */
            std::string subbbbb=str2.substr(posfuhao+1,len);
            std::cout<<subbbbb<<std::endl;
            std::cout<<std::stoi(subbbbb)<<std::endl;
        }
        
        
    }
    

    

    return 0;
}