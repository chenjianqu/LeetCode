#include <iostream>

#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * 题目：翻转一棵二叉树。
 */

/*
 * 思路1：递归。
 * 在后序时，交换其左右节点
 *
 * 思路2：迭代
 * 使用广度优先搜索，对于每个从queue中取出的节点，交换其左右两节点。
 */

TreeNode* invertTree1(TreeNode* root) {
    if(!root)
        return root;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        auto tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        if(node->left)q.push(node->left);
        if(node->right)q.push(node->right);
    }
    return root;
}


TreeNode* invertTree(TreeNode* root) {
    if(!root)
        return root;
    invertTree(root->left);
    invertTree(root->right);
    auto tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    return root;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
