Solution 1-:
Steps-:
1) using curr1 || curr2 || carry!=0


Code-: Time->O(N) 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* curr1=l1;
         ListNode* curr2=l2;

         int carry=0;
         ListNode* head=NULL;
         ListNode* curr=NULL;
         while(curr1!=NULL || curr2!=NULL || carry!=0)
         {
             int sum=0;
             if(curr1!=NULL)
             {
                sum+=curr1->val;
                curr1=curr1->next;
             }
             
             if(curr2!=NULL)
             {
                sum+=curr2->val;
                curr2=curr2->next;
             }

             sum+=carry;

             ListNode* temp=new ListNode(sum%10);
             carry=sum/10;
             if(head==NULL)
             {
                 head=temp;
                 curr=temp;
             }
             else
             {
                 curr->next=temp;
                 curr=temp;
             }
         }
        return head;
    }