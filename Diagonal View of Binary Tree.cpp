// My solution and much optimised same approach solution

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


vector<int> diagonal(Node *root)
{ 
    
    // queue<Node *> q;
    // vector<int> ans;
    
    // q.push(root);
    // //ans.push_back(root->data);
    
    // while(!q.empty()){
    //     Node * temp=q.front();
    //     q.pop();
    //     ans.push_back(temp->data);
        
    //      if(temp->left)
    //      q.push(temp->left);
        
    //     while(temp->right){
    //     //      if(temp->left)
    //     // q.push(temp->left);
        
    //         temp=temp->right;
            
             
    //         if(temp->left)
    //      q.push(temp->left);
        
    //      ans.push_back(temp->data);
            
            
    //     }
         
         
    // }
    // return ans;
    
    
    //optimised Solution
    
    queue<Node *> q;
    vector<int> ans;
    
    q.push(root);
    
    while(!q.empty()){
        Node * temp=q.front();
        q.pop();
        
        while(temp){
            if(temp->left)
            q.push(temp->left);
            
            ans.push_back(temp->data);
            
            temp=temp->right;
        }
    }
    
    return ans;


}
