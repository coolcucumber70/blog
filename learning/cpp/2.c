#include <stdio.h>
#include <stdlib.h>
void modifyValue(int* ptr) {
    *ptr = 100;  // 通过指针修改变量的值
}

int main() {
    int value = 0;
    modifyValue(&value);  // 通过指针参数传递
    // 现在value的值为100
    printf("%d",value);
    return 0;
}