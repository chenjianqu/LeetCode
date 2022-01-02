# LeetCode
这是我的解算法题的代码和笔记。





## 数组
### L2022. 将一维数组转变成二维数组

**题目**:
给你一个下标从 0 开始的一维整数数组 original 和两个整数 m 和  n 。你需要使用 original 中 所有
元素创建一个 m 行 n 列的二维数组。  
original 中下标从 0 到 n - 1 （都 包含 ）的元素构成二维数组的第一行，下标从 n 到 2 * n - 1 （都
包含 ）的元素构成二维数组的第二行，依此类推。
请你根据上述过程返回一个 m x n 的二维数组。如果无法构成这样的二维数组，请你返回一个空的二维数组。

**代码：**
```C++
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n)
            return vector<vector<int>>();
        vector<vector<int>> arr(m);
        for(int i=0;i<original.size();i+=n ){
                vector<int> row(n);
            for(int j=0;j<n;++j){
                row[j] = original[i+j];
            }
            arr[static_cast<int>(i/n)]=row;
        }
        return arr;
    }
```









## 链表
### L141. 环形链表
**题目**：给你一个链表的头节点 head ，判断链表中是否有环。  
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，
评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链
表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。  
如果链表中存在环，则返回 true 。 否则，返回 false 。  

**解法：1** 哈希表  

**解法：2** Floyd 判圈算法  
我们先设置慢指针 slow 和快指针 fast ，慢指针每次走一步，快指针每次走两步，根据「Floyd 判圈算法」两个指针在有环
的情况下一定会相遇，此时我们再将 slow 放置起点 0，两个指针每次同时移动一步，相遇的点就是答案。  
这里简单解释为什么后面将 slow 放置起点后移动相遇的点就一定是答案了。假设环长为 L，从起点到环的入口的步数是 a，
从环的入口继续走 b 步到达相遇位置，从相遇位置继续走 c 步回到环的入口，则有 b+c=L，其中 L、a、b、c 都是正整数。
根据上述定义，慢指针走了a+b 步，快指针走了 2(a+b)步。从另一个角度考虑，在相遇位置，快指针比慢指针多走了若干圈，
因此快指针走的步数还可以表示成 a+b+kL，其中 k 表示快指针在环上走的圈数。联立等式，可以得到2(a+b)=a+b+kL解
得 a=kL-b，整理可得 a=(k-1)L+(L-b)=(k-1)L+c  

从上述等式可知，如果慢指针从起点出发，快指针从相遇位置出发，每次两个指针都移动一步，则慢指针走了 a 步之后到达环的入口，
快指针在环里走了 k−1 圈之后又走了 c 步，由于从相遇位置继续走 c 步即可回到环的入口，因此快指针也到达环的入口。两个指针在
环的入口相遇，相遇点就是答案。  

注意特点： 适用于判断图，判断环路，有且只有一个环的情况。图中有且只有一个点存在两个入度为 1，其他入度均为 0。  



### L21. 合并两个有序链表
**题目**：将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

**思路**：
我们可以用迭代的方法来实现上述算法。当 l1 和 l2 都不是空链表时，判断 l1 和 l2 哪一个链表的头节点的值更小，将较小
值的节点添加到结果里，当一个节点被添加到结果里之后，将对应链表中的节点向后移一位。  


### L203. 移除链表元素
**题目**：给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。   

**思路**：首先找到第一个不是val的节点，作为新链表的头节点。然后定义两个节点prev和p，p用来判断是否是val，prev用来当删除
p时保存链表的连接。

```C++
ListNode* removeElements(ListNode* head, int val) {
    struct ListNode* dummyHead = new ListNode(0, head);
    struct ListNode* temp = dummyHead;
    while (temp->next != NULL) {
        if (temp->next->val == val) {
            temp->next = temp->next->next;
        } else {
            temp = temp->next;
        }
    }
    return dummyHead->next;
}
```


### L206. 反转链表
**题目**：给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。 

**思路**：假设链表为 1→2→3→∅，我们想要把它改成 ∅←1←2←3。 在遍历链表时，将当前节点的 next 指针改为
指向前一个节点。由于节点没有引用其前一个节点，因此必须事先存储其前一个节点。在更改引用之前，还需要存储后一个节点。最后
返回新的头引用。  
代码：  
```C++
ListNode* reverseList(ListNode* head) {
    if(!head)  return head;
    auto p = head;
    auto rev = head;
    while(p){
        auto tmp = p;
        p=p->next;
        tmp->next = rev;
        rev = tmp;
    }
    head->next = nullptr;
    return rev;
}
```



