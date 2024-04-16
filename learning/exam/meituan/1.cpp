#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <cstdint>

using namespace std;



int main() {
    int m, n;
    cin >> m >> n;
    vector<int> u(n);
    vector<int64_t> v(n);
    int index = 0;
    for (int i = 0; i < n; i++) {
        cin >> u[i] >> v[i];
        for (int64_t j = 0; j < v[i]; j++) {
            a[index++] = u[i];
        }
    }
    int q;
    cin >> q;
    vector<vector<int>> query(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> query[i][0] >> query[i][1];
    }
    sort(a.begin(), a.end());
    vector<int> res(q);
    for (int i = 0; i < q; i++) {
        int64_t product = 1;
        unordered_set<int64_t> list;
        list.insert(1);
        int sum = 1;
        for (int k = query[i][0] - 1; k <= query[i][1] - 1; k++) {
            if (list.find(a[k]) == list.end()) {
                sum++;
                list.insert(a[k]);
            }
            product *= a[k];
            if (list.find(product) == list.end()) {
                sum++;
                list.insert(product);
            }
        }
        for (int k = query[i][0] - 1; k <= query[i][1] - 1; k++) {
            product /= a[k];
            if (list.find(product) == list.end()) {
                sum++;
                list.insert(product);
            }
        }
        res[i] = sum % 1000000007;
    }
    for (int i = 0; i < q; i++) {
        cout << res[i] << endl;
    }
    return 0;
}