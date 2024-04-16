// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> adj[100005]; // 存储有向图
// bool visited[100005];    // 标记节点是否被访问过
// int reachable[100005];   // 存储每个节点可以到达的节点数量
// int n;                   // 节点数量
// int cnt;                 // 用于在DFS中计数可以到达的节点数量

// void dfs(int node) {
//     visited[node] = true; // 标记当前节点为已访问
//     cnt++;                // 增加可以到达的节点数量
//     for(int next : adj[node]) { // 遍历当前节点的所有出边
//         if(!visited[next]) {
//             dfs(next); // 如果未访问，则继续深度优先搜索
//         }
//     }
// }
// int main() {
//     cin >> n; // 输入节点数量
//     for(int i = 1; i <= n; ++i) {
//         int a;
//         cin >> a; // 输入每个节点的出边
//         adj[i].push_back(a); // 建立有向图
//     }

//     int totalPairs = 0; // 总的二元组数量
//     for(int i = 1; i <= n; ++i) {
//         fill_n(visited, n + 1, false); // 重置访问标记
//         cnt = 0; // 重置计数器
//         dfs(i); // 从节点i开始深度优先搜索
//         reachable[i] = cnt; // 记录节点i可以到达的节点数量
//         totalPairs += cnt; // 累加到总二元组数量中
//     }

//     cout << totalPairs << endl; // 输出总的二元组数量
//     return 0;
// }


//第3题

struct LargerNumberComparator {
    bool operator()(const std::string& a, const std::string& b) {
        // 比较两个数字字符串的组合哪个更大
        return a + b > b + a;
    }
};

string largestNumber(const std::vector<int>& nums) {
    // 将整数转换为字符串
    vector<string> asStrs;
    for (int i = 0; i < nums.size();i++) {
        asStrs.push_back(toString(nums[i]));
    }

    // 使用自定义的比较器来排序
    sort(asStrs.begin(), asStrs.end(), LargerNumberComparator());

    // 如果最大的数字是“0”，则整个数字是0
    if (!asStrs.empty() && asStrs[0] == "0") {
        return "0";
    }

    // 构建最终的字符串
    string largestNumberStr;
    for (const std::string& numStr : asStrs) {
        largestNumberStr += numStr;
    }

    return largestNumberStr;
}