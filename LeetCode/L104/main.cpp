#include <iostream>
#include <stack>

using namespace std;

/*
 * ### L104. 二叉树的最大深度

**题目**：给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

**思路1**：广度优先搜索或深度优先搜索，在将节点放入stack或queue时，同时放入深度。

**思路2**：同L102
 *
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int maxDepth(TreeNode* root) {
    if(!root)
        return 0;
    int max_depth=0;
    stack<pair<TreeNode*,int>> stk;
    stk.push({root,1});
    while(!stk.empty()){
        auto [node,depth] = stk.top();
        stk.pop();
        if(node->left)stk.push({node->left,depth+1});
        if(node->right)stk.push({node->right,depth+1});
        if(depth>max_depth)
            max_depth=depth;
    }
    return max_depth;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
