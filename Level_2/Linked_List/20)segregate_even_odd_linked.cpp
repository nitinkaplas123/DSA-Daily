Solution 1-:
Steps-:
1)Make two separate node for even and odd nodes 
2)After linking even with even nodes and odd with odd nodes
3)Then merge according to question statement.

Question link-:
https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

Code-:
Node* divide(int N, Node *head)
{
        Node* even=NULL;
        Node* odd=NULL;
        Node* even_head=NULL;
        Node* odd_head=NULL;
        Node* curr=head;

        while(curr!=NULL)
        {
            if(curr->data%2==0)
            {
                if(even_head==NULL)
                {
                   even_head=curr;
                   even=curr;
                }
                else
                {
                    even->next=curr;
                    even=curr;
                }
            }
            else
            {
                if(odd_head==NULL)
                {
                   odd_head=curr;
                   odd=curr;
                }
                else
                {
                    odd->next=curr;
                    odd=curr;
                }
            }
            curr=curr->next;
        }
        
        if(even_head==NULL) 
        {
            odd->next=NULL;
            return odd_head;
        }
        even->next=odd_head;
        if(odd)
        odd->next=NULL;
        return even_head;
}