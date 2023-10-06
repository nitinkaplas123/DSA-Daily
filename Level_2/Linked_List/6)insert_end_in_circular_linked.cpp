Solution 1-:
Steps-:
1)do it as we do insert_begin in sol 1 approach

Time->O(N)



Solution 2-:
Steps-:
eg. [10,20,30] add 40 at end
1)first we add 40 at begining as we do it previos
  [40,10,20,30]
2)now we return head->next 10 which makes [10,20,30,40] 

Code-: Time->O(1)
Node* insert(Node* head,int val)
{
   Node* temp=new Node(val);
   if(head==NULL)
   {
       temp->next=temp;
       return temp;
   }
   Node* curr=head;
   Node* save=curr->next;
   curr->next=temp;
   temp->next=save;
   swap(head->data,head->next->data);
   return head->next;
}