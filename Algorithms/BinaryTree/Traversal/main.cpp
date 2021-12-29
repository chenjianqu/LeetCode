#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode *left,TreeNode* right):val(x),left(left),right(right){}
};

///非递归的中序遍历
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode *> s;
    TreeNode *node = root;
    while (node != nullptr || !s.empty())
    {
        while (node != nullptr)
        {
            s.push(node);//保存一路走过的根节点
            node = node->left;
        }
        if (!s.empty())
        {
            node = s.top();
            res.push_back(node->val);
            s.pop();
            node = node->right;
        }
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
