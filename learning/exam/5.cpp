#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:
    int countHighestScoreNodes(vector<int> &parents)
    {
        struct Treenode
        {
            int node;
            vector<Treenode *> child;
            Treenode *parent = nullptr;
            int count = 1;
        };
        vector<Treenode> T(parents.size());
        for (int i = 1; i < parents.size(); i++)
        {
            T[parents[i]].child.push_back(&T[i]);
            T[i].parent = &T[parents[i]];
        }
        auto calcount = [&T](Treenode *root, auto &func) -> void
        {
            for (auto x : root->child)
            {
                func(x, func);
                root->count += x->count;
            }
        };
        pair<int, int> res = {0, 0};
        calcount(&T[0], calcount);
        for (auto x : T)
        {
            int p = 1, l = 1, r = 1;
            if (x.parent != nullptr)p = T[0].count - x.count;

            if (x.child.size() == 1)
            {
                l = x.child[0]->count;

            }
            else if(x.child.size() == 2)
            {
                l = x.child[0]->count;
                r = x.child[1]->count;
            }
            if (p * l * r == res.first)
            {
                res.second++;
            }
            else if (p * l * r > res.first)
            {
                res.first = p * l * r;
                res.second = 1;
            }
        }
        return res.second;
    }
};
int main(){
    Solution s;
    vector<int>v={-1,2,0,2,0};
    int res= s.countHighestScoreNodes(v);
    cout<<res<<endl;

}