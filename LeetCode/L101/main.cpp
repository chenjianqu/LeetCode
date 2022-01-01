#include <iostream>
#include <tuple>
#include <vector>
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
 ***题目**：给定一个二叉树，检查它是否是镜像对称的。
 */


/*
 ***思路1**：先层次遍历，再比较每层的数组是否对称。(比较麻烦)
 */


bool isSymmetric(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int left_num=0,right_num=0;
        int n = q.size();
        vector<tuple<int,bool,bool>> arr;//int表示数值，bool表示左子树还是右子树,bool表示是null
        for(int i=0;i<n;++i){
            auto node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                arr.push_back({node->left->val,true,false});
                left_num++;
            }
            else{
                arr.push_back({0,true,true});
            }
            if(node->right){
                q.push(node->right);
                arr.push_back({node->right->val,false,false});
                right_num++;
            }
            else{
                arr.push_back({0,false,true});
            }
        }


        //检查是否对称
        if(left_num!=right_num){
            return false;
        }

        n =arr.size();


        for(int i=0;i<n/2;++i){
            auto [left_val,left_l,left_null] = arr[i];
            auto [right_val,right_l,right_null] = arr[n-1-i];
            if(left_null!=right_null){
                return false;
            }
            if(left_null==false){
                if(left_val !=right_val ||  left_l ==right_l){
                    return false;
                }
            }
        }

    }
    return true;
}


/*
 ***思路2**：先层次遍历，再比较每层的数组是否对称。(比较麻烦)
 */



int main()
{

    std::cout << "Hello, World!" << std::endl;



    return 0;
}
