Solution 1-:
Steps-:
1)Using level order traversal.

Code-: Time->O(N) Space->O(N)
vector<int> largestValues(TreeNode* root) {
        vector<int>v;
        if(root==NULL)
        return v;
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty()==false)
        {
            int size=q.size();
            int ans=INT_MIN;
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                ans=max(ans,curr->val);
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
            v.push_back(ans);
        }
        return v;
    }



Solution 2-:
Steps-:
1)using recursion

Code-:
void helper(TreeNode* root,vector<int>&v,int level)
{
          if(root==NULL)
          return ;

          if(v[level]<root->val)
          v[level]=root->val;

          helper(root->left,v,level+1);
          helper(root->right,v,level+1);
}

int height(TreeNode* root)
{
        if(root==NULL)
        return 0;
        return 1+max(height(root->left),height(root->right));
}

vector<int> largestValues(TreeNode* root)
{
        int n=height(root);
        vector<int>v(n,INT_MIN);
        if(root==NULL)
        return v;
        int level=0;
        helper(root,v,level);
        return v;
}