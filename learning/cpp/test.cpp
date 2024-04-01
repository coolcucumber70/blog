#include <iostream>
#include <vector>
using namespace std;
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//二叉树的BFS与图的BFS还是有区别的，不要忘了

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>que;
        que.push(root);
        while(que.empty()){
            TreeNode*node =que.front();
            TreeNode*res_node=que.();
            que.pop();
            if(node->left)que.push(node->left);
            if(node->right)que.push(node->right);

        }
                                                                                                                               

    }
};