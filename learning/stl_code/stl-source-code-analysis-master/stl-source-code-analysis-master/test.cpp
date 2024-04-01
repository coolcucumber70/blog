using namespace std;
#include<iostream>
template <typename T>
T mymax(T a, T b) {
    return a > b ? a : b;
}
int main(){
    double a=1.2,b=1.5;
    double result =mymax<double>(a,b);
    cout<<"max:"<<result<<endl;
}  