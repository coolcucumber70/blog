# include<vector>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
const int MOD = 1e9 + 7;
int<vector> vec(n); // n指定长度

// 常用函数
vec.push_back(number);
vec.pop_back();
int n=vec.size();

// 其它函数
vec.clear();
bool flag=vec.empty();
  // 使用构造函数创建副本
    std::vector<int> copy(original);

    std::vector<int> copy(original.begin() + i, original.begin() + j + 1);

// 遍历方法
//1. 传统方法
int n=vec.size();
for(int i=0;i<n;i++{
  cout<<vec[i]<<endl;
}

//2. C++11中的方法
  for (auto num:vec)
  {
    cout<<num<<endl;
  }

  auto it = std::find(numbers.begin(), numbers.end(), target);

    if (it != numbers.end()) {
        std::cout << "Element found at index: " << std::distance(numbers.begin(), it) << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }