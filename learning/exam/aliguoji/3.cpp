// 阿里国际第三题
#include<iostream>
#include<vector>
using namespace std;
//图的遍历
int n;
vector<int> graph;
vector<bool> visited;
void dfs(int index, int &count, int sindex)
{
    count++;
    if (visited[index] == true)
    {
        if (sindex == index)
        {
            return;
        }
        else
        {
            count--;
            return;
        }
    }
    visited[index] = true;
    dfs(graph[index], count,sindex);
    visited[index] = false;
}
int main()
{
    cin >> n;
    graph = vector<int>(n + 1);
    visited = vector<bool>(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> graph[i];
    }
    int sum = 0;
    for (int i = 1; i < n + 1; i++)
    {
        int count = 0;
        dfs(i, count, i);
        sum += count;
    }
    cout << sum;
}
