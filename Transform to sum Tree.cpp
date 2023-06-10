/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
  
  
  int solve(Node * node){
      if(!node)
      return 0;
      
      int l=solve(node->left);
      int r=solve(node->right);
      int x=node->data;
      node->data=l+r;
      return x+l+r;
  }
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
         solve(node);
    }
};
