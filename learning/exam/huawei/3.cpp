#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> nums;
vector<int> f;
vector<int> res;
vector<int>ans;
int Find(int x)
{
    if (x == f[x])
        return x;
    else
    {
        f[x] = Find(x);
        return f[x];
    }
}
int main()
{
    int n;
    cin >> n;
    nums = vector<vector<int>>(n, vector<int>(n, 0));
    res = vector<int>(n, 0);
    f = vector<int>(n);
    iota(f.begin(), f.end(), 0);
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nums[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(nums[i][j==0]){
                continue;
            }
            int m=Find(i);
            int n=Find(j)
            if(m==n)res[m]+=nums[i][j];
            else{
                p[n]=m;
                res[m]+=nums[i][j]+res[n];
            }
        }
    }
    for(int i=0;i<n;i++){
        if(f[i]==i){
            ans.push_back(res[i]);
        }
    }
    sort(ans.begin(),ans.end(),[](int a,int b){return a>b});
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;

}