#include "MyClass.h"

int MyClass::staticVariable = 10;

void MyClass::staticFunction(int param) {
    std::cout << "Static Function" << std::endl;
    std::cout << "Previous Static Variable: " << staticVariable << std::endl;

    staticVariable = param; // 修改静态成员变量的值

    std::cout << "Modified Static Variable: " << staticVariable << std::endl;
}
int num2=222;
