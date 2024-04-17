#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, char>>> edges;
int dfs(int node)
{
    int childrenCount = 0;
    int nocut = -1;
    for (auto child : edges[node])
    {
        childrenCount++;
        if (edges[child].second == 'N')
        {
            nocut = child;
        }
    }
    if (edges[node].size()==1||edges[node].empty())
    {
        return 0;
    }
    if (nocut != -1)
    {
        int count = 0;
        for (auto child : edges[node])
        {
            if (child!=nocut)
                count += dfs(child);
        }
        for (auto rchild : edges[nocut])
        {
            count += dfs(rchild);
        }
        return edges[node].size() - 1 + edges[child].size() + count;
    }
    else
    {
        int count = 0;
        for (auto child : edges[node])
        {
            int nocut = -1;
            int res = INT_MAX;
            for (auto rchild : edges[child])
            {
                if (edges[child].second == 'N')
                {
                    nocut = child;
                    break;
                }
            }
            if (nocut == -1)
            {
                for (auto ochild : edges[node])
                {
                    if (ochild != child)
                        count += dfs(rchild);
                    for (auto rchild : edges[child])
                    {
                        count += dfs(rchild);
                    }
                    res = min(res, edges[node].size() - 1 + edges[child].size() + count;)
                }
            }
            else
            {
                for (auto ochild : edges[node])
                {
                    if (ochild != nocut)
                        count += dfs(rchild);
                }
                for (auto rchild : edges[nocut])
                {
                    count += dfs(rchild);
                }
                return redges[node].size() - 1 + edges[child].size() + count;
            }
        }
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    edges = vector<vector<pair<int, char>>>(n);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        char type;
        cin >> u >> v >> type;
        edges[u].push_back({v, type});
        //edges[v].push_back({u, type});
    }
    TreeNode *root = buildTree(n, edges);
    int cuts = 0;
    dfs(root, cuts);

    cout << cuts << endl;

    return 0;
}
