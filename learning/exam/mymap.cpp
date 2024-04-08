
#include <bits/stdc++.h>
using namespace std;// 集合
#include<set>

set<int> s;

// 常用函数
int n=s.size();
s.insert(num);
s.erase(num);
s.count(num); // 常用来判断有无这一元素

// 遍历元素
set<int>::iterator it;
for(it = s1.begin(); it!=s1.end(); it++){ //自动排序元素
    cout<<*it<<endl;  // 这里的it是个指向数据的指针
}
// map
map<string, int> m;

// 常用函数
int n=m.size();
m[key]=value; // 最简单的插入方法（个人认为）
m.erase(key);
s.count(key); // 常用来判断有无这一元素
// 遍历元素
map<string, int>::iterator it;
for (it = m.begin(); it != m.end(); it++) {
    cout<<it->first<<" "<<it->second<<endl;
}
// c++ 11
for(auto it : m){
    cout<<it.first<<" "<<it.second<<endl;
}