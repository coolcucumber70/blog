int dpfuc_diedai(vector<string> &str)
{
    unordered_set<char> set1;
    unordered_set<char> set2;
    int n = str.size();
    vector<int> dp(n);
    dp[n - 1] = str[n - 1].size();
    for (auto x : str[n - 1])
    {
        set1.insert(x);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        
        for (auto c : str[i])
        {
            if (set1.count(c))
            {
                set2.insert(c);
            }
        }
        dp[i] = set2.size() * dp[i + 1];
        set1.clear();
        set1 = set2;
        set2.clear();
    }
    return dp[0];
}
int dpfuc_digui(vector<string> &str, int index)
{
    if (index == str.size() - 1)
    {
        return str[index].size();
    }
    int num = 0;
    for (int i = 0; i < str[i].size(); i++)
    {
        if (str[index + 1].find(str[index][i]))
        {
            num++;
        }
    }
    return num * dpfuc_diedai(str);
}
int main()
{
    int n;
    cout << "input n" << endl;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v[i] = str;
    }
    cout<<"output"<<endl;
    int res1 = dpfuc_diedai( v);
    cout<<res1<<endl;
}