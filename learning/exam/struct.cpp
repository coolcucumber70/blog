#include <iostream>
#include <vector>

// 链表节点
template <typename T>
struct ListNode {
    T data;
    ListNode<T>* next;

    ListNode(const T& value) : data(value), next(nullptr) {}
};

// 树节点
template <typename T>
struct TreeNode {
    T data;
    std::vector<TreeNode<T>*> children;

    TreeNode(const T& value) : data(value) {}
};

// 图节点
template <typename T>
struct GraphNode {
    T data;
    std::vector<GraphNode<T>*> neighbors;

    GraphNode(const T& value) : data(value) {}
};

int main() {
    // 构造链表
    ListNode<int>* head = new ListNode<int>(1);
    ListNode<int>* node1 = new ListNode<int>(2);
    ListNode<int>* node2 = new ListNode<int>(3);
    head->next = node1;
    node1->next = node2;

    // 构造树
    TreeNode<char>* root = new TreeNode<char>('A');
    TreeNode<char>* nodeB = new TreeNode<char>('B');
    TreeNode<char>* nodeC = new TreeNode<char>('C');
    TreeNode<char>* nodeD = new TreeNode<char>('D');
    root->children.push_back(nodeB);
    root->children.push_back(nodeC);
    nodeB->children.push_back(nodeD);

    // 构造图
    GraphNode<std::string>* nodeX = new GraphNode<std::string>("X");
    GraphNode<std::string>* nodeY = new GraphNode<std::string>("Y");
    GraphNode<std::string>* nodeZ = new GraphNode<std::string>("Z");
    nodeX->neighbors.push_back(nodeY);
    nodeY->neighbors.push_back(nodeZ);
    nodeZ->neighbors.push_back(nodeX);

    // 打印链表
    ListNode<int>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // 打印树
    std::cout << root->data << std::endl;
    for (const auto& child : root->children) {
        std::cout << "- " << child->data << std::endl;
        for (const auto& grandchild : child->children) {
            std::cout << "-- " << grandchild->data << std::endl;
        }
    }

    // 打印图
    std::cout << nodeX->data << std::endl;
    for (const auto& neighbor : nodeX->neighbors) {
        std::cout << "- " << neighbor->data << std::endl;
    }

    // 释放内存
    delete nodeZ;
    delete nodeY;
    delete nodeX;
    delete nodeD;
    delete nodeC;
    delete nodeB;
    delete root;

    // 释放链表内存
    current = head;
    while (current != nullptr) {
        ListNode<int>* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}