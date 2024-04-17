#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<string>> paper;
unordered_map<string, int> cost;

int main()
{
    cin >> n;
    paper = vector<vector<string>>(n, vector<string>(4));
    unordered_set<string> set;
    unordered_map<string, int> res;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        stringstream ss(s);
        int j = 0;
        while (getline(ss, paper[i][j], ','))
        {
            j++;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        vector<string> t(2);
        stringstream ss(s);
        int j = 0;
        while (getline(ss, t[j], ','))
        {
            j++;
        }
        cost[t[0]] = stoi(t[1]);
    }
    for (int i = 0; i < n; i++)
    {
        string str = paper[i][0] + paper[i][1] + paper[i][2];
        if (set.count(str))
        {
            continue;
        }
        else
        {
            set.insert(str);
            string clinet = paper[i][1];
            int value = stoi(paper[i][3]);
            if (value >= 0 && value <= 100)
            {
                if(!res.count(clinet)){
                    res[clinet]=0;
                }
                res[clinet] += value * cost[paper[i][2]];
            }
        }
    }
    sort(res.begin(),res.end(),[](pair<string,int>a,pair<string,int>b){
        return a.second<b.second;
    })
    for(auto x:res)
    {
        cout<<x.first<<','<<x.second<<endl;
    }
    return 0;
}