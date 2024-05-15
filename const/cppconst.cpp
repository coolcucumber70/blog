// C++ 示例
#include <iostream>
void test02()
{
    const int b = 10;   //分配到栈上
    //b = 100;  //直接修改语法不通过
    
    //c语言下称为伪常量
    //int *p = &b;
    //*p = 100;
    //printf("b  %d\n",*p); //间接修改成功
 
    //int a[b];  伪常量是不可以初始化数组的
}
int main() {
    const int num = 10;
    int* ptr = const_cast<int*>(&num);  // 使用 const_cast 进行类型转换
    //int* ptr1=&num;
    test02();

    std::cout << "The value of num: " << num << std::endl;

    return 0;
}