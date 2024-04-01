#include <iostream>

class Base {
public:
    virtual void print() const {
        std::cout << "Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void print() const override {
        std::cout << "Derived class" << std::endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    // 上行转换（派生类指针转换为基类指针）
    Base* basePtr = &baseObj;
    // 下行转换（基类指针转换为派生类指针）
    // 不安全的转换，可能引发未定义行为
    Derived* derivedPtr = static_cast<Derived*>(basePtr);

    derivedPtr->print();  // 输出: "Derived class"

    return 0;
}