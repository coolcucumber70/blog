#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn=1e5+10;
int n,q;
int a[maxn];

int main(){
 scanf("%d %d",&n,&q);
 ll cnt=0,sum=0;
 for(int i=1;i<=n;++i){
  scanf("%d",&a[i]);
  if(a[i]==0){
   cnt++;
  }else{
   sum+=a[i];
  }
 }
 long long l,r;
 while(q--){
  scanf("%d %d",&l,&r);
  printf("%lld %lld\n",sum+l*cnt,sum+r*cnt);
 }
 
 return 0;
}