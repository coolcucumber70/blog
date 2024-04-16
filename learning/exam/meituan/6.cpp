#include<bits/stdc++.h>
using namespace std;
#define int long long
string colors;
struct Node{
    int Id;
    char Color;
    Node(int id,int color):Id(id),Color(color){};
};
vector<vector<Node>>tree;
int findsamerb(Node&node){
    if(tree[node.Id].empty()){
        return 0;
    }
    int res=0;
    int count=0;
    for(auto x :tree[node.Id]){
        int tmp=findsamerb(x);
        res+=tmp;
    }
    if(res!=0){
        return res+1;
    }
    else{
        for(auto x:tree[node.Id]){
            char c=node.Color;
            if(x.Color!=c){
                return res+1;
            }
        }
    }
    return 0; 
}
signed main() {
    int n;
    std::cin >> n;
    std::cin >> colors;
    colors=" "+colors;
    //tree.resize(n + 1);
    tree=vector<vector<Node>>(n+1);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        tree[u].push_back(Node(v,colors[v]));
    }
    Node node=Node(1,colors[1]);

    int res=findsamerb(node);
    std::cout << res << std::endl;
    system("pause");
    return 0;
}

