#include <stdio.h>
#include <stdlib.h>

// 使用 char* 参数
void modifyString(char* str) {
    str = "Modified";  // 修改指针的值，不影响原始字符串
}

// 使用 char** 参数
void modifyStringPtr(char** strPtr) {
    *strPtr = "Modified";  // 修改指针所指向的地址的内容，影响原始字符串
}

int main() {
    char* str1 = "Original";
    printf("Before modification: %s\n", str1);
    modifyString(str1);
    printf("After modification (char*): %s\n", str1);

    char* str2 = "Original";
    printf("Before modification: %s\n", str2);
    modifyStringPtr(&str2);
    printf("After modification (char**): %s\n", str2);

    return 0;
}