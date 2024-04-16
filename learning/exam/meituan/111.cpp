#include <iostream>
#include <vector>

using namespace std;

int countGoodMatrices(vector<vector<int>>& matrix) {
    int count = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < cols - 1; j++) {
            if (isGoodMatrix(matrix, i, j)) {
                count++;
            }
        }
    }

    return count;
}

bool isGoodMatrix(vector<vector<int>>& matrix, int row, int col) {
    int value = matrix[row][col];

    for (int i = row; i <= row + 1; i++) {
        for (int j = col; j <= col + 1; j++) {
            if (matrix[i][j] != value) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[j][i];
        }
    }

    int count = countGoodMatrices(matrix);
    cout << count << endl;

    return 0;
}