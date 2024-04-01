
//修饰类成员函数
//修饰类

#include <iostream>
using namespace std;

class MyClass {
private:
    int value;

public:
    MyClass(int v) : value(v) {}

    int getValue() const {
        // const 成员函数，不会修改成员变量的值
        return value;
    }

    void setValue(int v) {
        value = v;
    }
};

int main() {
    const MyClass obj(10);

    cout << "Value: " << obj.getValue() << endl;  // 调用 const 成员函数

    //obj.setValue(20);  // 错误！const 对象无法调用非 const 成员函数

    return 0;
}