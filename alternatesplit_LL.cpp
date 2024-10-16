
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

vector<Node*> alternateSplitListvalue(Node* head){
    vector<Node*> ans;
    Node* first = head;
    while(first != NULL && first->next !=NULL){
        ans.push_back(first);
        first = first->next->next;
    }
    // check is first is not null 
    if (first != NULL){
        ans.push_back(first);
    }

    // now from second
    first = head->next;
    while(first != NULL && first -> next != NULL){
        ans.push_back(first);
        first = first->next->next;
    }
    if (first != NULL){
        ans.push_back(first);
    }

    return ans;
}


vector<Node*> alternateSplitList(Node* head){
    if (head->next  == NULL){
        return {head,NULL};
    }

    // make two head
    Node* head2 = head->next;
    // make two pointers 
    Node* temp1 = head;
    Node* temp2 =  head->next;
    while(temp1 != NULL && temp2 != NULL){
        temp1->next = temp2->next;
        // shift temp1
        temp1 = temp1->next;
        if (temp1 == NULL){
            break;
        }
        temp2->next = temp1->next;
        temp2 = temp2->next;
    }

    vector<Node*> ans  = {head,head2};

    return ans;
}


int main(){
    Node* head = new Node(2);
    Node* tail = head;
    insertatTail(tail,5);
    // insertatTail(tail,8);
    // insertatTail(tail,9);
    // insertatTail(tail,6);
    // insertatTail(tail,8);
    print(head);
    vector<Node*> ans = alternateSplitList(head);
    print(ans[0]);
    print(ans[1]);


}