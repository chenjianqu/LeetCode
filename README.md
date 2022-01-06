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


### L136. 只出现一次的数字

**题目**:题目：给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。  
说明：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

**思路1**：使用哈希表对数组元素进行计数，最后遍历哈希表，找到计数为1的数。
```C++
int singleNumber(vector<int>& nums) {
    std::unordered_map<int,int> d;
    for(int i=0;i<nums.size();++i){
        if(d.find(nums[i])==d.end())
            d.insert({nums[i],1});
        else
            d[nums[i]]++;
    }
    for(auto [num,count] : d) if(count==1) return num;
    return 0;
}
```

**思路2**：使用异或运算。
  如何才能做到线性时间复杂度和常数空间复杂度呢？答案是使用位运算。对于这道题，可使用异或运算 ⊕。异或运算有以下三个性质。  
任何数和 0 做异或运算，结果仍然是原来的数，即 a⊕0=a。   
任何数和其自身做异或运算，结果是 0，即 a⊕a=0。   
异或运算满足交换律和结合律，即 a⊕b⊕a = b⊕a⊕a = b⊕(a⊕a) = b⊕0=b。  
 因此，数组中的全部元素的异或运算结果即为数组中只出现一次的数字。  
```C++
int singleNumber1(vector<int>& nums) {
        int result =0;
        for(int i=0;i<nums.size();++i)
            result ^= nums[i];
        return result;
}
```

### L169. 多数元素
**题目**：给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。  
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

**思路1**：采用哈希表（简单粗暴）
```C++
int majorityElement(vector<int>& nums) {
std::unordered_map<int,int> d;
for(int i=0;i<nums.size();++i){
    if(d.find(nums[i])==d.end())
	d.insert({nums[i],1});
    else
	d[nums[i]]++;
}
for(auto [num,count]:d){
    if(count>std::floor(nums.size()/2))
	return num;
}
return 0;
}
```
**思路2**：先排序，排序后数组的中间值肯定是众数。

**思路3**：分治算法。
如果数 a 是数组 nums 的众数，如果我们将 nums 分成两部分，那么 a 必定是至少一部分的众数。  
我们可以使用反证法来证明这个结论。假设 a 既不是左半部分的众数，也不是右半部分的众数，那么 a 出现的次数少于 l / 2 + r / 2 次，
其中 l 和 r 分别是左半部分和右半部分的长度。由于 l / 2 + r / 2 <= (l + r) / 2，说明 a 也不是数组 nums 的众数，因此出现了矛盾。所以这个结论是正确的。  
这样以来，我们就可以使用分治法解决这个问题：将数组分成左右两部分，分别求出左半部分的众数 a1 以及右半部分的众数 a2，随后在 a1 和 a2 中选出正确的众数。  

**思路4**：Boyer-Moore 投票算法
Boyer-Moore 算法的本质和方法四中的分治十分类似。我们首先给出 Boyer-Moore 算法的详细步骤：  
我们维护一个候选众数 candidate 和它出现的次数 count。初始时 candidate 可以为任意值，count 为 0；  
我们遍历数组 nums 中的所有元素，对于每个元素 x，在判断 x 之前，如果 count 的值为 0，我们先将 x 的值赋予 candidate，随后我们判断 x：  
如果 x 与 candidate 相等，那么计数器 count 的值增加 1；  
如果 x 与 candidate 不等，那么计数器 count 的值减少 1。  
在遍历完成后，candidate 即为整个数组的众数。
```
int majorityElement(vector<int>& nums) {
int candidate = -1;
int count = 0;
for (int num : nums) {
    if (num == candidate)
	++count;
    else if (--count < 0) {
	candidate = num;
	count = 1;
    }
}
return candidate;
}
```



### L1. 两数之和
**题目**：给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那 两个 整数，
并返回它们的数组下标。 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。  

**思路1**：遍历。  
```C++
vector<int> twoSum(vector<int>& nums, int target) {
    for(int i=0;i<nums.size();++i)
        for(int j=i+1;j<nums.size();++j)
            if(nums[i]+nums[j]==target)
                return vector<int>{i,j};
    return vector<int>{0,1};
}
```
**思路2**:哈希表。记录遍历过的值到哈希表。
```C++
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> d;
    for(int i=0;i<nums.size();++i){
        if(d.find(target-nums[i])!=d.end())
            return vector<int>{i,d[target-nums[i]]};
        if(d.find(nums[i])==d.end())
            d.insert({nums[i],i});
    }
    return vector<int>{0,1};
}
```

### L15. 三数之和
**题目**：给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
请你找出所有和为 0 且不重复的三元组。  
注意：答案中不可以包含重复的三元组。  

