Solution 1-:
Steps-:
1)Usind dummy node as -1.

Code-:
 ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy=new ListNode(-1);
        ListNode* prev=dummy;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            if(curr->val!=val)
            {
                prev->next=curr;
                prev=curr;
            }
            curr=curr->next;
        }
        prev->next=NULL;
        return dummy->next;
    }



Solution 2-:
Steps-:
1)Using recursion


Code-:
ListNode* removeElements(ListNode* head, int val) {
       if(head==NULL) return NULL;
       head->next=removeElements(head->next,val);
       return (head->val==val)?head->next:head;
    }