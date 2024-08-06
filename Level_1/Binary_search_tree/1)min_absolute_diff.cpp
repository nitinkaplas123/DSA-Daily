Question -:
https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1


Solution 1-:
Steps-:
1) its a bst so means its in sorted order if u store in a inorder traversal.

Code-:
void helper(Node* root,vector<int>&v)
{
        if(root==NULL) 
        return ;
        helper(root->left,v);
        v.push_back(root->data);
        helper(root->right,v);
}
    
int absolute_diff(Node *root)
{
        vector<int>v;
        helper(root,v);
        int ans=INT_MAX;
        for(int i=1;i<v.size();i++)
        {
            ans=min(ans,v[i]-v[i-1]);
        }
        return ans;
}


Solution 2-:
Steps-:
1)track of previous value and make difference with (root->data-prev)

Code-:
void helper(Node* root,int &prev,int &ans)
{
        if(root==NULL) return ;
        
        helper(root->left,prev,ans);
        
        ans=min(ans,root->data-prev);
        prev=root->data;
       
        helper(root->right,prev,ans);
}

int absolute_diff(Node *root)
{
       int prev=-1e9;
       int ans=INT_MAX;
       helper(root,prev,ans);
       return ans;
}