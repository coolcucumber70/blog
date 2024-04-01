#include <iostream>

class MyClass {
public:
    int* data;

    MyClass(int value) {
        data = new int(value);
        std::cout << "Constructor called. Value: " << *data << ", Address: " << data << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor called. Value: " << *data << ", Address: " << data << std::endl;
        delete data;
    }
};

int main() {
    MyClass obj1(5);
    MyClass obj2 = obj1;  // 使用默认的浅拷贝构造函数进行赋值

    return 0;
}