//My solution using queues

/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        queue<Node *> q;
        int cnt=1,lcnt=0;
        
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            Node * temp=q.front();
            q.pop();
            
            if(temp==NULL){
                cnt++;
                
                if(!q.empty())
                 q.push(NULL);
            }
            
            else{
                if(temp->left==NULL && temp->right==NULL){
                    if(lcnt==0){
                        lcnt=cnt;
                    }
                    
                    else if(lcnt!=cnt){
                        return 0;
                        
                    }
                }
                
                else{
                    if(temp->left)
                    q.push(temp->left);
                    
                    if(temp->right)
                    q.push(temp->right);
                }
            }
        }
        return 1;
    }
};

//Another DFS based recursive approach o(1) Space complexity

void solve(Node* root, int &mini, int &maxi, int level) {
        if(!root) return;
        
        if(!root -> left and !root -> right) {
            mini = min(level, mini);
            maxi = max(maxi, level);
        }
        
        solve(root->left, mini, maxi, level+1);
        solve(root->right, mini, maxi, level+1);
        
    }
    bool check(Node *root)
    {
        //Your code here
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        solve(root, mini, maxi, 0);
        
        return mini == maxi ? 1 : 0;
    }


//Another approach
bool ck(Node* root,int level)
    {
        
        if(root->left==NULL && root->right==NULL)
        {
            if(lv==0)
            {
                lv=level;
                return true;
            }
            else
            {
                if(level==lv)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        
        bool left=true;
        
        if(root->left)
        {
            left=ck(root->left,level+1);
        }
        bool right=true;
        if(root->right)
        {
            right=ck(root->right,level+1);
        }
        
        return left&&right;
        
    }
    
    bool check(Node *root)
    {
        lv=0;
        return ck(root,1);
    }

