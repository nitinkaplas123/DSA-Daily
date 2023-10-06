#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
    Node(int x)
    {
        data=x;
        prev=NULL;
        next=NULL;
    }
};

void printall(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* insert(Node* head,int val)
{
    Node* temp=new Node(val);
    temp->next=head;
    head->prev=temp;
    return temp;
}

int main()
{
  Node* head=new Node(10);
  Node* temp1=new Node(20);
  Node* temp2=new Node(30);
  head->next=temp1;
  temp1->prev=head;
  temp1->next=temp2;
  temp2->prev=temp1;
  Node* new_head=insert(head,5);
  printall(new_head);
  return 0;
}