// n个边，n个定点，那么就一定有环，遍历到环的时候停止就行了
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int visit[100] = {0};
int res[100] = {-1};
vector<int> circle;
vector<int> path;
int dfs(int index, vector<int> &graph)
{
    if (res[index] != -1)
    {
        return res[index];
    }
    else
    {
        path.push_back(index);
        if (visit[index] == 1)
        {
            path.pop_back();
            while(path.back()!=index){
                circle.push_back(path.back());
                path.pop_back();
            }
            return 0;
        }
        else
        {

            visit[index] = 1;
            res[index] = 1 + dfs(graph[index], graph);
            for(auto x:circle){
                //这一步写的不好，每一个节点都重复这一步，导致在覆盖
                res[x]=res[index];
            }
            return res[index];
        }
    }
}
int main()
{
    cout << "input n:" << endl;
    int n;
    std::cin >> n;
    std::fill(res, res + 100, -1);
    vector<int> graph(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        int b = a - 1;
        graph[i] = a - 1;
        /* code */
    }
    for (int i = 0; i < n; i++)
    {
        int xx = dfs(i, graph);
        path.clear();
        circle.clear();
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += res[i];
    }
    cout << "sum:" << sum << endl;
    return 0;
}