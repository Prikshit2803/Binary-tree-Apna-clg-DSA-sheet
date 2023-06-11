// Similar approach to Top view except the lattermost element in line is picked
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        queue<pair<Node *,int>> q;
        map<int,int> mp;
        vector<int> ans;
        
        q.push({root,0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node * temp=it.first;
            int line = it.second;
            
            mp[line]=temp->data;
            
            if(temp->left)
            q.push({temp->left,line-1});
            
            if(temp->right)
            q.push({temp->right,line+1});
            
            
        }
        
        for(auto it : mp)
        ans.push_back(it.second);
        
        return ans;
        
    }
};
