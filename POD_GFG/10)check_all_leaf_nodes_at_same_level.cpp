Solution 1-:
Steps-:
1)First a fall we find the height of the tree.
2)In helper function we count the nodes from every path from root to leaf.
3)If level!=height means all leaf nodes are not at equal level.

Code-: Time->O(N)
int heights(Node* root)
{
        if(root==NULL) return 0;
        else
        return 1+max(heights(root->left),heights(root->right));
}

void helper(Node* root,int level,int height,int &res)
{
        if(root==NULL) return ;
        level++;
        
        if(root->left==NULL and root->right==NULL)
        {
            if(level!=height)
            {
                res=0;
                return ;
            }
        }
        
        helper(root->left,level,height,res);
        helper(root->right,level,height,res);
}

bool check(Node *root)
{
       int height=heights(root);
       int res=1;
       helper(root,0,height,res);
       return res;
}



In Js-:
Code-:
heights(root)
    {
        if(root==null) return 0;
        return 1+Math.max(this.heights(root.left),this.heights(root.right));
    }
    helper(root,level,res,height)
    {
        if(root==null) return ;
        level++;
        
        if(root.left==null && root.right==null)
        {
            if(level!=height)
            {
                res[0]=0;
                return ;
            }
        }
        
        this.helper(root.left,level,res,height);
        this.helper(root.right,level,res,height);
    }
  	check(root){
  		let height=this.heights(root);
  		let level=0;
  		let res=[1];   // Using an array to pass by reference
  		this.helper(root,level,res,height);
  		return res;
  	}

Diff bw C++ and Js code=:

1)null is used instead of NULL.
2)Logical operators (&& instead of and, || instead of or).
3)Math.max() is used instead of max() from C++.
4)Parameters in function definitions are separated by commas (,).
5)res is passed as an array to act as a reference since JavaScript does not support passing variables by reference directly.
6)The check() function returns res[0] instead of res, as res is an array containing the result.
7)With these changes, the JavaScript code should function properly.