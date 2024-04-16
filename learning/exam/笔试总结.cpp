
// stl算法

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

sort(vec.begin(), vec.end());
auto maxElement = std::max_element(numbers.begin(), numbers.end()); // 返回的是指针
int maxValue = INT_MAX;
int minValue = INT_MIN;
const int MOD = 1e9 + 7;

// vector算法

vector<vector<int>> v;
v.resize(n + 1);
v = vector<vector<int>>(n, vector<int>(n, 0)); // 之后就不要用push这种手法了
std::vector<int>
    copy(original.begin() + i, original.begin() + j + 1); // 截断copy子vector

// find使用方法
auto it = std::find(numbers.begin(), numbers.end(), target);
if (it != numbers.end())
{
    std::cout << "Element found at index: " << std::distance(numbers.begin(), it) << std::endl;
}
else
{
    std::cout << "Element not found" << std::endl;
}

// unordered_map
unordered_map<string, int> m;

int n = m.size();
m[key] = value; // 最简单的插入方法（个人认为）
m.erase(key);
s.count(key); // 常用来判断有无这一元素
// 遍历元素
for (auto it : m)
{
    cout << it.first << " " << it.second << endl;
}

// string
std::string str = "Hello, World!";

// append(str), += 或 push_back(ch)
str.append(" Welcome");
// insert(pos, str) 或 insert(pos, ch)
str.insert(5, " C++");
// erase(pos, len)
str.erase(7, 7);
// replace(pos, len, str)
str.replace(7, 4, "Coders");
// substr(pos, len)
std::string substr = str.substr(7, 6);
size_t found = str.find("AAAA");
if (found != std::string::npos)
{
    std::cout << "Substring found at position: " << found << std::endl;
}
else
{
    std::cout << "Substring not found" << std::endl;
}
// rfind(str, pos)
size_t lastFound = str.rfind("o");
// 查找首先出现的字符
size_t findfirst = str.find_first_of("Ao");
// 优先队列
//  大根堆
priority_queue<int> q; // 等同于 priority_queue<int, vector<int>, less<int>> a;
// 小根堆
priority_queue<int, vector<int>, greater<int>> q;

// deque
queue<int> q;

// 常用函数： front指队头，back指队尾（新插入的）
q.push_back(num);
q.push_front(num);
q.pop_back();
q.pop_front();

// 树与图的构造
// 注意是有方向还是无方向
vector<vector<int>> graph(n + 1);

//华为面试用的一行
stirng s,t;
cin>>s;
stringstream ss(s);
getline(ss,t,',');//用空格的方法
