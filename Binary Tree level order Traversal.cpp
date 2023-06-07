//Love Babbar inspired approach

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode * > q;
        q.push(root);
        q.push(NULL);
        vector<int> ans;
        vector<vector <int> > ac;

        if(!root)
        return ac;   //key step

        while(!q.empty()){
            TreeNode * temp=q.front();
            
            
            q.pop();

            if(temp==NULL){
                //cout<<endl;
                ac.push_back(ans);
                ans.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }

           else{

               ans.push_back(temp->val);

               if(temp->left)
               q.push(temp->left);

               if(temp->right)
               q.push(temp->right);

           } 

        }

        return ac;

        
    }
};


//Another similar approach that also uses BFS

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
           int sz=q.size();
           vector<int>v;
           while(sz--){
               TreeNode * f=q.front();
               v.push_back(q.front()->val);
               q.pop();
               if(f->left)q.push(f->left);
               if(f->right)q.push(f->right);

           }
           ans.push_back(v);
        }
        return ans;
    }
};


//DFS approach
class Solution {
public:
    void dfs(TreeNode * root ,vector<vector<int>>&ans,int d=0){
      if(!root)return;
      if(d>=ans.size())ans.push_back({});
      ans[d].push_back(root->val);
      dfs(root->left,ans,d+1);
      dfs(root->right,ans,d+1);
  }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
         if(!root)return ans;
         dfs(root,ans);
        return ans;
    }
};

