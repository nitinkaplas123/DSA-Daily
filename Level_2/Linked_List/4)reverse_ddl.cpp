Solution 1-:
Using iterative method-:

Steps-:
1)Here just swap the arrow bw prev and next
2)prev become next and next become prev.

Code-:
Node* reverseDLL(Node * head)
{
    Node* prev=NULL;
    Node* curr=head;
    while(curr!=NULL)
    {
        Node* save=curr->next;
        curr->next=prev;
        curr->prev=save;
        prev=curr;
        curr=save;
    }
    return prev;
}

Solution 2-:
Recursive Solution
same approach

Code-:
Node* helper(Node* prev,Node* curr)
{
    if(curr==NULL) return prev;
    Node* save=curr->next;
    curr->next=prev;
    curr->prev=save;
    return helper(curr,save);
}
Node* reverseDLL(Node * head)
{
    Node* prev=NULL;
    Node* curr=head;
    return helper(prev,curr);
}


