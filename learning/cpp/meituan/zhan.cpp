#include <bits/stdc++.h>
using namespace std;
int evalRPN(vector<string>&tokens){
    stack<int>sta;
    for(auto str:tokens){
        if(isdigit(str[0])||(str[0]=='-'&&str.size()>1)){
            int num=stoi(str);
            sta.push(num);
        }
        else{
            int b=sta.top();
            sta.pop();
            int a=sta.top();
            sta.pop();
            if(str=="+")sta.push(a+b);
            if(str=="-")sta.push(a-b);
            if(str=="*")sta.push(a*b);
            if(str=="/")sta.push(a/b);
        }
    }
    return sta.top();
}
int main()
{

    int n;
    cout<<"input n:"<<endl;
    cin>>n;
    vector<string> v(n);
    cout << "input a vector" << endl;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v[i]=s;
    }
    int res=evalRPN(v);
    cout<<"res=="<<res<<endl;
    return 0;
}