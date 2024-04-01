#include <iostream>
#include <string>
using namespace std;
int func(string str)
{
    int count = 1;
    double dcount[2] = {0, 0};
    char pre = str[0];
    int result = 0;
    for (int i = 1; i < str.size(); i++)
    {
        /* code */
        if (str[i] == pre)
        {
            count++;
            if (count == 2)
            {
                if (dcount[0] == 0)
                {
                    dcount[0] = 1;
                }
                else
                {
                    dcount[1] = 1;
                }
                if (dcount[0] == 1 && dcount[1] == 1)
                {
                    result++;
                    count--;
                    dcount[1] = 0.5;
                }
            }
            if (count == 3)
            {
                result++;
                count--;
            }
        }
        else
        {
            count = 1;
            if(dcount[1]==0.5){
                dcount[0]=0;
                dcount[1]=0;
            }
            pre = str[i];
        }
    }
    return result;
}
int main(){
    string str="aabbbccdd";
    int result=func(str);
    cout<<result<<endl;
}