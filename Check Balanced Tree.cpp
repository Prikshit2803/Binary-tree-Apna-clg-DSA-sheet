//Mdoified height function

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    
    int dfsheight(Node * root){
         if(!root)
       return 0;
       
       int lh=dfsheight(root->left);
        int rh=dfsheight(root->right);
        
        if(abs(lh-rh)>1) return -1;
        if(lh==-1 || rh==-1) return -1;
        
        return max(lh,rh) + 1;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
      if(dfsheight(root)!=-1)
      return 1;
      
      else
      return 0;
    
    // return dfsheight(root)!=-1;
    }
};
