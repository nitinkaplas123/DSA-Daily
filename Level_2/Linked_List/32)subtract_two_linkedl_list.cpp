Test case-:
1)when starting with 0s
l1-> 0->1->2->3
l2-> 0->1

answer-> 123-1=122

2)when no. of nodes in l2>l1
l1-> 1->2->3
l2-> 1->2->3->4

answer -> first have to swap the nodes  swap(l2,l1) 
l1-> 1->2->3->4
l2-> 1->2->3

answer-> 1234-123=1111

3.1) when count1==count2 and values are also equal
l1-> 1->2->3
l2-> 1->2->3

answer-> 123-123=>0

3.2)when count1==count2 and in value l2>l1
l1-> 1->2->2
l2-> 1->3->2

122-132 =>not possible
here we have to swap

l1-> 1->3->2
l2-> 1->2->2
answer -> 132-122=>10


3.3) when count1==count2 and l1>l2 in values its come under when l1 nodes >l2 nodes.

steps-:
1)here we have to reverse the both linked list.

2)now 3 things curr1!=NULL || curr2!=NULL || carry!=0   =>  in addition of two linked list.
  in place of these 3 conditions we just write curr1!=NULL because -:
  1.curr2!=NULL not needed because curr1 nodes >=curr2 nodes.
  2.as in addition carry make addition nodes sometime like 9+9 make 18
    but here subtraction never make additon nodes.
    carry always work with curr1 until end.

3)when we take 10+curr1->data in previous values means there carry=1
   now we have to delete the 1 from curr1->data and make carry=0.

Code-:
if(carry!=0)
{
            curr1->data-=1;
            carry=0;
}

4)When we have both curr1 and curr2.
Code-:
if(curr1!=NULL and curr2!=NULL)
{
            if(curr1->data<curr2->data)
            {
                carry=1;
                curr1->data+=10;
                
            }
            diff=curr1->data-curr2->data;
            curr1=curr1->next;
            curr2=curr2->next;
}   

4)When we have only curr1 

There is 2 cases-:

4.1) curr1->data is negative
Code-:
if(curr1->data<0)
{
    curr1->data+=10;
    diff=curr1->data;
    carry=1;
    curr1=curr1->next;
}

4.2)curr1->data is positive.
if(curr1->data>=0)
{
    diff=curr1->data;
    curr1=curr1->next;
}


5)Now we make new nodes and make connection 
Node* temp=new Node(diff);
        
if(new_head==NULL)
{
    new_head=temp;
    curr=temp;
}
else
{
    curr->next=temp;
    curr=temp;
}


6)At the end we have to remove the leading zeros.
  eg. 1->0->0  - 1->2   =>8->8

  reverse=>  0->0->1 
             2->1
     o/p  -> 8->8->0

     rev-> 0->8->8

    we need 8->8 
    so  before return the answer 
    we have to remove all the leading zeros 

while(res!=NULL and res->data==0)
res=res->next;
    
return res;       
    







Code-:
int count_nodes(Node* head)
{
    int c1=0;
    while(head!=NULL)
    {
        c1++;
        head=head->next;
    }
    return c1;
}

Node* reverse(Node* head)
{
    Node* prev=NULL;
    Node* curr=head;
    
    while(curr!=NULL)
    {
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

Node* solve(Node* curr1,Node* curr2)
{
    int carry=0;
    int diff;
    Node* new_head=NULL;
    Node* curr=NULL;
    while(curr1!=NULL)
    {
        if(carry!=0)
        {
            curr1->data-=1;
            carry=0;
        }
        
        if(curr1!=NULL and curr2!=NULL)
        {
            if(curr1->data<curr2->data)
            {
                carry=1;
                curr1->data+=10;
                
            }
            diff=curr1->data-curr2->data;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        else if(curr1->data<0)
        {
            curr1->data+=10;
            diff=curr1->data;
            carry=1;
            curr1=curr1->next;
        }
        else
        {
            diff=curr1->data;
            curr1=curr1->next;
        }
        
        
        Node* temp=new Node(diff);
        
        if(new_head==NULL)
        {
            new_head=temp;
            curr=temp;
        }
        else
        {
            curr->next=temp;
            curr=temp;
        }
    }
   
    
    Node* rev=reverse(new_head);
    
    return rev;
    
}
Node* subLinkedList(Node* l1, Node* l2)
{
    Node* head1=l1;
    Node* head2=l2;
    
    //1
    while(head1!=NULL and head1->data==0)
    head1=head1->next;
    
    while(head2!=NULL and head2->data==0)
    head2=head2->next;
    
    //2
    Node* curr1=head1;
    Node* curr2=head2;
    
    int count1=count_nodes(curr1);
    int count2=count_nodes(curr2);
    
    //3 count1<count2
    if(count1<count2)
    return subLinkedList(l2,l1);
    
    //4 when count1==count2
    if(count1==count2)
    {
         curr1=head1;
         curr2=head2;
         while(curr1!=NULL and curr1->data==curr2->data)
         {
          curr1=curr1->next;
          curr2=curr2->next;
         }
    
         // 5 here if both are equal numbers 
         // l1->123     l2->123
         // o/p ->0 
         if(curr1==NULL)
         return new Node(0);
    
         if(curr2->data>curr1->data)
         return subLinkedList(l2,l1);
    }
   
    
    //6 now here we left with only case when l1>l2
    curr1=reverse(head1);
    curr2=reverse(head2);
    
   
    
    Node* res=solve(curr1,curr2);
    
    while(res!=NULL and res->data==0)
    res=res->next;
    
    return res;
}


