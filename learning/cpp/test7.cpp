#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    std::vector<TreeNode*> children;
    TreeNode(int x) : val(x) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }

    TreeNode* lca = nullptr;

    for (TreeNode* child : root->children) {
        TreeNode* result = lowestCommonAncestor(child, p, q);
        
        if (result != nullptr) {
            if (lca == nullptr) {
                lca = result;
            } else {
                return root; // 当前节点是最低公共祖先
            }
        }
    }

    return lca;
}

int main() {
    // 创建树节点
    TreeNode* root = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node4 = new TreeNode(4);

    // 构建树结构
    root->children.push_back(node5);
    root->children.push_back(node1);
    node5->children.push_back(node6);
    node5->children.push_back(node2);
    node2->children.push_back(node7);
    node2->children.push_back(node4);
    node1->children.push_back(node0);
    node1->children.push_back(node8);

    TreeNode* p = node6;
    TreeNode* q = node4;

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != nullptr) {
        std::cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is " << lca->val << std::endl;
    } else {
        std::cout << "Lowest Common Ancestor not found." << std::endl;
    }

    // 释放内存
    delete node4;
    delete node7;
    delete node8;
    delete node0;
    delete node2;
    delete node6;
    delete node1;
    delete node5;
    delete root;

    return 0;
}