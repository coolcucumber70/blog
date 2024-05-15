#include <bits/stdc++.h>
#include <functional>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n));
    vector<int> Capacity(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> Capacity[i];
    }

    int faultyNode, faultycapacity;
    cin >> faultyNode >> faultycapacity;

    vector<pair<int, int>> dist;
    dist.push_back({faultyNode, 0});

    unordered_set<int> set;
    set.insert(faultyNode);

    function<void()> Caldist = [&]() -> void {
        pair<int, int> res = {-1, 10000};
        for (int j = 0; j < n; j++)
        {
            if (set.count(j))
                continue;
            pair<int, int> tmp = {-1, 10000};
            for (auto y : dist)
            {
                if (m[y.first][j] == -1)
                    continue;
                if (y.second + m[y.first][j] < tmp.second)
                {
                    tmp = {j, y.second + m[y.first][j]};
                }
            }
            if (tmp.second < res.second)
                res = tmp;
        }
        dist.push_back(res);
        set.insert(res.first);
    };

    while (dist.size() < n)
    {
        Caldist();
    }

    for (auto x : dist)
    {
        if (x.first == faultyNode)
            continue;
        cout <<"node:"<< x.first << " "<<x.second<<endl;
        // faultycapacity -= x.second;
        // if (faultycapacity <= 0)
        //     break;
    }
        for (auto x : dist)
    {
        if (x.first == faultyNode)
            continue;
        cout<<x.first<<" ";
        faultycapacity -= Capacity[x.first];
        if (faultycapacity <= 0)
            break;
    }

    return 0;
}