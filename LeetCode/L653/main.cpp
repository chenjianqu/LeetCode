#include <iostream>
#include <vector>
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
 * 653. 两数之和 IV - 输入 BST
给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
 */

/*
 * 思路1:采用中序遍历，将BST转换为升序数组。然后双指针遍历数组，判断是否存在两个值=k。
 */

bool findTarget(TreeNode* root, int k) {
    //首先根据中序遍历，将BST转换为升序数组，然后从两边开始遍历
    if(!root)
        return false;
    vector<int> arr;
    stack<TreeNode*> stk;
    auto p = root;
    while(p || !stk.empty()){
        while(p){
            stk.push(p);
            p=p->left;
        }
        if(!stk.empty()){
            p = stk.top();
            stk.pop();
            arr.push_back(p->val);
            p = p->right;
        }
    }

    int n = arr.size();
    for(int i=0;i<n;++i){
        for(int j=n-1;j>i;--j){
            int v = arr[i]+arr[j];
            if(v == k)
                return true;
            if(v<k)
                break;
        }
    }

    return false;
}


/*
 * 思路2：遍历二叉树，将最简单的方法就是遍历整棵树，找出所有可能的组合，判断是否存在和为 k 的一对节点。现在在此基础上做一些改进。
如果存在两个元素之和为 k，即 x+y=k，并且已知 x 是树上一个节点的值，则只需判断树上是否存在一个值为 y 的节点，使得 y=k-x。
 基于这种思想，在树的每个节点上遍历它的两棵子树（左子树和右子树），寻找另外一个匹配的数。在遍历过程中，将每个节点的值都放到一个 set 中。
对于每个值为 p 的节点，在 set中检查是否存在 k-p。如果存在，那么可以在该树上找到两个节点的和为 k；否则，将 p 放入到 set 中。
如果遍历完整棵树都没有找到一对节点和为 k，那么该树上不存在两个和为 k 的节点。
 */


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
