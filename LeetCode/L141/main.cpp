#include <iostream>
#include <vector>
#include <unordered_map>

/*
 * **题目**：给你一个链表的头节点 head ，判断链表中是否有环。
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
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/**
 * 解法：Floyd 判圈算法
 * @param head
 * @return
 */
bool hasCycle1(ListNode *head) {
    auto a = head;
    auto b = head;
    while(true){
        if(!b) return false;
        b = b->next;
        if(!b) return false;
        b = b->next;
        a = a->next;
        if(a==b){
            break;
        }
    }
    return true;
}

/**
 * 解法：哈希表
 * @param head
 * @return
 */
bool hasCycle(ListNode *head) {
    std::unordered_map<ListNode*,int> d;
    auto p = head;
    while(p){
        d.insert({p,1});
        auto next = p->next;
        if(next && d.find(next)!=d.end()){
            return true;
        }
        p=next;
    }
    return false;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
