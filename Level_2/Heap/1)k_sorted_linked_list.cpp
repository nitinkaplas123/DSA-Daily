Solution 1-:
Steps-:
1)make an array put all linked_list values into an array.
2)sort the array.
3)convert the array elements into linked list.
4)return head of it.



Solution 2-:
Steps-:
1)make a function merge two linkled_list.
2) merge(head1,head2) O(2*N)
   {
      
   }
2)for(int i=0;i<k;i++) O(K)
  {
     head=merge(head,head[i]);
  }
3) Time -> O(N*K)