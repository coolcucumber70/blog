#include <iostream>
#include <vector>
#include <sstream>
int main() {
    std::string input;
    std::getline(std::cin, input);  // 读取输入的一行

    std::vector<int> nums;
    std::istringstream iss(input);
    int num;

    while (iss >> num) {
        nums.push_back(num);
    }

    // 输出接收到的数组
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << " ";
    }

    return 0;
}