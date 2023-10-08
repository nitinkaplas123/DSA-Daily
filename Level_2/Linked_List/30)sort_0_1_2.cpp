Solution 1-:
Steps-:
1)Make a 3 size array where we store the count of 0,1,2
2)Now travere the for loop for count[0] and make 0 in it.
3)Now travere the for loop for count[1] and make 1 in it.
4)Now travere the for loop for count[2] and make 2 in it.

Code-: Time->O(n)
Node* segregate(Node *head) {
        int count[3]={0,0,0};
        
        
        Node* curr=head;
        while(curr!=NULL)
        {
            count[curr->data]++;
            curr=curr->next;
        }
      
        curr=head;
        for(int i=0;i<count[0];i++)
        {
            curr->data=0;
            curr=curr->next;
        }
        for(int i=0;i<count[1];i++)
        {
            curr->data=1;
            curr=curr->next;
        }
        for(int i=0;i<count[2];i++)
        {
            curr->data=2;
            curr=curr->next;
        }
        return head;
    }





Solution 2-:
Steps-:
1)Make three dummy nodes for 0 ,1 ,2
2)Now linked separate 0 , 1, 2
3)At last we linked 0 1 2
4)At last there is possiblilty that-:
  1)zero element is not there
  2)ones element is not there
  3)twos element is not there

eg. [2,2,1,1] 
Case 1
-1       ->zeros
-1->1->1 ->ones
-1->2->2 ->twos

no zeros
zeros->next=ones_head->next
one->next=twos_head->next


Case2 -: No ones are there
eg [0,2,2,0,0]

-1->0->0->0
-1->
-1->2->2

no ones
if(ones_head->next)
zero->next=ones_head->next
else
zero->next=twos_head->next

Simple words -> if there is no ones then zero is linked with twos_head->next


Note all possibilty passed  but just take care with ones_head->next==NULL)
There is conditional statement


Code-:
Node* segregate(Node *head) {
        
        Node* ones_head=new Node(-1);
        Node* zeros_head=new Node(-1);
        Node* twos_head=new Node(-1);
        
        Node* one=ones_head;
        Node* zero=zeros_head;
        Node* two=twos_head;
        
        Node* curr=head;
        while(curr!=NULL)
        {
            int val=curr->data;
            if(val==0)
            {
              zero->next=curr;
              zero=curr;
            }
            else if(val==1)
            {
             one->next=curr;
             one=curr;
            }
            else
            {
              two->next=curr;
              two=curr;
            }
            curr=curr->next;
        }
        // when we no ones element when it have 
        zero->next=(ones_head->next)?ones_head->next:twos_head->next;
       
        one->next=twos_head->next;
        two->next=NULL;
        
        return zeros_head->next;
    }



