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

class Solution
{
    public:
    
    vector<int> a1,a2;
    
    bool solve1(Node * root, int n1){
        
        if(!root)
        return false;
        
         a1.push_back(root->data);
        
        
        if(root->data==n1){
           
            return true;
        }
        
       
        
      //  a1.push_back(root->data);
        
        if(solve1(root->left,n1) || solve1(root->right,n1))
        return true;
        
        a1.pop_back();
        
        return false;
    
    
    
        
        
        
        
        
    }
    
    bool solve2(Node * root, int n2){
        
        if(!root)
        return false;
        
        a2.push_back(root->data);
        
        if(root->data==n2){
            
            return true;
        }
        
        
        // a2.push_back(root->data);
        
        if (solve2(root->left,n2) || solve2(root->right,n2))
        return true;
        
       
      a2.pop_back();
        return false;
    
   

   
        
        
        
        
        
    }
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       solve1(root,n1);
       solve2(root,n2);
       
       Node * temp= NULL;
       
       for(int i=0;i<min(a1.size(),a2.size());i++){
          if(a1[i]==a2[i])
          temp=new Node(a1[i]);
        
        //cout<<a1[i]<<"";
       }
        
        return temp;
    }
};


// optimised soln with no o(1) space complexity Time complexity o(N) for both but above soln has Space complexity o(N)
//Striver soln : https://www.youtube.com/watch?v=_-QHfMDde90

class Solution
{
    public:
    
    
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(!root )
       return NULL;
       
       if(root->data==n1 || root->data==n2)
       return root;
       
       Node * left=lca(root->left,n1,n2);
       Node * right=lca(root->right,n1,n2);
       
      if(left==NULL)
      return right;
      
      else if(right==NULL)
      return left;
      
      else // it means that none is NULL and both return some value which is n1 and n2 hence root is LCA
       return root;
      
       
       
    }
};