### L83. 删除排序链表中的重复元素
**题目**：存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。
返回同样按升序排列的结果链表。

**思路**：定义一个while循环，当p->next && p->val == p->next->val 删除p即可。  
**解法**：
```C++
ListNode* deleteDuplicates(ListNode* head) {
    auto p = head;
    while(p){
        while(p->next && p->val == p->next->val){
            auto tmp =p->next;
            p->next = p->next->next;
            delete tmp;
        }
        if(p)
            p = p->next;
        else
            break;
    }
    return head;
}
```






## 树

### L144. 二叉树的前序遍历

**题目**：给你二叉树的根节点 `root` ，返回它节点值的 **前序** 遍历。

**思路**：迭代法和递归法

解答：

```
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr)
            return vector<int>();
        stack<TreeNode*> s;
        vector<int> output;
        auto node=root;
        while(node || !s.empty()){
            while(node!=nullptr){
                output.push_back(node->val);
                s.push(node);
                node = node->left;
            }
            if(!s.empty()){
                node = s.top();
                s.pop();
                node=node->right;
            }
        }

        return output;
    }
```





### L94. 二叉树的中序遍历

**题目**：给定一个二叉树的根节点 `root` ，返回它的 **中序** 遍历。

**思路**：迭代法和递归法

解答：

```
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
```

### L145. 二叉树的后序遍历

**题目**：给定一个二叉树，返回它的 *后序* 遍历。

**思路**：迭代法和递归法

解答：

```
    void traversal(vector<int>& arr,TreeNode* node){
        if(!node){
            return;
        }
        else{
            traversal(arr,node->left);
            traversal(arr,node->right);
            arr.push_back(node->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        traversal(arr,root);
        return arr;
    }
```

迭代法：通过定义一个prev指针，来判断当前是否已经递归完成了子树。

```
vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode *> stk;
        TreeNode *prev = nullptr;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->right == nullptr || root->right == prev) {
                res.emplace_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                stk.emplace(root);
                root = root->right;
            }
        }
        return res;
    }
```





### L102. 二叉树的层序遍历

**题目**：给你一个二叉树，请你返回其按 **层序遍历** 得到的节点值。 （即逐层地，从左到右访问所有节点）。

**思路1**：使用广度优先搜索，使用迭代法时，将节点和当前深度放入 队列中。这样就可以知道每个节点所在的层次。

**思路2**：使用广度优先搜索，使用迭代法时，同时拓展当前层的所有节点。如下：

```c++
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
```





### L104. 二叉树的最大深度

**题目**：给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

**思路1**：广度优先搜索或深度优先搜索，在将节点放入stack或queue时，同时放入深度。实现：

```C++
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
```

**思路2**：同L102





### L101. 对称二叉树

**题目**：给定一个二叉树，检查它是否是镜像对称的。

**思路1**：先层次遍历，再比较每层的数组是否对称。(比较麻烦)



**思路2**：如果一个树的左子树与右子树镜像对称，那么这个树是对称的。如果同时满足下面的条件，两个树互为镜像：

- 它们的两个根结点具有相同的值
- 每个树的右子树都与另一个树的左子树镜像对称

我们可以实现这样一个递归函数，通过「同步移动」两个指针的方法来遍历这棵树，ppp 指针和 qqq 指针一开始都指向这棵树的根，随后 ppp 右移时，qqq 左移，ppp 左移时，qqq 右移。每次检查当前 ppp 和 qqq 节点的值是否相等，如果相等再判断左右子树是否对称。  

首先我们引入一个队列，这是把递归程序改写成迭代程序的常用方法。初始化时我们把根节点入队两次。每次提取两个结点并比较它们的值（队列中每两个连续的结点应该是相等的，而且它们的子树互为镜像），然后将两个结点的左右子结点按相反的顺序插入队列中。当队列为空时，或者我们检测到树不对称（即从队列中取出两个不相等的连续结点）时，该算法结束。

```
    bool check(TreeNode *u, TreeNode *v) {
        queue <TreeNode*> q;
        q.push(u); q.push(v);
        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left); 
            q.push(v->right);

            q.push(u->right); 
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};
```




### L226. 翻转二叉树

**题目**：给定一个二叉树，翻转一棵二叉树。

**思路1**：递归。  
 在后序时，交换其左右节点
```C++
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
```


**思路2**：迭代  
使用广度优先搜索，对于每个从queue中取出的节点，交换其左右两节点。
```C++
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
```























