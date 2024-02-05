Solution 1-:
Steps-:
Four cases-:
//case1 -:when head is NULL
//case 2 -:when head->data>=data means the given value should be our new head.
//Case 3-:here data should be fit into middle.
//Case 4-:when it should be fit into the last element.


Node *sortedInsert(Node* head, int data)
    {
       //case1 -:when head is NULL
       if(head==NULL) 
       {
        Node *temp = new Node(data);
        temp->next = temp;
        return temp;
       }
       
       //case 2 -:when head->data>=data means the given value should be our new head.
       Node* temp=new Node(data);
       if(head->data>=data)
       {
           Node* next=head->next;
           head->next=temp;
           temp->next=next;
           swap(head->data,temp->data);
           return head;
       }
       //Case 3-:here data should be fit into middle or at the last position.
       else
       {
            Node* curr=head->next;
            Node* prev=head;
            while(curr!=head and curr->data<=data)
            {
              prev=curr;
              curr=curr->next;
            }
            prev->next=temp;
            if(curr!=head)
            temp->next=curr;
            else
            temp->next=head;
            return head;
       }
    }