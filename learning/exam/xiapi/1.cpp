//f反转字符串
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string reverseString(string str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        // 交换首尾字符
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    return str;
}

int main() {
    string inputString;
    getline(cin, inputString);  // 使用 getline 读取一整行

    istringstream stream(inputString);
    string word;
    string result;

    while (stream >> word) {
        word = reverseString(word);
        if (!result.empty()) {
            result += " ";
        }
        result += word;
    }

    cout << result << endl;

    return 0;
}
