//Striver solution using pair queue and ordered map
//LInk : https://www.youtube.com/watch?v=Et9OCDNvJ78

struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        
        vector<int> ans;
        queue<pair<Node *,int>> q;
        map<int ,int> mp;
        
        q.push({root,0});
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            Node * temp=it.first;
            int line=it.second;
            
            if(mp[line]==0)// no mapping found in map .... we only store the first value for a line
            mp[line]=temp->data;
            
            if(temp->left)
            q.push({temp->left,line-1});
            
            if(temp->right)
            q.push({temp->right,line+1});
        }
        
        for(auto it: mp)
        ans.push_back(it.second);
        
        return ans;
    }
