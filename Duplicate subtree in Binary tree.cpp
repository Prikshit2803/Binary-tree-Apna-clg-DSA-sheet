{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
  
   unordered_map<string,int> mp;
  
  string solve(Node * root){
      if(!root)
      return "$";
      
      string s="";
      if(!root->right && !root->left){
          
          s= s + to_string(root->data);
          return s;
          
      }
      
      s=s + to_string(root->data);
       s+="."; // this is added as for input : 2 1 11 11 N 1.  '1 11 $' and '11 1 $' appeared same to map
      s=s+ solve(root->left);
       s+=".";
      s=s+ solve(root->right);
       s+=".";
      
      mp[s]++;
      
      return s;
  }
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
        mp.clear();
        solve(root);
        
        for(auto x:mp)
        if(x.second>=2) return true;
        
        return false;
        
    }
};
