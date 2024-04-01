
#include <thread>
#include <iostream>

using namespace std;
int j = 1;
void test()
{
    int n = 100;
    for (int i = 0; i < n; i++)
    {
        /* code */
        j++;
    }
};
int main(){
    thread t1(test);
    thread t2(test);
    t1.json();
    t2.json();
    cout<<"j="<<j<<endl;
    return 0;
}
