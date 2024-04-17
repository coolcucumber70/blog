#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
struct Compare
{
    bool operator()(int a, int b) const
    {
        // 比较逻辑
        // 如果a应该排在b之前，返回true；否则返回false
        // 这里使用升序排序作为示例
        return a < b;
    }
};
bool compare(int a, int b)
{
    // 比较逻辑
    // 如果a应该排在b之前，返回true；否则返回false
    // 这里使用升序排序作为示例
    return a < b;
}
int main()
{
    std::vector<int> numbers = {5, 2, 8, 1, 6};
    std::vector<int> numbers1 = {5, 2, 8, 1, 6};
    std::sort(numbers.begin(), numbers.end(), [](int a, int b)
              { return a < b; });

    // 使用自定义比较函数进行排序
    std::sort(numbers.begin(), numbers.end(), compare);

    // 输出排序后的结果
    for (int num : numbers)
    {
        std::cout << num << " ";
    }

    return 0;
}
#include <iostream>

int main()
{
    int x = 5;
    int y = 3;

    // 捕获列表中以值的方式捕获x，以引用的方式捕获y
    auto lambda = [&]() mutable
    {
        x += 2;
        y += 2;
        std::cout << "x: " << x << ", y: " << y << std::endl;
    };

    lambda(); // 输出: x: 7, y: 5

    std::cout << "x: " << x << ", y: " << y << std::endl; // 输出: x: 5, y: 5

    return 0;
}