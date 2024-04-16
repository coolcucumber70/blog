#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>
int main()
{
    int n, q;
    cin >> n;
    cin >> q;
    unordered_map<string, vector<string>> map;
    unordered_map<string, int> sp;
    vector<string> propority;
    for (int i = 0; i < q; i++)
    {
        string por;
        cin >> por;
        propority.push_back(por);
    }
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            string por;
            cin >> por;
            map[por].push_back(name);
        }
    }
    for (auto pro : propority)
    {
        if (map.count(pro))
        {
            for (auto x : map[pro])
            {
                sp[x]++;
            }
        }
    }
    std::vector<std::pair<std::string, int>> sortedPairs(sp.begin(), sp.end());

    // 按照值从大到小排序
    std::sort(sortedPairs.begin(), sortedPairs.end(),
              [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
              {
                  return a.second > b.second;
              });

    // 输出排序后的键值对
    for (const auto &pair : sortedPairs)
    {
        std::cout  << pair.first <<" "<< std::endl;
    }
    return 0;

}