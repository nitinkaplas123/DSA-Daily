Question link->https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1
Solution -:
Steps-:
Three Cases-:
Case 1-:  eg [10,20,30]  val=5   o/p ->[5,10,20,30]
here we have to explicity solve this case
Case 2-: eg [10,20,30] val=25 o/p ->[10,20,25,30]
here we use prev and curr variable for linking correctly
Case 3-: eg [10,20,30] val=40  o/p ->[10,20,30,40]
here we have to return head if we unable to find the element in linked list smaller than val


Code-:
Node *sortedInsert(struct Node* head, int data) {
       Node* temp=new Node(data);
       Node* curr=head;
       Node* prev=NULL;

       // case 1
       if(head->data>data)
       {
           temp->next=head;
           return temp;
       }

       //case 2
       while(curr!=NULL)
       {
           if(data<curr->data)
           {
               prev->next=temp;
               temp->next=curr;
               return head;
           }
           else
           {
               prev=curr;
               curr=curr->next;
           }
       }
       //case 3
       prev->next=temp;
       return head;
    }
