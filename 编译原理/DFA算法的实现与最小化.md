# DFA与Hopcroft算法

## 1、DFA的形式定义

从形式上说，一个有限状态自动机可以用下面的5个参数来定义:

- Q: 状态q0, q1, ... , qN的有限集合
- Σ: 有限的输入符号字母表
- q0: 初始状态
- F: 终极状态的集合， F∈Q
- δ(q, i): 状态之间的转移函数或转移矩阵。给定一个状态q∈Q和一个输入符号i∈Σ， δ(q, i)返回一个新的状态q'∈Q。

## 2、DFA的C++实现

定义DFA状态节点

```cpp
//定义DFA状态节点
class DFA_node
{
    private:
        vector<char>      next_values;
        vector<DFA_node*> next_work_edges;

        int id;
        bool state;
        friend class DFA;
        friend class ReTree;

    public:
        DFA_node(int n,bool init_state = UNACCEPTABLE):next_values(),next_work_edges(),id(n),state(init_state){}

        void print_DFA(unordered_set<DFA_node*>& set);
};
inline void DFA_node::print_DFA(unordered_set<DFA_node*>& set)
{
    if(!this || set.find(this) != set.end())   return;
    cout << "now_DFA_id: " << id;

    //注释部分是 判断是否正确划分到一个子集中
    /*cout << ",now_NFA_ids: ";
    for(const auto& node: work_list)
        cout << node->id << " ";*/

    cout << ",state: " << (state == ACCEPTABLE ? "ACCEPTABLE" : "UNACCEPTABLE") << endl;
    set.emplace(this);

    int size = next_work_edges.size();
    cout << "next_DFA_id & cost_chr: ";
    for(int i=0;i<size;++i)
        cout << next_values[i] << "->" << next_work_edges[i]->id << " ";

    cout << "\n" << endl;
    for(int i=0;i<size;++i)
        next_work_edges[i]->print_DFA(set);
}

```

定义DFA

```cpp
class DFA
{
    private:
        DFA_node* root;
        vector<bool> visit;
        int node_cnt;
    public:
        DFA():root(nullptr),visit(),node_cnt(0) {}
        DFA(NFA* NFA):root(nullptr),visit(vector<bool> ((1 << NFA->total_nodes),false)),node_cnt(0) { build_DFA(NFA); }
        ~DFA()  {delete_all_nodes();}

        void build_DFA(NFA* NFA);
        void print_DFA_routes() const;
        void build(NFA_node* node,NFA_node* end);
        bool get_e_closure_set(unordered_set<NFA_node*>& set,deque<NFA_node*>& work_list,NFA_node* node,NFA_node* end,int& pos);

        void simplify_DFA();
        DFA_node* find_next_edge(DFA_node* node,char chr);
        void get_all_DFA_nodes(DFA_node* node,unordered_set<DFA_node*>& set,vector<DFA_node*>& total_nodes);
        void hopcraft();
        bool split(vector<vector<DFA_node*>>& sets,vector<DFA_node*>& set,unordered_map<DFA_node*,int>& map,int pos);
        void delete_all_nodes();

        friend class ReTree;
};
inline void DFA::print_DFA_routes() const
{
    unordered_set<DFA_node*> set;
    cout << "DFA_Print: " <<endl;
    cout << "Node_cnt: " << node_cnt << endl;
    root->print_DFA(set);
}

inline void DFA::build_DFA(NFA* NFA)
{
    build(NFA->start,NFA->end);
    simplify_DFA();
}

inline void DFA::build(NFA_node* start,NFA_node* end)
{
    deque<DFA_node*> work_lists{};
    deque<NFA_node*> work_list{},tmp{};
    deque<deque<NFA_node*>> next_work_lists{};

    unordered_set<NFA_node*> set;
    unordered_map<int,DFA_node*> cnt;

    int pos = 0,nodes = 0,id_max = 0;
    bool state = get_e_closure_set(set,tmp,start,end,pos);

    if(!tmp.empty())
    {
        auto node = new DFA_node(id_max++,state);
        work_lists.emplace_back(node);
        next_work_lists.emplace_back(tmp);
        root = node;
        visit[pos] = true;
        cnt[pos]   = node;
        ++nodes;
    }

    while(!work_lists.empty())
    {
        auto now_node = work_lists.front();
        work_lists.pop_front();

        work_list = next_work_lists.front();
        next_work_lists.pop_front();

        tmp.clear();
        set.clear();

        for(int i=1;i<256;++i)          // epsilon的情况不考虑进去 因为此时加入epsilon 全为此时工作集的
        {
            pos = 0;
            state = false;

            for(const auto& ptr:work_list)
            {
                if(ptr->value != i) continue;

                if(ptr->edge1)      state |= get_e_closure_set(set,tmp,ptr->edge1,end,pos);
                if(ptr->edge2)      state |= get_e_closure_set(set,tmp,ptr->edge2,end,pos);
            }

            if(!tmp.empty())
            {
                DFA_node* node = nullptr;
                if(visit[pos])          node = cnt[pos];
                else
                {
                    node = new DFA_node(id_max++,state);
                    visit[pos] = true;
                    cnt[pos] = node;
                    work_lists.emplace_back(node);
                    next_work_lists.emplace_back(tmp);
                    ++nodes;
                }

                now_node->next_values.emplace_back(static_cast<char>(i));
                now_node->next_work_edges.emplace_back(node);
                tmp.erase(tmp.begin(),tmp.end());
                set.clear();
            }
        }
    }
    node_cnt = id_max;
}

inline bool DFA::get_e_closure_set(unordered_set<NFA_node*>& set,deque<NFA_node*>& work_list,NFA_node* node,NFA_node* end,int& pos)
{
    if(!node)   return false;
    bool acceptable_state = false;
    deque<NFA_node*> tmp{node};

    while(!tmp.empty())
    {
        auto ptr = tmp.front();
        tmp.pop_front();
        if(set.find(ptr) != set.end())    continue;

        if(!ptr->value)
        {
            if(ptr->edge1)     tmp.emplace_back(ptr->edge1);
            if(ptr->edge2)     tmp.emplace_back(ptr->edge2);
        }

        work_list.emplace_back(ptr);
        pos |= (1 << ptr->id);
        set.emplace(ptr);

        if(ptr == end)
            acceptable_state = true;
    }
    return acceptable_state;
}

inline void DFA::simplify_DFA()
{
    hopcraft();
}

inline DFA_node* DFA::find_next_edge(DFA_node* node,char chr)
{
    if(node->next_values.empty())   return nullptr;

    int size = node->next_values.size();
    for(int i=0;i<size;++i)
    {
        auto tmp = node->next_values[i];
        if(tmp == chr)
            return node->next_work_edges[i];
    }
    return nullptr;
}
```



