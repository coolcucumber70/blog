#include<iostream>
#include<vector>
using namespace std;
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    string id;
    vector<TreeNode*> children;
    int severe_problems = 0;
    int general_problems = 0;
};

void aggregate_problems(TreeNode* node) {
    for (auto child : node->children) {
        aggregate_problems(child);
        node->severe_problems += child->severe_problems;
        node->general_problems += child->general_problems;
    }
}

int main() {
    int M, N;
    cin >> M >> N;
    cin.ignore();

    unordered_map<string, TreeNode*> nodeMap;
    unordered_set<string> rootsIdentified;
    
    vector<TreeNode*> roots;

    string line;
    while (N--) {
        getline(cin, line);
        stringstream ss(line);
        string node_id, parent_id;
        int severity, count;
        ss >> node_id >> parent_id >> severity >> count;

        if (nodeMap.find(node_id) == nodeMap.end()) {
            nodeMap[node_id] = new TreeNode{node_id};
        }
        TreeNode* node = nodeMap[node_id];
        if (severity == 0) {
            node->severe_problems += count;
        } else {
            node->general_problems += count;
        }

        if (parent_id == "*") {
            
           if (rootsIdentified.find(node_id) == rootsIdentified.end()) { // Check if not already identified as root
                roots.push_back(node);
                rootsIdentified.insert(node_id); // Mark this node as identified as root
            }
        } else {
            if (nodeMap.find(parent_id) == nodeMap.end()) {
                nodeMap[parent_id] = new TreeNode{parent_id};
            }
            nodeMap[parent_id]->children.push_back(node);
        }
    }

    // Aggregating problems
    for (auto root : roots) {
        aggregate_problems(root);
    }

    // Calculating risk count
    int risk_count = 0;
    for (auto root : roots) {
        int di_value = 5 * root->severe_problems + 2 * root->general_problems;
        cout << "Root " <