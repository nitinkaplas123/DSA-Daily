Solution 1-:
eg 
[4,5]
[3,5,0]
sum=>[7,0,8]


Steps-:
1)We know that when we add two numbers we start from right to left side.
2)So here also we do same but we give singly linked list.
3)Idea is first reverse the two linked list
4)Add the linked  list
5)Now reverse the ans as well.

Code-: Time->O(n)

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
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
      
        Node* head1=reverse(first);
        Node* head2=reverse(second);
        Node* curr1=head1;
        Node* curr2=head2;
        Node* new_head=NULL;
        Node* curr=NULL;
        int carry=0;
        while(curr1!=NULL || curr2!=NULL || carry!=0)
        {
            int sum=0;
            if(curr1!=NULL)
            {
              sum+=curr1->data;
              curr1=curr1->next;
            }

            if(curr2!=NULL)
            {
                sum+=curr2->data;
                curr2=curr2->next;
            }
            sum+=carry;

            carry=sum/10;
            sum=sum%10;

            Node* temp=new Node(sum);
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
        Node* ans=reverse(new_head);
        return ans;
    }