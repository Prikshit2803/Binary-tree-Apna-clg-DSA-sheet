//Similar to left view
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       queue<Node *> q;
       if(!root)
       return ans;
       
       ans.push_back(root->data);
       q.push(root);
       q.push(NULL);
       
       while(!q.empty()){
           Node * temp=q.front();
           q.pop();
           
           if(temp==NULL){
               if(!q.empty()){
               if(q.front()!= NULL) ans.push_back(q.front()->data);
               q.push(NULL);
               }
           }
           
           else{
               if(temp->right)
               q.push(temp->right);
               
               
                if(temp->left)
               q.push(temp->left);
           }
       }
       return ans;
    }
};
