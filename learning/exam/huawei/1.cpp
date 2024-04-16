#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;
int main()
{
    vector<int> nums;
    string s;
    int x;
    int count=-1;
    int res=0;
    unordered_map<int, int> map;
    getline(cin, s);
    stringstream ss(s);
    int sum = 0;
    while (ss >> x)
    {
        if (map.count(x))
            map[x]++;
        else
            map[x] = 1;
        sum++;
        if(map[x]>count){
            count=map[x];
            res=x;
        }
        if(ss.peek()==',')ss.ignore();
    }
    if(count>sum/2){
        cout<<res;
    }
    else{
        cout<<0;
    }
    return 0;
}