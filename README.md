# LeetCode
这是我的解算法题的代码和笔记。

[字符串和数组](https://github.com/chenjianqu/LeetCode/blob/master/%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%92%8C%E6%95%B0%E7%BB%84.md)

[二叉树](https://github.com/chenjianqu/LeetCode/blob/master/%E4%BA%8C%E5%8F%89%E6%A0%91.md)

[回溯](https://github.com/chenjianqu/LeetCode/blob/master/%E5%9B%9E%E6%BA%AF.md)

[贪心](https://github.com/chenjianqu/LeetCode/blob/master/%E8%B4%AA%E5%BF%83.md)

<<<<<<< HEAD
## 数组




### L2022. 将一维数组转变成二维数组
=======
[动态规划](https://github.com/chenjianqu/LeetCode/blob/master/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92.md)
>>>>>>> 104197c0729f4b1129b2f296ad78686234f80e96


**哈希表**
**链表**
**查找**


## 哈希表

### L705. 设计哈希集合
**题目**：不使用任何内建的哈希表库设计一个哈希集合（HashSet）。  
实现 MyHashSet 类：
void add(key) 向哈希集合中插入值 key 。  
bool contains(key) 返回哈希集合中是否存在这个值 key 。  
void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。  

**思路1**：使用数组作为容器，一开始就设置数组的容量。使用除留余数法作为哈希函数。使用链地址法解决哈希冲突。即
数组的每个元素是一个list，这样增删比较方便。

```C++
class MyHashSet {
public:
    MyHashSet() {
        data.resize(kSize);
    }
    int hash(int key){
        return key%kSize;
    }
    void add(int key) {
        int index = hash(key);
        for(auto it=data[index].begin();it!=data[index].end();++it)
            if(*it == key)
                return;
        data[index].push_back(key);
    }
    void remove(int key) {
        int index = hash(key);
        for(auto it=data[index].begin();it!=data[index].end();++it){
            if(*it == key){
                data[index].erase(it);
                return;
            }
        }
    }
    bool contains(int key) {
        int index = hash(key);
        for(auto p: data[index]) if(p==key) return true;
        return false;
    }
private:
    vector<list<int>> data;
    static constexpr int kSize=1000;
};
```

**思路2**：使用一个**数组**来表示哈希集。数组中的每个元素都是一个桶。在每个桶中，我们使用 vector来存储所有值。

```C++
#define MAX_LEN 100000          // the amount of buckets
class MyHashSet {
private:
    vector<int> set[MAX_LEN];   // hash set implemented by array
    /** Returns the corresponding bucket index. */
    int getIndex(int key) {
        return key % MAX_LEN;
    }
    /** Search the key in a specific bucket. Returns -1 if the key does not existed. */
    int getPos(int key, int index) {
        // Each bucket contains a list. Iterate all the elements in the bucket to find the target key.
        for (int i = 0; i < set[index].size(); ++i) 
            if (set[index][i] == key) 
                return i;
        return -1;
    }
public:
    MyHashSet() {
    }
    
    void add(int key) {
        int index = getIndex(key);
        int pos = getPos(key, index);
        if (pos < 0) set[index].push_back(key);
    }
    
    void remove(int key) {
        int index = getIndex(key);
        int pos = getPos(key, index);
        if (pos >= 0) set[index].erase(set[index].begin() + pos);
    }
    /** Returns true if this set did not already contain the specified element */
    bool contains(int key) {
        int index = getIndex(key);
        int pos = getPos(key, index);
        return pos >= 0;
    }
};
```





### L706. 设计哈希映射

**题目**：不使用任何内建的哈希表库设计一个哈希映射（HashMap）。  
实现 MyHashMap 类：  
MyHashMap() 用空映射初始化对象  
void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。  
int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。  
void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。  

**思路1**：使用数组作为容器，一开始就设置数组的容量。使用除留余数法作为哈希函数。使用链地址法解决哈希冲突。即
数组的每个元素是一个list，这样增删比较方便。
```C++
class MyHashMap {
public:
    MyHashMap() {
        data.resize(kSize);
    }
    int hash(int key){
        return key%kSize;
    }
    void put(int key, int value) {
        int index = hash(key);
        for(auto it=data[index].begin();it!=data[index].end();++it){
            if(it->first==key){
                it->second = value;
                return;
            }
        }
        data[index].push_back({key,value});
    }
    
    int get(int key) {
        int index = hash(key);
        for(auto it=data[index].begin();it!=data[index].end();++it){
            if(it->first==key){
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        for(auto it=data[index].begin();it!=data[index].end();++it){
            if(it->first==key){
                data[index].erase(it);
                return;
            }
        }
    }
private:
    vector<list<pair<int,int>>> data;
    static constexpr int kSize=1000;
};
```

**思路2**：使用一个**数组**来表示哈希集。数组中的每个元素都是一个桶。在每个桶中，我们使用 vector来存储所有值。

```C++
#define MAX_LEN 100000            // the amount of buckets

class MyHashMap {
private:
    vector<pair<int, int>> map[MAX_LEN];       // hash map implemented by array
    /** Returns the corresponding bucket index. */
    int getIndex(int key) {
        return key % MAX_LEN;
    }
    /** Search the key in a specific bucket. Returns -1 if the key does not existed. */
    int getPos(int key, int index) {
        for (int i = 0; i < map[index].size(); ++i) 
            if (map[index][i].first == key) 
                return i;
        return -1;
    }
public:
    /** Initialize your data structure here. */
    MyHashMap() {
    }
    /** value will always be positive. */
    void put(int key, int value) {
        int index = getIndex(key);
        int pos = getPos(key, index);
        if (pos < 0) {
            map[index].push_back(make_pair(key, value));
        } else {
            map[index][pos].second = value;
        }
    }
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = getIndex(key);
        int pos = getPos(key, index);
        if (pos < 0) 
            return -1;
         else 
            return map[index][pos].second;
    }
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = getIndex(key);
        int pos = getPos(key, index);
        if (pos >= 0) 
            map[index].erase(map[index].begin() + pos);
    }
};
```









### L202. 快乐数

**题目**：难度简单769收藏分享切换为英文接收动态反馈

编写一个算法来判断一个数 `n` 是不是快乐数。

「快乐数」定义为：

- 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
- 然后重复这个过程直到这个数变为 1，也可能是 **无限循环** 但始终变不到 1。
- 如果 **可以变为** 1，那么这个数就是快乐数。

如果 `n` 是快乐数就返回 `true` ；不是，则返回 `false` 。

```
输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

**思路1**：通过哈希集合std::unordered_set记录每次迭代中中平方和num，若发现哈希集合中已经存在了该值，则返回false。

```C++
bool isHappy(int n) {
    if(n==1)
        return true;
    else if(n==0)
        return false;
    int num=0;
    std::unordered_set<int> hash_set;
    while(true){
        while(n>0){//split
            num += std::pow(n%10,2);
            n/=10;
        }
        if(num==1)
            return true;
        if(hash_set.count(num)>0)
            return false;
        hash_set.insert(num);
        n=num;
        num=0;
    }
    return false;
}
```

**思路2**：使用快慢指针法。通过反复调用 getNext(n) 得到的链是一个隐式的链表。隐式意味着我们没有实际的链表节点和指针，但数据仍然形成链表结构。起始数字是链表的头 “节点”，链中的所有其他数字都是节点。next 指针是通过调用 getNext(n) 函数获得。

意识到我们实际有个链表，那么这个问题就可以转换为检测一个链表是否有环。因此我们在这里可以使用弗洛伊德循环查找算法。这个算法是两个奔跑选手，一个跑的快，一个跑得慢。在龟兔赛跑的寓言中，跑的慢的称为 “乌龟”，跑得快的称为 “兔子”。

不管乌龟和兔子在循环中从哪里开始，它们最终都会相遇。这是因为兔子每走一步就向乌龟靠近一个节点（在它们的移动方向上）。

我们不是只跟踪链表中的一个值，而是跟踪两个值，称为快跑者和慢跑者。在算法的每一步中，慢速在链表中前进 1 个节点，快跑者前进 2 个节点（对 getNext(n) 函数的嵌套调用）。

如果 n 是一个快乐数，即没有循环，那么快跑者最终会比慢跑者先到达数字 1。

如果 n 不是一个快乐的数字，那么最终快跑者和慢跑者将在同一个数字上相遇。





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










## 二分查找

### L35. 搜索插入位置

**题目**：给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。

**思路**：二分查找。

```C++
int searchInsert(vector<int>& nums, int target) {
    int low=0,high =nums.size()-1;
    if(target<=nums[low]) return 0;
    else if(target>nums[high]) return nums.size();
    
    while(low<high){
        int mid = (low+high)/2;
        if(nums[mid] == target) return mid;
        else if(target>nums[mid]) low = mid+1;
        else high = mid-1;
    }
    if(nums[low]>target) return low;
    else if(nums[low]<target) return low+1;
    return low;
}
```












