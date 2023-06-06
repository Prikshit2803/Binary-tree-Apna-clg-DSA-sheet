/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    
    vector<int> ans;
    
    if(root==NULL){
        return ans;
    }
    
    queue<Node *> q;
    
    
    q.push(root);
    
    while(!q.empty()){
        Node * temp=q.front();
        q.pop();
        
        ans.push_back(temp->data);
        
        if(temp->right){// Key step as right side traversal done first so order traversal is correct when array ans is reversed
            q.push(temp->right);
            
    
        }
        
        if(temp->left){
            q.push(temp->left);
            
    
        }
        
    }
    
    reverse(ans.begin(),ans.end());
    
    return ans;
}
