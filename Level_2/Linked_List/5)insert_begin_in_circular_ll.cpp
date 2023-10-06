[10,20,30] in circular manner means 30->next=10

Question is we have to insert at begin of it. 
for eg. 5

o/p ->[5,10,20,30]  here 30->next=5

Solution 1-:
Steps-:
1)Make a temp node of 5
2)traverse the node till we reach end node 30 
3)Now 30->next=temp and temp->next=head

Code-: Time->O(n)
Node* insert(Node* head,int val)
{
   Node* temp=new Node(val);
   if(head==NULL)
   {
       temp->next=temp;
       return temp;
   }
   
   Node* curr=head;
   while(curr->next!=head)
   {
       curr=curr->next;
   }
   curr->next=temp;
   temp->next=head;
   return temp;
}


Solution 2-: 
Steps-:
eg. [10,20,30]
1)Just add temp node in next of head
  [10,5,20,30]
2)Now just swap the values of head with head->next


Code-: Time->O(1)
Node* insert(Node* head,int val)
{
   Node* temp=new Node(val);
   if(head==NULL)
   {
       temp->next=temp;
       return temp;
   }
   
   Node* save=head->next;
   head->next=temp;
   temp->next=save;
   swap(head->data,head->next->data);
   return head;
}



