//Similar to duplicate subtree in binary tree where no leaft node included whereas here leaf node is included
//Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree

unordered_map<Node *,int> mp;

string dfs(Node * root,unordered_map<string,pair<Node *,int>> &mp){
  
  if(!root)
  return "";
  
  string l=dfs(root->left,mp);
  string r=dfs(root->right,mp);
  
  string s=to_string(root->data) + "#" + l + "#" + r;
  
  if(mp.find(s)!=mp.end())
   mp[s].second++;
   
   else{
       mp[s].first=root;
       mp[s].second=1;
   }
  
  
  return s;
  
}

vector<Node*> printAllDups(Node* root)
{
    unordered_map<string,pair<Node *,int>> mp;
    dfs(root,mp);
    vector<Node *> ans;
    
    for(auto it : mp){
        if(it.second.second>=2)
        ans.push_back(it.second.first);
    }
    
    return ans;
}
