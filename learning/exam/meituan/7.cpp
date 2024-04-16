
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> adj;
string colors;
vector<bool> visited;
int count = 0;

// DFS函数返回当前节点的子树包含的颜色类型
pair<bool, bool> dfs(int node) {
    visited[node] = true;
    bool hasRed = colors[node] == 'R';
    bool hasBlack = colors[node] == 'B';
    
    for (int child : adj[node]) {
        if (!visited[child]) {
            auto subtree = dfs(child);
            hasRed |= subtree.first;
            hasBlack |= subtree.second;
        }
    }
    
    // 如果这个节点的子树包含红色和黑色，则符合条件
    if (hasRed && hasBlack) {
        count++;
    }
    
    return {hasRed, hasBlack};
}

int main() {
    int n;
    cin >> n;
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    
    cin >> colors; // colors字符串从索引0开始，因此对应关系需要调整
    colors = " " + colors; // 将索引对齐，使得1号节点对应colors[1]

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    
    cout << count << endl;
    
    return 0;
}