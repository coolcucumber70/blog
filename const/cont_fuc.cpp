#include <bits/stdc++.h>
using namespace std;
class MyClass
{
public:
    void foo() const// 常函数的声明
    {
        cout<<"foo"<<endl;

    }

    void bar() const
    {
        // 常函数的定义
        cout<<"bar"<<endl;
    }
};
int main()
{
    const MyClass obj;
    obj.foo(); // 合法调用常函数

    const MyClass *ptr = &obj;
    ptr->foo(); // 合法调用常函数

    // 非常对象调用常函数会导致编译错误
    // MyClass obj2;
    // obj2.foo(); // 编译错误
}