Solution 1-:
Steps-:
1)Make prev at head and curr at head->next
2)Two cases-:
  1. if(curr->data==prev->data) prev is linked with curr->next 
  2. if(curr->data!=prev->data) prev is shifted to curr become we consider this node.

Code-:
ListNode* deleteDuplicates(ListNode* head)
{
        if(head==NULL || head->next==NULL) return head;

        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr!=NULL)
        {
            if(prev->val==curr->val)
            prev->next=curr->next;
            
            else
            prev=curr;
            
            curr=curr->next;
        }
        return head;
}