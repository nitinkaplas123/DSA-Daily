Solution 1-:
Steps-:
1) here using helper function we check every node.
2) here using solve function we check the current node having leaf node at distance k or not.
   if(at distance k there is leaf node)
   count++;
3) return count;


Code-:Time->O(N*K) 
here helper function go to every node ->O(N)
here solve function go to the depth of tree -> O(k)
Time ->O(N*K)

int count=0;
    bool solve(Node* root,int k)
    {
        if(root==NULL) return false;
        
        if(k==0)
        {
            if(root->left==NULL and root->right==NULL)
            return true;
        }
        int left=solve(root->left,k-1);
        int right=solve(root->right,k-1);
        
        return (left || right);
     }
    void helper(Node* root,int k)
    {
        if(root==NULL) return ;
        
        if(solve(root,k))
        count++;
        
        helper(root->left,k);
        helper(root->right,k);
    }
    int printKDistantfromLeaf(Node* root, int k)
    {
    	 helper(root,k);
    	 return count;
    }


