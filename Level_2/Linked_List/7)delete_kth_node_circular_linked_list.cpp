Solution 1-:
Steps-:
1)There are two cases-:
  1)when k==1
  2)when k>1


Code-: Time->O(N)
Node* deleted(Node* head,int k)
{
    if(k==1)
    {
       Node* temp=head->next;
       head->data=temp->data;
       head->next=temp->next;
       delete(temp);
       return head;
    }
    else
    {
        Node* curr=head;
        Node* prev=NULL;
        for(int i=0;i<k-1;i++)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        delete(curr);
        return head;
    }
}