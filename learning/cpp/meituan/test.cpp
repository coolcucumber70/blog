#include <bits/stdc++.h>
using namespace std;
int isequal(int i, int j, int **arry)
{
    int count = 0;
    count = arry[i][j] + arry[i + 1][j] + arry[i][j + 1] + arry[i + 1][j + 1];
    return count == 2;
}
int main()
{
    int m, n;
    cin >> m >> n;
    int **array = new int *[m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> array[i][j];
            cout<< array[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            res += isequal(i, j, array);
        }
    }
    for (int i = 0; i < m; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    cout << res;
    return 0;
}