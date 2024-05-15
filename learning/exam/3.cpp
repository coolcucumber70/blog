// 我们将云服务看做一棵树，每个云服务在发布前尚未解决的问题称为云服务的遗留问题(云服务的遗留问题包含以该云服务为根节点的树上所有节点的问题),
// DI值(遗留问题缺陷密度)可以作为评估云服务发布的指标,当云服务DI值小于等于阈值时才准许云服务发布,否则视为风,险云服务，需要问题整改完成后重新进行发布评估。
// 现有一批云服务树，已给出云服务树各节点的问题数量，请通过计算输出风险云服务的个数。
// 计算公式:DI值<5x严重问题数+2x一般问题数,
// 其中每个节点的不同级别问题数量需要将该节点及该节点为根节点的所有子节点的相应级别问题数量求和。

// 输入描述:
// 第一行输入M和N(M≤100000,N≤1000),使用空格分隔,M 表示代表云服务阈值， N 表示接下来有 N 行问题统计数据;
// 接下来输入一个 N*4 的矩阵表，行内使用空格分隔，
// 第一列 A_i为服务节点,
// 第二列 B_i为 A_i 的父节点，如果 Ai 为云服务则无父节点，此时 Bi 用*号表示( A_i和 B_i取值为字符串,1≤字符串长度 <5,均由小写萸文字母或 *号组成),
// 第三列C_i为问题级別(C_i取值为(0,1),0表示严重问题,1表示一般问题)
// 第四列 D_i为该节点该级别的问题数量(D_i< 1000)
// 说明:输入保证只出现树的关系，不会出现连通图的情况。

// 输出描述：
// 风险云服务的个数

// 样例1:
// 输入:
// 40 12
// a * 0 2
// a * 1 2
// b a 0 3
// b a 1 5
// c a 1 3
// d a 0 1
// d a 1 3
// e b 0 2
// f * 0 8
// f * 1 10
// g f 1 2
// h * 0 4
// 输出:
// 2

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode
{
    string id;
    vector<TreeNode *> children;
    int severe_problems = 0;
    int general_problems = 0;
};

void aggregate_problems(TreeNode *node)
{
    for (auto child : node->children)
    {
        aggregate_problems(child);
        node->severe_problems += child->severe_problems;
        node->general_problems += child->general_problems;
    }
}

int main()
{
    int M, N;
    cin >> M >> N;
    cin.ignore();

    unordered_map<string, TreeNode *> nodeMap;
    unordered_set<string> rootsIdentified;

    vector<TreeNode *> roots;

    string line;
    while (N--)
    {
        getline(cin, line);
        stringstream ss(line);
        string node_id, parent_id;
        int severity, count;
        ss >> node_id >> parent_id >> severity >> count;

        if (nodeMap.find(node_id) == nodeMap.end())
        {
            nodeMap[node_id] = new TreeNode{node_id};
        }
        TreeNode *node = nodeMap[node_id];
        if (severity == 0)
        {
            node->severe_problems += count;
        }
        else
        {
            node->general_problems += count;
        }

        if (parent_id == "*")
        {

            if (rootsIdentified.find(node_id) == rootsIdentified.end())
            { // Check if not already identified as root
                roots.push_back(node);
                rootsIdentified.insert(node_id); // Mark this node as identified as root
            }
        }
        else
        {
            if (nodeMap.find(parent_id) == nodeMap.end())
            {
                nodeMap[parent_id] = new TreeNode{parent_id};
            }
            nodeMap[parent_id]->children.push_back(node);
        }
    }

    // Aggregating problems
    for (auto root : roots)
    {
        aggregate_problems(root);
    }

    // Calculating risk count
    int risk_count = 0;
    for (auto root : roots)
    {
        int di_value = 5 * root->severe_problems + 2 * root->general_problems;
        cout << "Root " << root->id << " has DI value " << di_value << endl;
        if (di_value > M)
        {
            risk_count++;
        }
    }

    cout << risk_count << endl;

    // Memory cleanup
    for (auto pair : nodeMap)
    {
        delete pair.second;
    }

    return 0;
}

// 我们将云服务看做一棵树，每个云服务在发布前尚未解决的问题称为云服务的遗留问题(云服务的遗留问题包含以该云服务为根节点的树上所有节点的问题),
// DI值(遗留问题缺陷密度)可以作为评估云服务发布的指标,当云服务DI值小于等于阈值时才准许云服务发布,否则视为风,险云服务，需要问题整改完成后重新进行发布评估。
// 现有一批云服务树，已给出云服务树各节点的问题数量，请通过计算输出风险云服务的个数。
// 计算公式:DI值<5x严重问题数+2x一般问题数,
// 其中每个节点的不同级别问题数量需要将该节点及该节点为根节点的所有子节点的相应级别问题数量求和。

