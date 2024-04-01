#include<iostream>
using namespace std;
class OBJ{
private:
    string Name ;
    int* arry;
public:
    OBJ(int lenth,string name):Name(name){
        arry= new int[lenth];
        std::cout<<"obj"<<endl;
    }
    ~OBJ(){
        delete []arry;
        std::cout<<"~"<<Name<<endl;
    }
}
OBJ o1(3,"o1");
int main(){
    OBJ o2(4,"o2");
    OBJ* o3=new OBJ(5,"o3")
    return 0;
}
