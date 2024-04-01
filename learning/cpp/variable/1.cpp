#include <iostream>

const int GLOBAL_CONST = 50; // 全局常量

int globalVar1 = 10; // 全局变量，存储在静态数据区
int globalVar2;      // 全局变量，存储在全局数据区

static int staticVar1 = 20; // 静态变量，存储在静态数据区
static int staticVar2;      // 静态变量，存储在全局数据区

class MyClass
{
public:
    int nonStaticVar;     // 非静态成员变量
    static int staticVar; // 静态成员变量
    static int staticVar1;

    static void staticFunction()
    {
        std::cout << "This is a static function." << std::endl;
        // 静态函数可以访问静态变量，但不能访问非静态变量
        std::cout << "Static variable value: " << staticVar << std::endl;
    }
     void Function()
    {
        std::cout << "This is a  function." << std::endl;
        // 静态函数可以访问静态变量，但不能访问非静态变量
        std::cout << "Static variable value: " << staticVar << std::endl;
        std::cout << " variable value: " << nonStaticVar << std::endl;

    }
};

int MyClass::staticVar = 100; // 静态变量初始化

int main()
{
    const int LOCAL_CONST = 30;     // 局部常量,局部常量在编译时期进行初始化，它们的值在程序执行之前就确定了。局部常量在声明时必须进行初始化，并且不能在运行时修改其值。
    static int localStaticVar = 40; // 静态局部变量，存储在静态数据区,静态局部变量只会在首次进入声明所在的函数或代码块时进行初始化，之后的函数调用或代码块执行不会再触发初始化过程。初始化仅在第一次进入时执行，然后变量的值在后续调用或执行中保持不变。
    int localVar = 50;              // 局部变量，存储在栈上

    // 输出各个变量的地址
    std::cout << "Global variable 1 address: " << &globalVar1 << std::endl;
    std::cout << "Global variable 2 address: " << &globalVar2 << std::endl;
    std::cout << "Static variable 1 address: " << &staticVar1 << std::endl;
    std::cout << "Static variable 2 address: " << &staticVar2 << std::endl;
    std::cout << "Local static variable address: " << &localStaticVar << std::endl;
    std::cout << "Local variable address: " << &localVar << std::endl;

    // 输出全局常量和局部常量的值
    std::cout << "Global constant value: " << GLOBAL_CONST << std::endl;
    std::cout << "Local constant value: " << LOCAL_CONST << std::endl;
    MyClass obj1;
    MyClass obj2;

    // 访问非静态变量
    obj1.nonStaticVar = 10;
    obj2.nonStaticVar = 20;

    // 访问静态变量
    std::cout << "Static variable value (obj1): " << obj1.staticVar << std::endl;
    std::cout << "Static variable value (obj2): " << obj2.staticVar << std::endl;

    // 修改静态变量的值
    obj1.staticVar = 50;

    // 再次访问静态变量
    std::cout << "Static variable value (obj1): " << obj1.staticVar << std::endl;
    std::cout << "Static variable value (obj2): " << obj2.staticVar << std::endl;

    // 调用静态函数
    MyClass::staticFunction();
    obj1.Function();
    return 0;
}