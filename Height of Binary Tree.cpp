/*
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
    //Function to find the height of a binary tree.
    int height(struct Node* node){
       if(!node)
       return NULL;
       
       int l=height(node->left);
       int r=height(node->right);
       
       return max(l,r)+1;
    }
};
