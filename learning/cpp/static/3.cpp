#include<iostream>
class MyClass {
public:
    int nonConstVar;
    const int  a =5;

    void modifyNonConstVar()const {
        //nonConstVar = 10;  // 可以修改非 const 成员变量
        std::cout<<"hello"<<std::endl;
    }
    MyClass(int x):nonConstVar(x){};
};

int main() {
    const MyClass obj(3);
    obj.a = 110;  // 可以访问和修改非 const 成员变量
    obj.modifyNonConstVar();  // 可以调用修改非 const 成员变量的函数
    return 0;
}