Solution 1-:
Steps-:
1)using 2 for loop.
2)check each loop.

Code-: Time->O(N^2)
int minxorpair(int N, int arr[]){    
        int ans=INT_MAX;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(i!=j)
                ans=min(ans,arr[i]^arr[j]);
            }
        }
        return ans;
}


Solution 2-:
Steps-:
1)Here we have to sort the array first.
2)Because if we do xor of adjacent elements its pair result is very small as compared to other.
 for eg.
 N=8 -> 1000
 N=7 -> 0111
 Xor => 0000

 we learn this concept when we are doing bit manupilation and count the total no. of set bit in a number.

 Code-: Time -> O(Nlog(N))
 int minxorpair(int N, int arr[]){    
        int ans=INT_MAX;
        sort(arr,arr+N);
        
        for(int i=0;i<N-1;i++)
        {
            ans=min(ans,arr[i]^arr[i+1]);
        }
        return ans;
}



Solution 3-:
Steps-:

Detailed Explanation of Trie Operations (Insertion and Minimum XOR Calculation)
1)Trie Insertion (insert function):

For each element arr[i], we traverse through its binary representation from the most significant bit (MSB) to the least significant bit (LSB) (i.e., from bit 31 to bit 0).
We check each bit of the element and traverse the trie accordingly:
If the bit is 1, we move to the right child of the current node (node->link[1]).
If the bit is 0, we move to the left child of the current node (node->link[0]).
If the child node corresponding to the bit does not exist (node->link[i] == NULL), we create a new node and link it to the current node.
We repeat this process for all bits of the element, ensuring that each element is properly inserted into the trie according to its binary representation.

2)Minimum XOR Calculation (getMin function):

Similar to trie insertion, for each element x, we traverse through its binary representation from MSB to LSB.
At each bit position, we check if the corresponding child node exists in the trie:
If the bit is 1 and the right child exists (node->have(1)), we move to the right child.
If the bit is 1 and the right child does not exist, we move to the left child and add 2^i to the answer, where i is the current bit position.
If the bit is 0 and the left child exists (node->have(0)), we move to the left child.
If the bit is 0 and the left child does not exist, we move to the right child and add 2^i to the answer.
We repeat this process for all bits of the element, accumulating the bits that contribute to the minimum XOR value.
Finally, we return the accumulated value, which represents the minimum XOR value for the given element x.
Example
Let's walk through an example using the input array arr[] = {3, 10, 5, 2}:

Initialization: root = NULL, ans = INT_MAX.
Insertion and Minimum XOR Calculation:
Insert 3, 10, 5, and 2 into the trie.
Calculate minimum XOR for each element.
Return Minimum XOR Value: Return the minimum XOR value found during the iterations.

Conclusion
This algorithm efficiently finds the minimum XOR value between any two elements in 
the array by utilizing a trie data structure for storing and querying binary representations
of elements. The detailed explanation provides insights into how trie insertion and minimum
XOR calculation are performed, ensuring a clear understanding of the algorithm's working mechanism.

Code-:
struct Node
{
    Node *link[2];
    bool have(int i)
    {
        return (link[i] != NULL);
    }
};
Node *root = NULL;
void insert(int n)
{
    Node *node = root;
    for (int i = 31; i >= 0; i--)
    {
        if (((n >> i) & 1)!=0)
        {
            if (node->have(1)==NULL)
            node->link[1] = new Node();
            node = node->link[1];
        }
        else
        {
            if (node->have(0)==NULL)
            node->link[0] = new Node();
            node = node->link[0];
        }
    }
}

int getMin(int x)
{
    Node *node = root;
    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (((x>>i)&1)!=0)
        {
            // 1
            if (node->have(1)!=NULL)
            node = node->link[1];
            else
            {
              ans += (1<<i);
              node = node->link[0];
            }
        }
        else
        {
            // 0
            if(node->have(0)!=NULL)
            node = node->link[0];
            else
            {
               ans+=(1<<i);
               node = node->link[1];
            }
        }
    }
    return ans;
}
class Solution
{
    public:
    int minxorpair(int N, int arr[])
    {
        root = new Node();
        int ans = INT_MAX;
        for (int i = 0; i < N; i++)
        {
            if (i>0)
            ans = min(ans, getMin(arr[i]));
            insert(arr[i]);
        }
        return ans;
    }
};