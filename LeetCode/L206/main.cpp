#include <iostream>

/*
 * **题目**：给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

**思路**：假设链表为 1→2→3→∅，我们想要把它改成 ∅←1←2←3。 在遍历链表时，将当前节点的 next 指针改为
指向前一个节点。由于节点没有引用其前一个节点，因此必须事先存储其前一个节点。在更改引用之前，还需要存储后一个节点。最后
返回新的头引用。
 *
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverseList(ListNode* head) {
    if(!head)
        return head;
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


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