// 输入描述:
// 第一行输入M和N(M≤100000,N≤1000),使用空格分隔,M 表示代表云服务阈值， N 表示接下来有 N 行问题统计数据;
// 接下来输入一个 N*4 的矩阵表，行内使用空格分隔，
// 第一列 A_i为服务节点,
// 第二列 B_i为 A_i 的父节点，如果 Ai 为云服务则无父节点，此时 Bi 用*号表示( A_i和 B_i取值为字符串,1≤字符串长度 <5,均由小写萸文字母或 *号组成),
// 第三列C_i为问题级別(C_i取值为(0,1),0表示严重问题,1表示一般问题)
// 第四列 D_i为该节点该级别的问题数量(D_i< 1000)
// 说明:输入保证只出现树的关系，不会出现连通图的情况。

// 输出描述：
// 风险云服务的个数

// 样例1:
// 输入:
// 40 12
// a * 0 2
// a * 1 2
// b a 0 3
// b a 1 5
// c a 1 3
// d a 0 1
// d a 1 3
// e b 0 2
// f * 0 8
// f * 1 10
// g f 1 2
// h * 0 4
// 输出:
// 2

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode
{
    string id;
    vector<TreeNode *> children;
    int severe_problems = 0;
    int general_problems = 0;
};

void aggregate_problems(TreeNode *node)
{
    for (auto child : node->children)
    {
        aggregate_problems(child);
        node->severe_problems += child->severe_problems;
        node->general_problems += child->general_problems;
    }
}

int main()
{
    int M, N;
    cin >> M >> N;
    cin.ignore();

    unordered_map<string, TreeNode *> nodeMap;
    unordered_set<string> rootsIdentified;

    vector<TreeNode *> roots;

    string line;
    while (N--)
    {
        getline(cin, line);
        stringstream ss(line);
        string node_id, parent_id;
        int severity, count;
        ss >> node_id >> parent_id >> severity >> count;

        if (nodeMap.find(node_id) == nodeMap.end())
        {
            nodeMap[node_id] = new TreeNode{node_id};
        }
        TreeNode *node = nodeMap[node_id];
        if (severity == 0)
        {
            node->severe_problems += count;
        }
        else
        {
            node->general_problems += count;
        }

        if (parent_id == "*")
        {

            if (rootsIdentified.find(node_id) == rootsIdentified.end())
            { // Check if not already identified as root
                roots.push_back(node);
                rootsIdentified.insert(node_id); // Mark this node as identified as root
            }
        }
        else
        {
            if (nodeMap.find(parent_id) == nodeMap.end())
            {
                nodeMap[parent_id] = new TreeNode{parent_id};
            }
            nodeMap[parent_id]->children.push_back(node);
        }
    }

    // Aggregating problems
    for (auto root : roots)
    {
        aggregate_problems(root);
    }

    // Calculating risk count
    int risk_count = 0;
    for (auto root : roots)
    {
        int di_value = 5 * root->severe_problems + 2 * root->general_problems;
        cout << "Root " << root->id << " has DI value " << di_value << endl;
        if (di_value > M)
        {
            risk_count++;
        }
    }

    cout << risk_count << endl;

    // Memory cleanup
    for (auto pair : nodeMap)
    {
        delete pair.second;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
    int v;
    int w;
    bool operator<(const edge &a) const
    {
        return w == a.w ? v > a.v : w > a.w;
    }
};
int n;
vector<vector<edge>> mp(10001);
vector<int> a(10001);
int src;
int need;
void deal()
{
    vector<int> dis(n, 1e18);
    dis[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    priority_queue<edge, vector<edge>> ans;
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u])
        {
            continue;
        }
        for (auto [v, w] : mp[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                // cost[v]=cost[u]+a[v];
                pq.push({dis[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        ans.push({i, dis[i]});
    }
    while (!ans.empty())
    {
        auto [u, w] = ans.top();
        ans.pop();
        if (w == 0)
            continue;
        // cout<<u<<" "<<a[u]<<" "<<need<<endl;
        if (a[u] >= need)
        {
            cout << u;
            return;
        }
        else
            cout << u << " ";
        need -= a[u];
    }
}
signed main()
{
    cin >> n;
    for (signed i = 0; i < n; i++)
    {
        for (signed j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x != -1)
            {
                mp[i].push_back({j, x});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> src;
    cin >> need;
    deal();
    // system("pause");
    return 0;
}