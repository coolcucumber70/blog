#include <iostream>
#include <vector>
#include <string>

const char* filter_letters(const std::vector<char>& ignore_letters, const std::string& str)
{
    std::string _result;
    int n = str.length(); // 使用 str.length() 获取字符串长度
    int x=0;
    while (x < n) {
        bool _exist = false;
        for (std::vector<char>::const_iterator it = ignore_letters.begin(); it != ignore_letters.end(); ++it) {
            if (*it == str[x]) {
                _exist = true;
                break;
            }
        }
        if (!_exist) {
            _result.push_back(str[x]); // 使用 push_back() 方法将字符添加到字符串末尾
        }
        x++;
    }
    _result.push_back('\0'); // 添加字符串结束符
    return _result.c_str(); // 返回字符串指针
}

void work()
{
    std::vector<char> letters {'w', 'h', 'a'};
    std::string buf("Your past is not your potential.");
    const char* result = filter_letters(letters, buf);
    printf("%s", result);
}

int main()
{
    work(); // 调用 work() 函数
    return 0;
}