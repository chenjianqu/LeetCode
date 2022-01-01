#include <iostream>

/*
 * 题目：给定一个单链表的头结点pHead，长度为n，反转该链表后，返回新链表的表头。
 */

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
    val(x), next(NULL) {
    }
};

ListNode* ReverseList(ListNode* pHead) {
if(!pHead)
    return pHead;
auto p = pHead;
auto p_n = pHead->next;
auto p_r = pHead;

while(p_n){
    p = p_n;
    p_n = p_n->next;
    p->next = p_r;
    p_r = p;
}
pHead->next=NULL;
return p_r;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
