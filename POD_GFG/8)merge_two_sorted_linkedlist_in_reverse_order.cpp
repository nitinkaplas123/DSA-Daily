Solution 1-:
Steps-:
1)Using iterative method.


Code-:
Node* reverse(Node* head)
    {
        Node* curr=head;
        Node* prev=NULL;
        
        while(curr!=NULL)
        {
            Node* save=curr->next;
            curr->next=prev;
            prev=curr;
            curr=save;
        }
        return prev;
    }
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        Node* curr1=node1;
        Node* curr2=node2;
        Node* curr=NULL;
        Node* head=NULL;
        Node* ans=NULL;
        
        if(curr1==NULL)
        {
           ans=reverse(curr2);
           return ans;
        }
        if(curr2==NULL)
        {
            ans=reverse(curr1);
            return ans;
        }
       
        
        while(curr1!=NULL and curr2!=NULL)
        {
            if(curr1->data<curr2->data)
            {
                if(head==NULL)
                {
                     head=curr1;
                     curr=curr1;
                }
                else
                {
                    curr->next=curr1;
                    curr=curr1;
                }
                curr1=curr1->next;
            }
            else
            {
                if(head==NULL)
                {
                     head=curr2;
                     curr=curr2;
                }
                else
                {
                    curr->next=curr2;
                    curr=curr2;
                }
                curr2=curr2->next;
            }
        }
        
        if(curr2!=NULL)
        curr->next=curr2;
        if(curr1!=NULL)
        curr->next=curr1;
        
        
        Node* res=reverse(head);
        return res;
    } 




Solution 2-:
Steps-:
1)Using recursion 
 

Code-:
Node* reverse(Node* head)
{
        Node* curr=head;
        Node* prev=NULL;
        
        while(curr!=NULL)
        {
            Node* save=curr->next;
            curr->next=prev;
            prev=curr;
            curr=save;
        }
        return prev;
}

Node* helper(Node* list1,Node* list2)
{
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        if(list1->data<list2->data)
        {
            list1->next=helper(list1->next,list2);
            return list1;
        }
        else
        {
            list2->next=helper(list1,list2->next);
            return list2;
        }
}

struct Node * mergeResult(Node *node1,Node *node2)
{
       Node* head=helper(node1,node2);
       Node* ans=reverse(head);
       return ans;
}  

