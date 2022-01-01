#include <iostream>
#include <map>

using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if(head==NULL){
        return head;
    }
    auto new_head = new Node(head->val);

    std::map<Node*,Node*> addr;
    addr.insert({head,new_head});

    auto new_p = new_head;
    auto p = head;

    p=p->next;
    while(p!=NULL){
        auto new_node = new Node(p->val);
        addr.insert({p,new_node});
        new_p->next = new_node;
        new_p = new_p->next;
        p = p->next;
    }
    new_p->next=NULL;
    new_p = new_head;
    p = head;
    while(p!=NULL){
        if(p->random==NULL){
            new_p->random = NULL;
        }
        else{
            new_p->random = addr[p->random];
        }

        p = p->next;
        new_p = new_p->next;
    }

    return new_head;
}

int main() {
    std::cout << "Hello, World!" << std::endl;


    Node* head = new Node(7);
    Node* p1 = new Node(13);
    head->next=p1;
    Node* p2 = new Node(11);
    p1->next=p2;
    Node* p3 = new Node(10);
    p2->next=p3;
    Node* p4 = new Node(1);
    p3->next=p4;

    head->random=NULL;
    p1->random = head;
    p2->random = p4;
    p3->random = p2;
    p3->random=head;


    auto p=head;
    while(p){
        cout<<p->val<<" ";
        if(p->random!=NULL)
            cout<<p->random->val;
        else
            cout<<"NULL";
        cout<<endl;
        p = p->next;
    }
    cout<<endl;

    auto rp = copyRandomList(head);

    while(rp){
        cout<<rp->val<<" ";
        if(rp->random!=NULL)
            cout<<rp->random->val;
        else
            cout<<"NULL";
        cout<<endl;
        rp = rp->next;
    }


    return 0;
}
