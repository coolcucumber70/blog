#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string str = "1+2/3+4*2+55";
    std::vector<int> v;
    std::vector<char> cal;
    
    auto finfuhao = [&str, &cal, &v](int start) -> size_t {
        str = str.substr(start);
        if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/') {
            cal.push_back(str[0]);
            return  1;
        }
        auto it = str.find_first_of("+-*/");
        std::string tmp = str.substr(0, it);
        v.push_back(std::stoi(tmp));
        return it;
    };
    
    auto calfuc = [](int a, int b, char f) -> int {
        switch (f) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            default:
                return 0;
        }
    };
    
    int start = 0;
    while (start != std::string::npos && start < str.length()) {
        start = finfuhao(start);
        while (cal.size() > 2 && (cal.back() == '*' || cal.back() == '/') && (cal[cal.size() - 2] == '+' || cal[cal.size() - 2] == '-')) {
            int num = calfuc(v.back(), v[v.size() - 2], cal[cal.size() - 2]);
            char f = cal.back();
            v.pop_back();
            v.pop_back();
            v.push_back(num);
            cal.pop_back();
            cal.pop_back();
            cal.push_back(f);
        }
    }
    
    while (!cal.empty()) {
        int a = v.back();
        v.pop_back();
        int b = v.back();
        v.pop_back();
        char f = cal.back();
        cal.pop_back();
        int num = calfuc(a, b, f);
        v.push_back(num);
    }
    
    std::cout << "Result: " << v[0] << std::endl;
    
    return 0;
}