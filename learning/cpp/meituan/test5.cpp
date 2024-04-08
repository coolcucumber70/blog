#include <iostream>
#include <set>

int main() {
    std::set<int> set1 = {1, 2, 3}; // set1的初始数据
    std::set<int> set2 = {4, 5, 6}; // set2的初始数据

    // 清空set1并将set2的数据赋值给set1
    set1.clear();
    set1 = set2;

    // 清空set2
    set2.clear();

    // 输出set1中的元素
    std::cout << "set1: ";
    for (const auto& element : set1) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // 输出set2中的元素
    std::cout << "set2: ";
    for (const auto& element : set2) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}