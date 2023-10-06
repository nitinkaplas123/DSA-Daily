Solution -:
Steps-:
1)Two cases-:
  1. if position at 0 
  2. Rest shift the position according to.


Code-:
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
      SinglyLinkedListNode* temp=new SinglyLinkedListNode(data);
      if(position==0)
      {
          temp->next=llist;
          return temp;
      }
      else{
          SinglyLinkedListNode* curr=llist;
          for(int i=0;i<position-1;i++)
          {
              curr=curr->next;
          }
          SinglyLinkedListNode* save=curr->next;
          curr->next=temp;
          temp->next=save;
          return llist;
      }
}