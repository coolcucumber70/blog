#include <iostream>
using namespace std;

class MyClass {
public:
    const int MAX_VALUE;

    MyClass() : MAX_VALUE(100) {
        // 构造函数初始化列表中对 const 成员变量进行初始化
    }

    void printValue() {
        cout << MAX_VALUE << endl; // 可以访问 const 成员变量
    }
};

int main() {
    MyClass obj;
    obj.printValue(); // 输出: 100

    return 0;
}