#include <iostream>
#include <vector>
#include <algorithm>

struct Compare {
    bool operator()(int a, int b) const {
        return a < b;
    }
};

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 9};

    std::sort(numbers.begin(), numbers.end(), Compare());

    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}