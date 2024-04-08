#include <bits/stdc++.h>
using namespace std;
int res=0;
void  minkcal(int k, int index, string str)
{
    unordered_set<char>set;
    int type = 0;
    int num = 0;
    for (int i = index; i < str.size(); i++)
    {
        if(set.count(str[i])==0){
            type++;
            set.insert(str[i]);
        }
        num++;
        if(num*type>=k){
            res++;
            set.clear();
            num=0;
            type=0;
        }
    }
    return ;
};

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    string cin_str;
    string str;
    cin >> cin_str;
    for (int i = 0; i < cin_str.size(); i = i + 4)
    {
        string sub_str;
        char a = cin_str[i];
        for (int j = 0; j < cin_str[i + 3]-'0'; j++)
        {
            sub_str += a;
        }
        str += sub_str;
    }
    minkcal(k,0,str);
    if(res==0){
        cout<<-1;
    }
    else if(res==1){
        cout<<0;
    }
    else{
        cout<<res;
    }
    return 0;
}