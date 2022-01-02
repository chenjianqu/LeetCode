#include <iostream>
#include <stack>

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
 * 题目：给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，
 * 这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
叶子节点 是指没有子节点的节点。
 */

/*
 * 思路1：迭代
 * 使用 深度优先搜索 或 广度优先搜索。在queue或stack中，同时保存到当前节点的路径和。如stack<tuple<TreeNode*,int>>
 */

/*
 * 思路2:递归
 * 假定从根节点到当前节点的值之和为 val，我们可以将这个大问题转化为一个小问题：是否存在从当前节点的子节点到叶子的路径，满足其路径和为 sum - val。
不难发现这满足递归的性质，若当前节点就是叶子节点，那么我们直接判断 sum 是否等于 val 即可（因为路径和已经确定，就是当前节点的值，我们只需要判断该路
 径和是否满足条件）。若当前节点不是叶子节点，我们只需要递归地询问它的子节点是否能满足条件即可。
 */


bool hasPathSum1(TreeNode* root, int targetSum) {
    if(!root)
        return false;
    stack<tuple<TreeNode*,int>> stk;//int表示路径和
    stk.push({root,root->val});
    while(!stk.empty()){
        auto [node,ps] = stk.top();
        stk.pop();
        if(!node->left && !node->right && ps==targetSum)
            return true;
        if(node->right)stk.push({node->right,node->right->val + ps});
        if(node->left)stk.push({node->left,node->left->val + ps});
    }
    return false;
}



bool hasPathSum(TreeNode *root, int sum) {
    if (root == nullptr) {
        return false;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return sum == root->val;
    }
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
}





int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
