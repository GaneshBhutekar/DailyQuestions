#include<iostream>
#include<vector>
using namespace std;



class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        prev = NULL;
        next = NULL;
        this->data = data;
    }
};


void Insert(Node* &head,Node* &tail,int data){

    Node* newdata = new Node(data);
    if (head == NULL){
        head = newdata;
        tail = newdata;
        return;
    }
    newdata->prev = tail;
    tail->next = newdata;
    tail = tail->next;
}


Node* sortedInsert(Node* &head,int x){
    Node* aage = head;
    Node* piche = NULL;
    if (head->data >= x){
        Node* newnode =  new Node(x);
        newnode->next = head;
        head = newnode;
        return head;
    }
    while(aage !=  NULL && aage->data <= x){
        piche = aage;
        aage = aage->next;
    }

    // now insert where it is 
    // create the Node first

    Node* X = new Node(x);
    if (aage == NULL){
        X->prev = piche;
        piche->next = X;
        return head;
    }
    X->prev = piche;
    X->next = aage;
    piche->next = X;
    aage->prev = X;
    return head;

}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    // Insert(head,tail,10);
    // Insert(head,tail,20);
    // Insert(head,tail,30);
    // Insert(head,tail,40);
    // Insert(head,tail,50);
    // Insert(head,tail,60);
    Insert(head,tail,5);
    // now try to insert 55 in it and then 70 in it;
    print(head);
    cout<<"after inserting two element"<<endl;
    // sortedInsert(head,55);
    // sortedInsert(head,70);
    // sortedInsert(head,25);
    sortedInsert(head,1000);
    sortedInsert(head,5);
    print(head);

}