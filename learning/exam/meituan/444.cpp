#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int countFactors(long long n) {
    int count = 0;
    for (long long d = 1; d <= n; d++) {
        if (n % d == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> a;
    for (int i = 0; i < n; i++) {
        int u;
        long long v;
        cin >> u >> v;
        for (int j = 0; j < v; j++) {
            a.push_back(u);
        }
    }

    int q;
    cin >> q;
    vector<vector<int> > query(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> query[i][0] >> query[i][1];
    }

    

    vector<int> res(q);
    for (int i = 0; i < q; i++) {
        long long product = 1;
        for (int k = query[i][0] - 1; k <= query[i][1] - 1; k++) {
            product *= a[k];
        }
        int factorsCount = countFactors(product);
        res[i] = factorsCount % 1000000007;
    }

    for (int i = 0; i < q; i++) {
        cout << res[i] << endl;
    }

    return 0;
}