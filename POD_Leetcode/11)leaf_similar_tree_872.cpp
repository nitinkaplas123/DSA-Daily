Solution 1-:
Steps-:
1)make two vector v1 and v2 
2)store leaf nodes into v1 and v2.
3)return (v1==v2)


Code-:
void helper(TreeNode* root,vector<int>&v)
{
        if(root==NULL) return ;
        if(root->left==NULL and root->right==NULL)
        {
            v.push_back(root->val);
            return ;
        }
        helper(root->left,v);
        helper(root->right,v);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1;
        vector<int>v2;
        helper(root1,v1);
        helper(root2,v2);
        return (v1==v2);
}