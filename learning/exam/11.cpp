#include <bits/stdc++.h>
using namespace std;

pair<int, int> dp(int k);
vector<pair<int, int>> memo;
int main()
{
    int n;
    cin >> n;
    vector<int> question(n);
    for (int i = 0; i < n; i++)
    {
        cin >> question[i];
    }
    vector<int> res;
     memo=vector<pair<int, int>>(n, {-1, -1});
    for (int i = 0; i < n; i++)
    {
        res.push_back(dp(question[i]).first);
        cout<<res[i]<<" ";
    }1
    return 0;
}

pair<int, int> dp(int k)
{
    pair<int, int> res = {100, 0};
    if (memo[k] != make_pair(-1, -1))
        return memo[k];
    if (k == 1)
        return {0, 0};
    for (int i = k - 1; i > 0; i--)
    {
        if (dp(i).second + i == k)
            res = res.first < dp(i).first + 1 ? res : make_pair(dp(i).first + 1, dp(i).second);
        if (i * 2 == k)
            res = res.first < dp(i).first + 2 ? res : make_pair(dp(i).first + 2, i);
        if (i + 1 == k)
            res = res.first < dp(i).first + 2 ? res : make_pair(dp(i).first + 2, 1);
    }

    memo[k] = res;
    return res;
}