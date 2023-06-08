//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	queue<Node *> q;
    	vector<int> ap,ans;
    	int cnt=0;
    	
    	//ap.push_back(root->data);
    	q.push(root);
    	q.push(NULL);
    	
    	while(!q.empty()){
    	    Node *temp=q.front();
    	    q.pop();
    	    
    	    if(temp==NULL){
    	        cnt++;
    	        
    	        if(cnt%2==0){
    	            reverse(ap.begin(),ap.end());
    	            
    	        }
    	           int N = sizeof(ap) / sizeof(ap[0])  ;
    	       // for(int i=0;i<N;i++)
    	       // ans.push_back(ap[i]);
    	       
    	      //  ans.insert(ans.begin(), ap, ap+N);
    	       copy(begin(ap), end(ap), back_inserter(ans));
    	       //It inserts elements into ans
    	        
    	        ap.clear();
    	        if(!q.empty()){
    	            q.push(NULL);
    	        }
    	    }
    	    else{
    	        
    	        ap.push_back(temp->data);
    	        if(temp->left)
    	        q.push(temp->left);
    	        
    	        if(temp->right)
    	        q.push(temp->right);
    	    }
    	}
    	
    	return ans;
    }
};

//Similar approach
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        // Code here
        vector<int>final_ans;
         queue<Node*>q;
       q.push(root);
          if(root==NULL)
       {
        return final_ans;   
       }
       int count=0;
       while(!q.empty())
       {
           int size=q.size();
           vector<int>temp;
           for(int i=0;i<size;i++)
           {
               Node* front_element=q.front();
               q.pop();
               temp.push_back(front_element->data);
               if(front_element->left)
               {
                   q.push(front_element->left);
               }
               if(front_element->right)
               {
                   q.push(front_element->right);
               }
           }
           if(count%2!=0)
           {
               reverse(temp.begin(),temp.end());
           }
           for(int i=0;i<temp.size();i++)
           {
               final_ans.push_back(temp[i]);
           }
           count++;
       } 
       return final_ans;
    }
};
