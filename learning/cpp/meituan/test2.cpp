#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    std::cin>>n;
    vector<int>array(n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>array[i];
    }
    
    string strs;
    unordered_map<int,int>data;
    unordered_map<int,char>color;
    cin>>strs;
    for (int i = 0; i < n; i++)
    {
        /* code */
        data[array[i]]=i;
        color[array[i]]=strs[i];
    }
    vector<int>coparray(array);
    sort(array.begin(),array.end());
    int res=0;
    for (int i = 0; i < n; i++)
    {
        /* code */
        if(data[array[i]]==i){
            continue;
        }
        else{
            if(color[array[i]]=='R'&&color[coparray[i]]=='R'){
                int tmp=data[array[i]];
                data[array[i]]=i;
                data[coparray[i]]=tmp;
                
                res++;

            }
            else{
                return -1;
            }

        }
    }
    return res;
    
}