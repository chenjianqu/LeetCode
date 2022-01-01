#include <iostream>


/*
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 */


/**
 * Definition for singly-linked list.

 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    ListNode* p1 = list1;
    ListNode* p2 = list2;
    ListNode* pm;

    if(p1==nullptr)
        return p2;
    else if(p2==nullptr)
        return p1;

    if(p1->val <= p2->val){
        pm=p1;
        p1 = p1->next;
    }
    else{
        pm=p2;
        p2=p2->next;
    }
    ListNode *h = pm;

    while(true){
        if(p1 == nullptr){
            pm->next = p2;
            break;
        }
        else if(p2==nullptr){
            pm->next = p1;
            break;
        }

        if(p1->val <= p2->val){
            ListNode* tmp = p1;
            p1 = p1->next;
            tmp->next = pm->next;
            pm->next = tmp;
        }
        else{
            ListNode* tmp = p2;
            p2 = p2->next;
            tmp->next = pm->next;
            pm->next = tmp;
        }
        pm = pm->next;

    }

    return h;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
