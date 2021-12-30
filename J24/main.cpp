#include <iostream>

using namespace std;

/*定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseList(ListNode* head) {
    auto p = head;//一个指针用于原来的list
    auto rp = head;//一个指针用于表示反转的list
    auto tail = rp;
    if(head==NULL){
        return head;
    }
    auto p_next = head->next;

    while(p_next!=NULL){
        p=p_next;
        p_next=p_next->next;

        p->next = rp;
        rp = p;
    }
    tail->next =NULL;

    return rp;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    ListNode* head = new ListNode(1);
    ListNode* p1 = new ListNode(2);
    head->next=p1;
    ListNode* p2 = new ListNode(3);
    p1->next=p2;
    ListNode* p3 = new ListNode(4);
    p2->next=p3;
    ListNode* p4 = new ListNode(5);
    p3->next=p4;

    auto p=head;
    while(p){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;

    auto rp = reverseList(head);
    while(rp){
        cout<<rp->val<<endl;
        rp = rp->next;
    }

    return 0;
}
