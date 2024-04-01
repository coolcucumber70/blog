#include <iostream>
using namespace std;

class MyClass {
public:
    const int MAX_VALUE = 100; // const 成员变量

    void printValue() {
        cout << MAX_VALUE << endl; // 可以访问 const 成员变量
    }
};
int main() {
    MyClass obj;
    obj.printValue(); // 输出: 100

    return 0;
}