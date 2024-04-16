#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m;
    cin >> n;

    vector<vector<int>> nums(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }

    int res = 0;
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (nums[i][j] == nums[i][j + 1] && nums[i][j] == nums[i + 1][j] && nums[i][j] == nums[i + 1][j + 1]) {
                res++;
            }
        }
    }

    cout << res << endl;
    return 0;
}
