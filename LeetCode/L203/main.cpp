#include <iostream>

/*
 * 题目：给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 */

 struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };


 /*
  * 我想到的解法
  */
 ListNode* removeElements1(ListNode* head, int val) {
     auto prev = head;
     while(prev){
         if(prev->val != val){
             break;
         }
         else{
             auto tmp = prev;
             prev = prev->next;
             //free(tmp);
         }
     }
     if(!prev)
         return prev;
     ListNode *new_head= prev;
     ListNode * p = prev->next;

     while(p){
         if(p->val == val){
             prev->next = p->next;
             delete p;
             p = prev->next;
         }
         else{
             prev = prev->next;
             p = prev->next;
         }
     }
     return new_head;
 }

/**
 * 官方解法
 * @return
 */
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



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
