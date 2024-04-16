#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

using namespace std;

vector<int> maxHeroes(const vector<int>& costs, int coins) {
    // 创建一个包含成本及其原始索引的pair数组

    if (coins <= 0) {
    return vector<int>();  // 如果金币数不合法，直接返回空的整数向量
}
if (costs.empty()) {
    return vector<int>();  // 如果英雄成本列表为空，直接返回空的整数向量
}敲下这个试试
其实都包括了
    vector<pair<int, int>> indexedCosts;
  
    for (int i = 0; i < costs.size(); i++) {
        indexedCosts.push_back({costs[i], i});
    }
有没有考虑到的，66 啥意思你加一下边界检查试试,可能是空数组没定义的原因。啥意思，不存在越界
定义的就是空的
最后有里子有可能int越界
65535 youknow tal+[]>65535 -----》-变复数了所以满足了小于coisns，   
你定义默认就是空，不行就试试培晨的，在下面
    // 根据成本对这些pair进行排序
    sort(indexedCosts.begin(), indexedCosts.end());

    vector<int> result; // 用来存放可以购买的英雄的索引
    vector<int> ans; 
    int totalCost = 0; // 已经花费的金币总数

    for (const auto& p : indexedCosts) {
        int cost = p.first;  // 价格
        int index = p.second; // 原始索引

        if (totalCost + cost <= coins) { // 检查是否有足够的金币购买当前英雄
            totalCost += cost; // 更新已花费的金币数
            result.push_back(index); // 将此英雄的原始索引添加到结果列表中
        } else {
            break; // 如果金币不够购买当前英雄，结束循环
        }
    }
    
    // 根据原始索引排序结果，以保持按原始数组的顺序输出
    sort(result.begin(), result.end());
    for (int a : result) {
         ans.push_back(costs[a]);//res[i] = res[costs[i]]buyong ans le 
    }
   
    return ans.empty()? vector<int>():ans; // 返回可以购买的英雄的索引列表
}

int main() {
    vector<int> costs = {2, 1, 3, 4, 5}; // 英雄的定价列表
    int coins = 10; // 可用的点券数量

    vector<int> purchasedHeroes = maxHeroes(costs, coins);

    cout << "Indices of heroes you can buy: "<<endl;
    for (int index : purchasedHeroes) {
        cout << index << " ";
    }看一下空例
    cout << x<<有没有可能，第一个数组的sort，比较first

    return 0;
}

。。。。。。。。。。。。。。。。。培晨版本
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list;

void maxNumberOfHeroes(vector<int>& nums, int coins) {
    sort(nums.begin(), nums.end()); // 将价格数组进行排序

    int numHeroes = 0; // 用于计数购买的英雄数量
    for (int cost : nums) {
        if (coins >= cost) {
            coins -= cost; // 购买英雄，减少相应的点券
            list.push_back(cost); // 增加已购买的英雄数量
        } else {
            break; // 如果点券不足以购买下一个英雄，终止循环
        }
    }
}白扯啊

int main() {
    vector<int> costs = {15,10,11,10};
    vector<int> nums = costs;
    int coins = 5;
    maxNumberOfHeroes(nums, coins);
    vector<int> res;
    
    for (int cost : costs) {
        if (find(list.begin(), list.end(), cost) != list.end()) {
            res.push_back(cost);
        }
    }
    
    for (int j = 0; j < res.size(); j++) {
        cout << res[j] << endl;
    }
    
    return 0;
}


培晨超自信版本 输入输出什么要求啊
----------------------------
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list;

void maxNumberOfHeroes(vector<int>& nums, int coins) {
    sort(nums.begin(), nums.end()); // 将价格数组进行排序

    int numHeroes = 0; // 用于计数购买的英雄数量
    for (int cost : nums) {
        if (coins >= cost) {
            coins -= cost; // 购买英雄，减少相应的点券
            list.push_back(cost); // 增加已购买的英雄数量
        } else {
            break; // 如果点券不足以购买下一个英雄，终止循环
        }
    }
}

int main() {
    vector<int> costs = {2, 3, 5, 7, 1, 4, 6};
    vector<int> nums = costs;
    int coins = 15;
    maxNumberOfHeroes(nums, coins);
    vector<int> res;
    
    for (int cost : costs) {
        if (find(list.begin(), list.end(), cost) != list.end() && coins >= cost) {
            res.push_back(cost);
            coins -= cost;
        }
    }
    
    for (int j = 0; j < res.size(); j++) {
        cout << res[j] << endl;
    }
    
    return 0;
}