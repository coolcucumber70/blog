#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int value) : val(value), next(nullptr) {}
};

class A
{
private:
    /* data */
public:
    const int Id;
    std::string Name;
    ListNode *Ptr;
    const int card = 201;
    void hello() const
    {
        std::cout << "hello" << std::endl;
    }
    void world()
    {
        std::cout << "world" << std::endl;
    }

    A(int id, std::string name, ListNode *ptr) : Id(id), Name(name), Ptr(nullptr) {}

    ~A()
    {
        if (Ptr != nullptr)
        {
            delete (Ptr);
        }
    }
};

class MyClass
{
public:
    static const int myConstant = 10;
    static const A ob;
    A Oc;
    const A Od;
    int mycount;
    int mycount1;
    int Id;
    string Name;
    ListNode *Node;
    static void myFunction()
    {
        std::cout << "Hello from myFunction!" << std::endl;
    }
    MyClass(int id, A &oc, int count) : Id(id), Oc(oc), Od(3, "lwh", Node), mycount(2), mycount1(count){};
};
ListNode *node = new ListNode(0);
const A MyClass::ob(1, "wfp", node); // 静态成员的定义和初始化

int main()
{
    // std::cout << MyClass::ob.Id << std::endl;
    // MyClass::myFunction();
    // std::cout << MyClass::ob.Name << std::endl;
    // MyClass::ob.hello();
    // std::cout << MyClass::ob.card << endl;
    ListNode *my_node = new ListNode(2);
    class A oc(2, "wfp2", my_node);
    MyClass Bigclass(1, oc, 2);
    Bigclass.Od.Name="2";
    Bigclass.Oc.Name="2";
    cout << Bigclass.Oc.Name << endl;
    cout << Bigclass.Oc.Id << endl;
    Bigclass.Oc.world();
    return 0;
}