#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int,vector<int>>que;
    int p,m,n;
    cin>>p>>m>>n;
    vector<int>guai(m);
    vector<int>boss(n);
    for(int i=0;i<m;i++){
        cin>>guai[i];
    }
    for(int i=0;i<n;i++){
        cin>>boss[i];
    }
    auto calfuc=[&guai,&p,&que](int k)->int{
        int cost=0;
        for(auto g:guai){
        if(g<=p){
            que.push();
            continue;
        }
        while(g<=p){
            if(p/10>que.top())p+=q/10;
            else{
                p+=que.top();
                que.pop();
            }
            cost++;
            if(p>=k)return cost;
        }
    }
    return -1;
    };
    for(auto x:boss){
        cout<<calfuc(x)<<" ";
    }
    return 0;


}