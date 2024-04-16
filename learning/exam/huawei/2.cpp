#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>
using namespace std;

unordered_set<int> relations;
int n, m;
vector<vector<int>> office;
vector<vector<int>> visit;

int dfs(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || !relations.count(office[i][j]) || !visit[i][j])
    {
        return 0;
    }
    visit[i][j] = 1;
    return 1 + dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i, j - 1);
}
int main()
{

    cin >> n>>m;
    office = std::vector<std::vector<int>>(n, std::vector<int>(m, 0));
    visit = std::vector<std::vector<int>>(n, std::vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < m; j++)
        {
            int a;
            cin >> a;
            office[i][j] = a;
        }
    }
    int i, j;
    cin >> i, j;
    string s;
    getline(cin, s);
    stringstream ss(s);
    int x;
    while (ss >> x)
    {
        if (relations.count(x))
        {
            continue;
        }
        relations.insert(x);
    }
    int sum = dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i, j - 1);
    cout << sum;
    return 0;
}