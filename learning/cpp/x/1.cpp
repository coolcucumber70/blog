#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int sum = 0;
    char tmp = s[0];
    int cnt = 1;
    vector<int> a;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == tmp)
        {
            cnt += 1;
            if (s.size() - 1 == i)
            {
                if (cnt > 2)
                    sum += cnt - 2;
                a.push_back(min(cnt, 2));
            }
        }
        else
        {
            if (cnt > 2)
                sum += cnt - 2;
            a.push_back(min(cnt, 2));
            cnt = 1;
            tmp = s[i];
        }
    }
    int tmp1 = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == tmp1 && a[i] == 2)
        {
            sum += 1;
            tmp1 = 1;
        }
        else
        {
            tmp1 = a[i];
        }
    }
    cout << sum << endl;
}