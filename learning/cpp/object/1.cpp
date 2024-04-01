#include <iostream>

class MyClass {
public:
    int data;

    MyClass(int value) : data(value) {
        std::cout << "Constructor called. Value: " << data << std::endl;
    }
    virtual int func(){};
    //纯虚函数就是
    int novirfunc(){return 0;};

    MyClass(const MyClass& other) : data(other.data) {
        std::cout << "Copy constructor called. Value: " << data << std::endl;
    }
};

void functionByValue(MyClass obj) {
    std::cout << "Inside functionByValue" << std::endl;
}

MyClass returnByValue() {
    MyClass obj(10);
    return obj;
}

int main() {
    MyClass obj1(5);  // 直接初始化

    MyClass obj2 = obj1;  // 赋值操作

    functionByValue(obj1);  // 以值传递方式传入函数体

    MyClass obj3 = returnByValue();  // 从函数返回值

    return 0;
}