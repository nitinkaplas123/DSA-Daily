Solution 1-:
Steps-:
1)count the node in a linked list
2)now move count-n steps from head of the list.

Code-: Time->O(N)
int helper(Node* head)
{
        int count=0;
        while(head!=NULL)
        {
            count++;
            head=head->next;
        }
        return count;
}

int getNthFromLast(Node *head, int n)
{
       int count=helper(head);
       if(n>count) return -1;
       
       Node* curr=head;
       for(int i=0;i<count-n;i++)
       {
           curr=curr->next;
       }
       return curr->data;
}

Solution 2-:
Steps-:
1)slow=head and fast at n step ahead
2)means there is n node gap bw slow and fast node
3)now move slow and fast with 1 move and if(fast==NULL) that means slow is at target position.
4)if(n>no. of nodes) then return -1

Code-:
int getNthFromLast(Node *head, int n)
{
       Node* curr=head;
       Node* slow=head;
       Node* fast=head;
       int i=0;
       while(i<n)
       {
           if(fast==NULL)
           return -1;
           fast=fast->next;
           i++;
       }
       
       while(fast!=NULL)
       {
           slow=slow->next;
           fast=fast->next;
       }
       return slow->data;
}