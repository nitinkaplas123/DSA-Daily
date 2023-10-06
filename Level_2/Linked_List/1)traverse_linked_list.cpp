Solution 1-:
Iterative Solution-:

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

void printall(Node* head)
{
    Node* curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

int main()
{
    Node* head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    printall(head);
    return 0;
}


Solution 2 -:

Recursive solution-:

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

void printall(Node* head)
{
    if(head==NULL)
    return ;
    cout<<head->data<<" ";
    printall(head->next);
}

int main()
{
    Node* head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    printall(head);
    return 0;
}