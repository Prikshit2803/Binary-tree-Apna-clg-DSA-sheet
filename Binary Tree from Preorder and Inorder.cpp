/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

int fpos(vector<int>& inorder,int element,int n){
    for(int i=0;i<n;i++){
        if(inorder[i]== element)
        return i;
    }
    return -1;
}                                                                   //THi s& is most crucial step

     TreeNode * solve(vector<int>& preorder, vector<int>& inorder,int &preorderIndex,int inorderstart,int inorderEnd,int n){
         if(preorderIndex>=n || inorderstart > inorderEnd){
             return NULL;
         }

         int element=preorder[preorderIndex++];
         TreeNode* root=new TreeNode(element);
         int pos=fpos(inorder,element,n);

         root->left=solve(preorder,inorder,preorderIndex,inorderstart,pos-1,n);
         root->right=solve(preorder,inorder,preorderIndex,pos+1,inorderEnd,n);

         return root;

     }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int preorderIndex=0;
        int n=inorder.size();
        TreeNode* ans=solve(preorder,inorder,preorderIndex,0,n-1,n);
        return ans;
    }
};

//For case where elements repeat i.e. for eg. more than one 3 in tree

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    
    
    public:
    
    int fpos(int inorder[],int element,int start,int end){
    for(int i=start;i<=end;i++){
        if(inorder[i]== element)
        return i;
    }
    return -1;
}

     Node * solve(int in[], int pre[],int &preorderIndex,int inorderstart,int inorderEnd,int n){
         if(preorderIndex>=n || inorderstart > inorderEnd){
             return NULL;
         }

         int element=pre[preorderIndex++];
         Node* root=new Node(element);
         int pos=fpos(in,element,inorderstart,inorderEnd);

         root->left=solve(in,pre,preorderIndex,inorderstart,pos-1,n);
         root->right=solve(in,pre,preorderIndex,pos+1,inorderEnd,n);

         return root;

     }
    Node* buildTree(int in[],int pre[], int n)
    {    int preorderIndex=0;
        Node* ans=solve(in,pre,preorderIndex,0,n-1,n);
        return ans;
    }
};
