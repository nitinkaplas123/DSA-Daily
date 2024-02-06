Solution 1-:
Steps-:
Four cases-:
//case1 -:when head is NULL
//case 2 -:when head->data>=data means the given value should be our new head.
//Case 3-:here data should be fit into middle.
//Case 4-:when it should be fit into the last element.


Explanation:

Case 1: If the list is empty (head is NULL), create a new node temp with the given data. 
        Since it's the only node, it points to itself and becomes the head.
Case 2: If the new data is smaller or equal to the current head's data, insert the new node
        before the head. Adjust the pointers accordingly, and swap the data values of the head 
        and the new node.
Case 3: Otherwise, traverse the list to find the correct position to insert the new node while 
        maintaining the sorted order. Insert the new node between prev and curr. If curr reaches 
        the head, it means the new node should be inserted at the end of the list, so it points 
        back to the head.
Finally, return the head of the modified list.


Code-: Time->O(n) Space->O(1)
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