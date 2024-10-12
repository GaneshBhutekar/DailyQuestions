
// sort using map
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this-> data=data;
        this-> next=NULL;

    }
    ~Node(){
        cout<<"deleting something ..."<<endl;
    }
};
void insertatHead(Node * &head,int data){
    Node *temp = new Node(data);
    temp->next=head;
    head=temp;

}
void insertatTail(Node*&tail,int data){
    Node * temp=new Node(data);
    tail->next=temp;
    tail=temp;
}

void print(Node * head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;

}


void deleteAlt(Node* head){
    if (head->next == NULL){
        return;
    }

    Node* temp = head;
    while(temp!= NULL && temp->next != NULL){
        Node* x = temp->next;
        temp->next  = temp->next->next;
        x->next = NULL;
        delete x;
        temp = temp->next;
    }
}

int main(){
    Node* temp = new Node(10);
    Node* head = temp;
    Node* tail = temp;
    insertatTail(tail,20);
    insertatTail(tail,30);
    insertatTail(tail,40);
    insertatTail(tail,50);
    insertatTail(tail,60);
    insertatTail(tail,70);
    insertatTail(tail,80);
    insertatTail(tail,90);
    insertatTail(tail,100);

    print(head);
    cout<<"after deleting the alternate nodes"<<endl;
    deleteAlt(head);
    print(head);
}