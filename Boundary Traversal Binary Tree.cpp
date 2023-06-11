// The soln is my version of Striver's approach that includes left boundary traversal , leaf nodes then reverse right boundary traversal
//Striver Video Link: https://www.youtube.com/watch?v=0ca1nvR0be4

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:

void inorder(Node * root, vector <int> &ans){
    if(!root)
    return;
    
    if(root->left==NULL && root->right==NULL)
    ans.push_back(root->data);
    
    inorder(root->left,ans);
    inorder(root->right,ans);
}
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        
        stack<int> st;
        
        
        if(!root)
        return ans;
        
        ans.push_back(root->data);
        
         if(root->left==NULL && root->right==NULL)
         return ans;
        
        Node * temp=root;
        
        temp=temp->left;
        
     while(temp && (temp->left || temp->right)){
         
        //  if(!(temp->left || temp->right))
        //  break;
         
         ans.push_back(temp->data);
         
         if(temp->left)
         temp=temp->left;
         
         else if(temp->right)
         temp=temp->right;
         
        //  else
        //  break;
     }
     
     
      inorder(root,ans);
     
     temp=root->right;
     
     
      while(temp && (temp->left!=NULL || temp->right!=NULL ) ){
        //  ans.push_back(temp->data);
        
        st.push(temp->data);
         
         if(temp->right)
         temp=temp->right;
         
         else
         temp=temp->left;
     }
     
     while(!st.empty()){
         ans.push_back(st.top());
         st.pop();
     }
     
     return ans;
        
        
    }
};

