question link-:


Solution 1-:
Steps-:
1)Make a count array where we use this array as hashmap and increment the values.
2)If the freq at index ==0 means its missing 
  if the Freq at index==2 means its repeating.

Code-: Time->O(N)  Space ->O(N)

vector<int> findTwoElement(vector<int> arr, int n)
{
        int count[n]={0};
        for(int i=0;i<arr.size();i++)
        {
            count[arr[i]-1]++;
        }
        
        int missing,repeat;
        for(int i=0;i<n;i++)
        {
            if(count[i]==0)
            missing=i+1;
            if(count[i]==2)
            repeat=i+1;
        }
        return {repeat,missing};
    }



Solution 2-:
Steps-:
1) Here first we calculate the xor of all arr[i] and i+1 elements
    1 2 3
   [1,3,3]

   xor=1^1^2^3^3^3
   xor=>2^3 
      =>1

2)Here we have to separate the -:
  xor=>1 as (2^3)
  because we know that bw 2 and 3 one number is missing and another is repeating.

3)To separate we use bit manipulating.
  int bits=0;
       while(1)
       {
         if(res & (1<<bits)!=0)
         break;
         else
         bits++;
       }

    At what position we find the bit is set from right to left side

    eg. [1]
    0 1 
     
    here we find the bits =0 which indicates at zero position 


4)Now we make two columns 0 and 1 and travese whole loop and indexs if the values at zero bit is 1 then separate xor 
  same as for bit is 0 then into different 

  eg 
   1 2 3
  [1,3,3]

  0=>2        =>  2
  1=>1^3^1^3^3=>  3


5)Now we separate both as 2 and 3 in two different variable 
6)Now we have to find which is repeating and which is missing using traverse the array and count it.



Code-: Time->O(N)  Space->O(1)

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	   
       int res=0;
       for(int i=0;i<n;i++)
       {
           res=res^(i+1)^arr[i];
       }
       
       int bits=0;
       while(1)
       {
         if(res & (1<<bits)!=0)
         break;
         else
         bits++;
       }
       
       
      int ones=0;
      int zeros=0;
      for(int i=0;i<n;i++)
      {
          int index=i+1;
          int val=arr[i];
          if(((1<<bits) & index)!=0)
          ones=ones^index;
          else
          zeros=zeros^index;
           
          if(((1<<bits) & val)!=0)
          ones=ones^val;
          else
          zeros=zeros^val;
      }
       
      int count=0;
      for(int i=0;i<n;i++)
      {
          if(arr[i]==ones)
          count++;
      }
      if(count>1)
      return {zeros,ones};
      else
      return {ones,zeros};
}


