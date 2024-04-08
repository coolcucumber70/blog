#include <queue>
#include <stack>

// 队列
queue<int> q;
q.push(num);
q.pop();
int n=q.size();
bool isEmpty=q.empty();
int first=q.front(); // 队头
int last=q.back();   // 队尾：最后一个push进去的元素是队尾！

// 栈
stack<int>st;
st.push(num);
st.pop();
int top=q.top(); //栈顶元素
int n=st.size();
bool isEmpty=st.empty();

// 大根堆
priority_queue<int> q; //等同于 priority_queue<int, vector<int>, less<int>> a;

// 小根堆
priority_queue<int, vector<int>, greater<int>> q;


// 常用函数
q.push(num);
int top=q.top();
q.pop();


queue<int>q;

// 常用函数： front指队头，back指队尾（新插入的）
q.push_back(num);
q.push_front(num);
q.pop_back();
q.pop_front();
int num=q.front();
int num=q.back();
int n=q.size();
bool flag=q.empty();