#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node
{
    int s;
    char c;
    Node(int s,char c)
    {
        this->s=s;
        this->c=c;
    }
};
int n;
int ans=0;
vector<vector<Node>> graph(100005+1);
string s;
bool dfs(int u, int p)
    {   
        bool flag = false;
        for(auto [v,c]:graph[u])
        {
            if(v==p)
                continue;
            
            if(dfs(v,u)) {flag = true;}
            if(s[v-1]!=s[u-1])
            {
                flag = true;
            }
        }
        if(flag) {ans++;}
        return flag;
    };
signed main()
{
    
    int n;
    cin>>n;
    
    cin>>s;
   
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(Node(v, s[v-1]));
        graph[v].push_back(Node(u, s[u-1]));
    }
    
   
    dfs(1,-1);
   cout<<ans<<endl;
//    system("pause");
   return 0;

}