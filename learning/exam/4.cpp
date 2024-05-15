#include <bits/stdc++.h>
using namespace std;

char num;

int main()
{
    std::string s;
    getline(cin,s);
    char t;
    std::stringstream ss(s);
    vector<int>v;
    int i=0;
    while (ss >> t)
    {
        v.push_back(t);
        cout<<i++<<" ";
    }
    for(auto x:v){
        cout<<x<<" ";
    }
}