**思路1**:遍历法，双重循环，外层单指针，内双指针。时间复杂度O(n^2)  
```C++
int Partition(vector<int> &arr,int low,int high){
    int key=arr[low];
    while(low<high){
        while(low<high && arr[high]>=key)
            high--;
        arr[low]=arr[high];
        while(low<high && arr[low]<=key)
            low++;
        arr[high]=arr[low];
    }
    arr[low]=key;
    return low;
}
void QSort(vector<int> &arr,int low,int high){
    if(low < high){
        int parting = Partition(arr,low,high);
        QSort(arr,low,parting-1);
        QSort(arr,parting+1,high);
    }
}

vector<vector<int>> threeSum(vector<int>& nums) {
    const int n = nums.size();
    vector<vector<int>> output;
    //先排序
    QSort(nums,0,nums.size()-1);
    //外层单指针，内层双指针
    for (int first = 0; first < n; ++first) {
        if (first > 0 && nums[first] == nums[first - 1])  // 需要和上一次枚举的数不相同
            continue;
        int third = n - 1;// c 对应的指针初始指向数组的最右端
        int target = -nums[first];
        for (int second = first + 1; second < n; ++second) {
            if (second > first + 1 && nums[second] == nums[second - 1]) // 需要和上一次枚举的数不相同
                continue;
            while (second < third && nums[second] + nums[third] > target)  // 需要保证 b 的指针在 c 的指针的左侧
                --third;
            if (second == third)
                break;
            if (nums[second] + nums[third] == target)
                output.push_back({nums[first], nums[second], nums[third]});
        }
    }
    return output;
}
```


### L16. 最接近的三数之和
**题目**：给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，
使它们的和与 target 最接近。 返回这三个数的和。  
假定每组输入只存在恰好一个解。

**思路1**: 直接暴力解法的时间复杂度时O(n^3)。同上一题一样，内层循环可以用双指针降低复杂度。  
为了使用双指针，需要首先对数组进行排序，复杂度为O(nlogn)。与上一题不同的是，不需要考虑重复的3元组。
```C++
int threeSumClosest(vector<int>& nums, int target) {
    std::sort(nums.begin(),nums.end());
    int closest_sum=0;
    int delta = INT_MAX;
    for(int i=0;i<nums.size();++i){
        int j=i+1,k=nums.size()-1;
        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            if(std::abs(target-sum)<delta){
                delta = std::abs(target-sum);
                closest_sum = sum;
                if(delta==0)break;
            }
            if(sum<=target)
                j++;
            else if(sum>target)
                k--;
        }
    }
    return closest_sum;
}
```


### L18. 四数之和
**题目**：
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] 
（若两个四元组元素一一对应，则认为两个四元组重复）：  
* 0 <= a, b, c, d < n
* a、b、c 和 d 互不相同
* nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

**思路1**: 与L16差不多，外层是两个暴力双循环，内层是一个双指针。为了去掉重复的4元组，这里通过
集合set来保存结果。注意，本题还要考虑数据范围的问题。

```C++
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> arr;
    if(nums.size()<4)
        return arr;
    std::set<vector<int>> num_set;
    //排序
    std::sort(nums.begin(),nums.end());
    //内外层双指针
    int n = nums.size();
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            int k=j+1,l= n-1;
            while(k<l){
                int64_t sum = static_cast<int64_t>(nums[i])+static_cast<int64_t>(nums[j])+
                        static_cast<int64_t>(nums[k])+static_cast<int64_t>(nums[l]);
                if(sum==target){
                    num_set.insert({nums[i],nums[j],nums[k],nums[l]});
                    k++;
                }
                else if(sum>target) l--;
                else k++;
            }
        }
    }

    for(auto &v : num_set)
        arr.push_back(v);
    return arr;
}

```



### L75. 颜色分类
**题目**:
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。  
**思路1：**: 最简单粗暴的方法是，直接使用排序算法，进行升序排列。
```C++
//快速排序
void QSort(vector<int> &nums,int low,int high){
    static auto partition = [](vector<int> &arr,int left,int right){
        int key = arr[left];
        while(left<right){
            while(left < right && arr[right]>=key) right--;
            arr[left]=arr[right];
            while(left<right && arr[left]<=key) left++;
            arr[right] = arr[left];
        }
        arr[left] = key;
        return left;
    };
    if(low>=high) return;
    int mid = partition(nums,low,high);
    QSort(nums,low,mid-1);
    QSort(nums,mid+1,high);
}


void sortColors(vector<int>& nums) {
    QSort(nums,0,nums.size()-1);
}
```

**思路2**：这是一个荷兰国旗问题。单指针，遍历两次，第一次遍历将0 交换到数组的前部，第二次遍历将1 交换到0后数组的中间区域。
```C++
void sortColors(vector<int>& nums) {
    int k=0;
    for(int i=0;i<nums.size();++i){
        if( nums[i]==0){
            std::swap(nums[i],nums[k]);
            k++;
        }
    }
    for(int i=k;i<nums.size();++i){
        if( nums[i]==1){
            std::swap(nums[i],nums[k]);
            k++;
        }
    }
}
```

