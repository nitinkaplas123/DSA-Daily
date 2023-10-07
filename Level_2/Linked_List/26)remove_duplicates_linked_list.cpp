Question Link-:
https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

Solution 1-:
Steps-:
1)Using hashset we store head in it.
2)Now if curr element is present in set then move 1 step 
3)If not present then prev->next=curr; prev=curr and also insert into set because now we add this node into ans


Code-:
Node * removeDuplicates( Node *head) 
{
       unordered_set<int>s;
       s.insert(head->data);
       Node* temp=head;
       Node* curr=head->next;
       while(curr!=NULL)
       {
           int val=curr->data;
           if(s.find(val)==s.end())
           {
               temp->next=curr;
               temp=curr;
               s.insert(val);
           }
           curr=curr->next;
       }
       temp->next=NULL;
       return head;
 }