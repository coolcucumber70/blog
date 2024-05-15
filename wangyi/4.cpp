
#include <iostream>
#include <string>

class MyClass {
public:
    MyClass(const std::string& name, int age) : name(name), age(age) {
        // 构造函数的其他操作（如果有）
    }

    void printInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
    }

private:
    std::string name;
    int age;
};

int main() {
    // 创建一个类的实例，使用初始化列表初始化参数
    MyClass myObject("Alice", 25);

    // 调用类的方法
    myObject.printInfo();

    return 0;
}