**思路3**：采用双指针，一个从前往后，一个从后往前同时遍历。
```C++
void sortColors(vector<int>& nums) {
    int k = nums.size()-1;
    int j=0;
    for(int i=0;i<=k;++i){
        while(i<=k && nums[i]==2){
            std::swap(nums[i],nums[k]);
            k--;
        }
        if(nums[i]==0){
            std::swap(nums[i],nums[j]);
            j++;
        }
    }
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




### L112. 路径总和

**题目**：给定一个二叉树，检查它是否是镜像对称的。给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，
这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。  
叶子节点 是指没有子节点的节点。

**思路1**：迭代  
使用 深度优先搜索 或 广度优先搜索。在queue或stack中，同时保存到当前节点的路径和。如stack<tuple<TreeNode*,int>>
```C++
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
```

**思路2**：递归  
假定从根节点到当前节点的值之和为 val，我们可以将这个大问题转化为一个小问题：是否存在从当前节点的子节点到叶子的路径，满足其路径和为 sum - val。
不难发现这满足递归的性质，若当前节点就是叶子节点，那么我们直接判断 sum 是否等于 val 即可（因为路径和已经确定，就是当前节点的值，我们只需要判断该路
 径和是否满足条件）。若当前节点不是叶子节点，我们只需要递归地询问它的子节点是否能满足条件即可。   
```C++
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
```




### L701. 二叉搜索树中的插入操作

**题目**：给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。  
注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。  

**思路1**：递归  



**思路2**: 迭代  
将val与每个节点的val进行比较，若val<node->val，则进入左节点，否则进入右节点。  当节点为空时，插入新的节点。
```C++
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //迭代法
        TreeNode* node = new TreeNode(val);
        if(!root){
            root = node;
            return root;
        }

        auto p = root;
        while(p){
            if(val < p->val){
                if(!p->left){
                    p->left = node;
                    break;
                }
                p = p->left;
            }
            if(val > p->val){
                if(!p->right){
                    p->right = node;
                    break;
                }
                p = p->right;
            }
        }
        return root;
    }
```



### L98. 验证二叉搜索树

**题目**：给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。  
有效二叉搜索树定义如下：  
节点的左子树只包含 小于 当前节点的数。  
节点的右子树只包含 大于 当前节点的数。  
所有左子树和右子树自身必须也是二叉搜索树。  
	
**思路1**：根据二叉搜索树的定义可知，其中序遍历是一个升序，因此可以通过比较当前节点和上一节点的值来判断是否时二叉搜索树。
```C++
bool isValidBST(TreeNode* root) {
    //采用中序遍历
    stack<TreeNode*> stk;
    auto p = root;
    TreeNode* prev=nullptr;
    while(p || !stk.empty()){
        while(p){
            stk.push(p);
            p=p->left;
        }
        if(!stk.empty()){
            p = stk.top();
            stk.pop();
            if(prev && prev->val >= p->val ){
                return false;
            }
            prev = p;
            p = p->right;
        }
    }
    return true;
}
```
	
**思路2**：用递归法，对于每次递归传入当前节点的范围，若不满足范围则不是二叉搜索树。


	
### L653. 两数之和 IV - 输入 BST

**题目**： 给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。  

**思路1**:采用中序遍历，将BST转换为升序数组。然后双指针遍历数组，判断是否存在两个值=k。
```C++
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
```
	
**思路2**:遍历二叉树，将最简单的方法就是遍历整棵树，找出所有可能的组合，判断是否存在和为 k 的一对节点。现在在此基础上做一些改进。
如果存在两个元素之和为 k，即 x+y=k，并且已知 x 是树上一个节点的值，则只需判断树上是否存在一个值为 y 的节点，使得 y=k-x。  
 基于这种思想，在树的每个节点上遍历它的两棵子树（左子树和右子树），寻找另外一个匹配的数。在遍历过程中，将每个节点的值都放到一个 set 中。
对于每个值为 p 的节点，在 set中检查是否存在 k-p。如果存在，那么可以在该树上找到两个节点的和为 k；否则，将 p 放入到 set 中。
如果遍历完整棵树都没有找到一对节点和为 k，那么该树上不存在两个和为 k 的节点。  
	
	
	
### L235. 二叉搜索树的最近公共祖先

**题目**： 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。  
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”  
例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

**思路1**:根据BST的性质，当(node->val >= p->val && node->val <= q->val) || (node->val <= p->val && node->val >= q->val)时，node是最近公共祖先。
```C++
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    auto node = root;
    while(node){
        if((node->val >= p->val && node->val <= q->val) ||
           (node->val <= p->val && node->val >= q->val)
                ){
            return node;
        }
        else if(p->val < node->val && q->val < node->val){
            node = node->left;
        }
        else{
            node = node->right;
        }
    }
    return node;
}
```
	
	
	
	
	
	

