#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * 题目：给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 */

/*
 * 思路：采用广度优先搜索，每次取出该层中的所有节点同时扩展，即可知道哪些节点在同一层
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



vector<vector<int>> levelOrder(TreeNode* root) {
if(!root)
    return vector<vector<int>>();
queue<TreeNode*> q;
q.push(root);
vector<vector<int>> arr;
while(!q.empty()){
    int num = q.size();
    vector<int> level_vector;
    for(int i=0;i<num;++i){
        auto node = q.front();
        q.pop();
        if(node->left)q.push(node->left);
        if(node->right)q.push(node->right);
        level_vector.push_back(node->val);
    }
    arr.push_back(level_vector);
}
return arr;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
