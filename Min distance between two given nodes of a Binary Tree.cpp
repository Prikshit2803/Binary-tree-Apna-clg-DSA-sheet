

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
    bool dist(Node * root , int n , vector<int> &ap){
        
        
        if(!root)
        return false;
        
        ap.push_back(root->data);
        
        if(root->data==n)
        return true;
        
        if(dist(root->left,n,ap) || dist(root->right,n,ap) )
        return true;
        
        ap.pop_back();
        
        return false;
    }
    
    Node * lca(Node * root, int a , int b){
         if(!root)
         return NULL;
         
         if(root->data==a || root->data==b)
         return root;
         
         Node * left = lca(root->left,a,b);
         Node * right = lca(root->right,a,b);
         
         if(left == NULL)
         return right;
         
         else if(right == NULL)
         return left;
         
         else
         return root;
         
        
    }
    
    int findDist(Node* root, int a, int b) {
        
        Node * lowestca = lca(root,a,b);
        
        vector<int> a1,a2,a3;
        
        dist(root,a,a1);
        dist(root,b,a2);
        dist(root,lowestca->data,a3);
        
        int ans = a1.size() + a2.size() - 2*a3.size(); //This is the crux of solution approach
        
        return ans;
      
    }
};
