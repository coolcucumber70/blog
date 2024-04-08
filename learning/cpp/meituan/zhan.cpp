#include<iostream>
using namespace std;
class Solution
{
public:
    string simplifyPath(string path)
    {
        string res;
        for (auto  s : path)
        {
            if (isalpha(s))
            {
                res += s;
            }
            else if (s == '/')
            {
                if (!res.empty() && res.back() == '/')
                {
                    continue;
                }
                else if (!res.empty() &&res.back() == '.')
                {
                    res.pop_back();
                }
                else
                {
                    res += s;
                }
            }
            else if (s == '.')
            {
                if (!res.empty() &&res.back() == '.')
                {
                    res.pop_back();
                    if (res.size() > 1)
                    {
                        res.pop_back();
                    }
                    while(!res.empty()&&isalpha(res.back()))
                    {
                        res.pop_back();
                    }
                }
                else{
                    res+=s;
                }
            }
        }
        if(res.size()>1){
            res.pop_back();
        }
        return res;
    }
};
int main(){
    Solution sol;
    cout<<"input string:"<<endl;
    string str;
    cin>>str;
    string res=sol.simplifyPath(str);
    cout<<res<<endl;

}