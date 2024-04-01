#include"MyClass.h"
extern int num2;
extern int num;
int main() {
    MyClass::staticFunction(5); // 调用静态成员函数进行修改
    std::cout<<MyClass::staticVariable<<std::endl;
    std::cout<<num<<std::endl;
    std::cout<<num2<<std::endl;

    return 0;
}
static int num=111;