#include <bits/stdc++.h>
using namespace std;
class HitCounter
{
private:
    int count;
    queue<int> que;

public:
    HitCounter(int count)
    {
        this->count = count;
    }
    int getHits(int num)
    {
        while ((!que.empty()) && num - 300 >= que.front())
        {
            que.pop();
            count--;
        }
        return count;
    }
    void hit(int num)
    {
        que.push(num);
        count++;
    }
};
int main()
{
    string hitstr;
    string timestr;
    vector<string> hitvec;
    //cin >> hitstr;
    //cin.ignore();
    getline(cin,hitstr);
    stringstream ii(hitstr);
    string str;
    while (getline(ii, str, ','))
    {
        hitvec.push_back(str);
    };
    getline(cin, timestr);
    stringstream hh(timestr);
    int num;
    vector<int> time;
    time.push_back(-1);
    while (hh >> num)
    {
        time.push_back(num);
    }
    vector<int> res(hitvec.size(), -1);
    HitCounter h(0);
    for (int i = 1; i < hitvec.size(); i++)
    {
        if (hitvec[i] == "hit")
            h.hit(time[i]);
        else if (hitvec[i] == "getHits")
            res[i] = h.getHits(time[i]);
    }
    for (auto x : res)
    {
        cout << x << " ";
    }
    return 0;
}