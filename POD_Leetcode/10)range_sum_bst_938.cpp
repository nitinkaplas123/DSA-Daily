Solution 1-:
Steps-:
1)As its a bst so we take a vector and store the elements in inorder order traversal
  as its stored in sorted  order.
2)Now  traverse a vector v and add elements which is in range of low and high.


Code-: Time->O(N) Space->O(N)
void helper(TreeNode* root,vector<int>&v)
{
        if(root==NULL) return ;

        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);
}

int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>v;
        helper(root,v);

        int sum=0;
        for(int i=0;i<v.size();i++)
        {
           if(v[i]>=low and v[i]<=high)
           sum+=v[i];
        }
        return sum;
}