## 3、DFA最小化实例

下面给出一个例子：

如下是我们之前写出的 a(b|c)* 的 NFA：

![v2-11c0cf7eef5fb195f108062f99c9652d_1440w](D:\code_learning\Blog\picture\v2-11c0cf7eef5fb195f108062f99c9652d_1440w.jpg)

它可以对应转换成如下的 DFA：

![v2-e2897359eb858af8de9ba29ad3ee0df9_1440w](D:\code_learning\Blog\picture\v2-e2897359eb858af8de9ba29ad3ee0df9_1440w.jpg)

在上面的 DFA 中非接受状态和接受状态是不能够合并的，因为如果合并，就会接受一个 ε 串，这是明显不正确的。但是如果同样是接受状态或者同样是非接受状态的话就有可能。例如可以将 q2 和 q3 进行合并，得到一个新的接受状态 q4。得到新的 DFA，如下：

![](D:\code_learning\Blog\picture\v2-8028cece40f585c16d2d384ab4be1f83_1440w.png)

之后，我们还可以再对 q1 和 q5 进行融合得到 q5。

![v2-144a0fcf97ac95348d3ee44d9d6fbf69_1440w](D:\code_learning\Blog\picture\v2-144a0fcf97ac95348d3ee44d9d6fbf69_1440w.png)

这就是最终的状态最少的 DFA 。

最小化得到状态最少的 DFA 的好处在于，因为 DFA 最后的代码实现是在作为内部的一个数据结构表示，如果状态和边越少，则它占用的计算资源（内存、cache）会更少 ，可以提高算法的运行效率和速度。

## 4、Hopcroft 算法

```cpp
//基于等价类的思想
split(S)
    foreach(character c)
        if(c can split s)
            split s into T1, ..., Tk

hopcroft()
    split all nodes into N, A
    while(set is still changes)
        split(s)
```

![v2-1f16bc9343eb1764c11d59a5823dae2a_1440w](D:\code_learning\Blog\picture\v2-1f16bc9343eb1764c11d59a5823dae2a_1440w.png)

q1, q2, q3 都有对状态 a 的转移，但是 q1 和 q2 转移到了同样的一个状态 S2, q3 转移到了 S3。所以 q1, q2 可以看做一组，因为它们对 a 的行为是一致的，都到了 S2。q3 单独一组。所以 a 这个字符将 S1 切为了两个子集。这就是等价类的思想。

Hopsroft 算法就是先根据非终结状态与非终结状态将所有的节点分为 N 和 A 两大类。 N 为非终结状态，A 为终结状态，之后再对每一组运用基于等价类实现的切割算法。

