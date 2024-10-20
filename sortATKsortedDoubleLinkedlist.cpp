#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<queue>
using namespace std;


class DLLNode{
    public:
    int data;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};


void insertHead(DLLNode* &head,DLLNode* &tail,int data){
    DLLNode* temp = new DLLNode(data);
    if (head == NULL){
        head = temp;
        tail = temp;
        return;
    }   

    // now connect it 
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void print(DLLNode* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head ->next;
    }
    cout<<endl;
}



DLLNode* sortAKSortedDLL(DLLNode *head,int k){
    if (head ->next == NULL){
        return head;
    }
    // now 
    priority_queue<int,vector<int>,greater<int>> pq;

    // now we have prority queue for k element to get lowest element priority 
    // now add the first k+1 element in to the priority queue
    DLLNode* right = head;
    DLLNode* left = head;
    int i =0;
    while(right != NULL && i<=k){
        pq.push(right->data);
        right = right->next;
        i++;
    }

    // now left is at start position and right is at right position also
    while(left != NULL){
        // push the data into correct position 
        left->data = pq.top();
        pq.pop();
        // check that right is not before to null. so that we have to no push more in to the pq;
        if (right != NULL){
            pq.push(right->data);
            right = right->next;
        }

        left= left->next;
    }
    return head;
}
int main(){
    DLLNode* head = NULL;
    DLLNode* tail = NULL;

    insertHead(head,tail,3);
    insertHead(head,tail,2);
    insertHead(head,tail,1);
    insertHead(head,tail,5);
    insertHead(head,tail,6);
    insertHead(head,tail,4);
    print(head);
    cout<<"after sorting this k-doubly linked list "<<endl;
    int k = 3;
    head = sortAKSortedDLL(head,k);
    print(head);
}