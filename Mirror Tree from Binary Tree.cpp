#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

void mirrorTree(BinaryTreeNode<int> *root) {
    //   if(!root)
    //     return 0;
     if(root == NULL){
    return;
    }

        BinaryTreeNode<int> * temp=root->left;
        //BinaryTreeNode<int> * left=mirrorTree(root->left);

        root->left=root->right;
        root->right=temp;

        mirrorTree(root->left);
        mirrorTree(root->right);

       // return 0;
}


//GFG solution
// Function to convert to mirror tree
// by swapping the left and right links.
public static Node mirrorTree(Node root)
{
    if (root == null)
        return null;
 
    Node left = mirrorTree(root.left);
    Node right = mirrorTree(root.right);
 
    root.left = right;
    root.right = left;
 
    return root;
}
 