定义split算法

```cpp
inline bool DFA::split(vector<vector<DFA_node*>>& sets,vector<DFA_node*>& set,unordered_map<DFA_node*,int>& map,int pos)
{
    if(set.size() <= 1)   return false;//<=1，也就是没有必要去划分了

    unordered_map<int,vector<DFA_node*>> DFA_map;
    unordered_set<int> id_set;
    int id_first = 0,new_id = -256;


    for(int i=1;i<256;++i)
    {
        auto chr = static_cast<char>(i);
        for(const auto& node:set)
        {
            auto next_ptr = find_next_edge(node,chr);
            int tmp_pos = (next_ptr ? map[next_ptr] : map[node]);

            if(node->next_values.empty())       //因为没有边链接 所以属于单独的状态,就是单独的状态，不会跟任何进行连接呢
            {
                tmp_pos = new_id;
                map[node] = new_id;
                ++new_id;
            }
            id_set.emplace(tmp_pos);
        }

        if(id_set.size() != 1)//这里说明，经过chr后，原本在一个集合里的状态集已经分离了，所以不再是1
        {
            id_set.clear();
            for(const auto& node:set)
            {
                auto next_ptr = find_next_edge(node,chr);
                int pos = (next_ptr ? map[next_ptr] : map[node]);
                id_set.emplace(pos);

                DFA_map[pos].emplace_back(node);
            }

            for(const auto& num:id_set)
            {
                if(id_first == 0)
                {
                    sets[pos] = DFA_map[num];
                    id_first = 1;
                    for(const auto& node:DFA_map[num])
                        map[node] = pos;
                }
                else
                {
                    sets.emplace_back(DFA_map[num]);
                    int now_size = sets.size() - 1;
                    for(const auto& node:DFA_map[num])
                        map[node] = now_size;
                }
            }
            return true;
        }
        id_set.clear();
    }
    return false;
}
```

定义Hopcroft 算法

```cpp
inline void DFA::hopcraft()
{
    if(!root)   return;
    bool can_be_split = true;
    vector<vector<DFA_node*>> sets(2,vector<DFA_node*>());
    vector<DFA_node*> total_nodes;
    unordered_set<DFA_node*> set;
    unordered_map<DFA_node*,int> map;

    get_all_DFA_nodes(root,set,total_nodes);

    for(const auto& node:total_nodes)
    {
        int num = (node->state == ACCEPTABLE);
        sets[num].emplace_back(node);
        map[node] = num;
    }

    while(can_be_split)
    {
        can_be_split = false;
        int size = sets.size();
        for(int i=0;i<size;++i)
        {
            if(sets[i].empty()) continue;
            can_be_split = split(sets,sets[i],map,i);
            if(can_be_split)    break;
        }
    }
    int root_id = map[root];

    /*for(const auto& set:sets)
    {
        cout << "id: " ;
        for(const auto& node:set)
        {
            cout << node->id << ' ';
        }
        cout << endl;
    }*/

    unordered_set<char> chr_set;
    unordered_set<int>  work_id_set;
    unordered_map<int,DFA_node*> node_map;
    deque<DFA_node*> work_list;
    deque<int> work_id;
    int id_max = 0;


    if(map.find(root) != map.end())
    {
        auto node = new DFA_node(id_max++);
        root = node;
        work_list.emplace_back(node);
        work_id.emplace_back(root_id);
    }

    while(!work_list.empty())
    {
        chr_set.clear();

        auto now_node = work_list.front();
        work_list.pop_front();

        int id = work_id.front();
        work_id.pop_front();

        for(auto& node:sets[id])
        {
            if(node->state == ACCEPTABLE)    now_node->state = ACCEPTABLE;
            int size = node->next_values.size();
            for(int i=0;i<size;++i)
            {
                char chr = node->next_values[i];
                if(chr_set.find(chr) == chr_set.end())
                {
                    chr_set.emplace(chr);
                    int node_id = map[node->next_work_edges[i]];
                    DFA_node* ptr = nullptr;

                    if(node_map.find(node_id) != node_map.end())    ptr = node_map[node_id];
                    else
                    {
                        ptr = new DFA_node(id_max++);
                        node_map[node_id] = ptr;
                    }

                    now_node->next_values.emplace_back(chr);
                    now_node->next_work_edges.emplace_back(ptr);

                    if(work_id_set.find(node_id) == work_id_set.end())
                    {
                        work_list.emplace_back(ptr);
                        work_id.emplace_back(node_id);
                        work_id_set.emplace(node_id);
                    }
                }
            }
        }
    }

    for(auto& node:total_nodes)
        free(node);
    node_cnt = id_max;
}
```

