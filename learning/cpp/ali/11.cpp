#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"input n:"<<endl;
    cin >> n;
    vector<string> v;
    cout<<"input strings:"<<endl;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }
    vector<vector<int>> visit(n, vector<int>(n, 0));
    int i, j;
    cout<<"input i j:"<<endl;
    cin >> i;
    cin >> j;
    i=i-1;
    j=j-1;
    cout<<i<<" "<<j<<endl;
    int res = 0;
    while (i >= 0 && i < n && j >= 0 && j < n)
    {
        res++;
        visit[i][j]++;
        if (visit[i][j]> 2)
        {
            res = -1;
            break;
        }
        else if (v[i][j] == '>')
        {
           
            v[i][j] = '<';
             j++;
        }
        else if (v[i][j] == '<')
        {
            
                v[i ][j] = '>';
                j-- ;
        }
        else if (v[i][j] == '^')
        {
            
            v[i][j] = 'v';
            i--;
        }
        else if (v[i][j] == 'v')
        {
            
            v[i][j] = '^';
            i++;
        }
    }
    cout<<res;
    return 0;
}
