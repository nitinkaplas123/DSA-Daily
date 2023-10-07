Solution 1-:
Steps-:
1)using stack 
2)store all nodes value in stack
3)Now curr=head and compare with st.top() with curr

Code-: Time->O(N) Space ->O(N)
bool isPalindrome(ListNode* head) 
{
        stack<int>st;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            st.push(curr->val);
            curr=curr->next;
        }

        curr=head;
        while(curr!=NULL)
        {
            if(st.top()!=curr->val)
            return false;
            else
            st.pop();

            curr=curr->next;
        }
        return true;
}


Solution 2-:
Steps-:
1)Here first we find the middle of the linked list and make pointer to prev of middle.
2)Now reverse the nodes from middle to end of linked list.
3)Now connect prev->next=rev;
4)Now make two pointer 1st at head and 2nd at middle point 
5)return false if both values are not matching else return true;


Code-: Time->O(n)  Space->O(1)
ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            ListNode* save=curr->next;
            curr->next=prev;
            prev=curr;
            curr=save;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        // middle node
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast!=NULL and fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL and fast->next==NULL)
        {
          prev=slow;
          slow=slow->next;
        }

        ListNode* rev=reverse(slow);
        prev->next=rev;


        ListNode *low=head;
        ListNode* high=rev;
        while(high!=NULL)
        {
            if(low->val!=high->val) return false;

            low=low->next;
            high=high->next;
        }
        return true;
    }