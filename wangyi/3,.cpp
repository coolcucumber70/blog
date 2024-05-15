//3之后开始#include <iostream>
#include <cmath>

int main() {
    int P, Q, x;
    std::cin >> P >> Q >> x;

    // n份食物，m份水    n+3*m<=x
    // 老虎和人最多可以挨饿多少天
    int a = std::min(P, Q);

    // 老虎或者人可以挪出来多少天的食物
    int b = std::abs(P - Q) / 3;

    // 这些食物可以供人和老虎存活多久
    int c = x / 12;

    std::cout << (a + b + c) << std::endl;

    return 0;
}