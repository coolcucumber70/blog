#include<iostream>
using namespace std;

void modifyValue(int& ref) {
    ref = 100;  // 直接修改引用所引用的变量的值
}

int main() {
    int value = 0;
    modifyValue(value);  // 通过引用参数传递
    cout<<value<<endl;
    // 现在value的值为100
    return 0;
}