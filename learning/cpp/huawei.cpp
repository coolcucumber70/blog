#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void dfs(vector<std::vector<int>> &matrix, int index, int &count, vector<int> visit, int auth)
{
    if (visit[index] != 0)
    {
        return;
    }
    count++;
    visit[index] = 1;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (i == index || matrix[index][i] == 0)
        {
            continue;
        }
        if (auth > matrix[index][i])
        {
            dfs(matrix, i, count, visit, matrix[index][i]);
        }
    }
}
int main()
{
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> matrix[i][j];
        }
    }


    std::vector<int> exposed;
    std::string input;
    std::getline(std::cin, input);  // 读取输入的一行
    std::istringstream iss(input);
    int num;

    while (iss >> num) {
        exposed.push_back(num);
    }

    int res = INT_MIN;
    int res_node = -1;
    for (auto node : exposed)
    {
        vector<int> visit(N, 0);
        int count = 0;
        cout << "node:" << node << endl;
        dfs(matrix, node, count, visit, INT_MAX);
        cout << "node:" << node << "R:" << count << endl;
        if (count > res)
        {
            res = count;
            res_node = node;
        }
    }
    cout << res_node;

    return 0;
}