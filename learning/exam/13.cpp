#include<bits/stdc++.h>
using namespace std;
#define long long int
#define _for(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
int n;
int res=0;
void travel(int index){
    if(index>n)return;
    res++;
    travel(index+1);
}
signed main(){
    cin>>n;
    _for(i,1,n){
        travel(i);
    }
    res+=n-2;

    cout<<res<<endl;
    system("pause");
    return 0;

}