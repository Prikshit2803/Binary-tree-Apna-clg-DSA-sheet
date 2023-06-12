//Basic logic behind solution is that inorder traversal of Binart search tree is in increasing order and swaps done to sort 
// inorder traversal of binary tree is the answer

class node{
      public:
      
      int data;
      node * left;
      node * right;
      
      node(int d){
          this->data=d;
          this->left=NULL;
          this->right=NULL;
      }
  };
  
  
class Solution{
  public:
  
  node* buildtree(vector<int> &A, int index){
      if(index>=A.size()||A[index]==-1)
      return NULL;
      
      node * root=new node(A[index]);
      
      int leftchild= 2*index + 1;
      
      root->left=buildtree(A,leftchild);
      
      int rightchild=2*index + 2;
      
      root->right=buildtree(A,rightchild);
      
      return root;
      
      
      
  }
  
  void inorder(node * root, vector<int> & ap){
      
      if(!root)
      return ;
      
      
      inorder(root->left,ap);
      ap.push_back(root->data);
      inorder(root->right,ap);
  }
  
    int minSwaps(vector<int>&A, int n){
       
       vector<int>  ap;
       node * root=buildtree(A,0);
       inorder(root,ap);
       
    //   for(int i=0;i<ap.size();i++)
    //   cout<<ap[i]<<"";
    
    
    
   // int* arr = ap.data();
   
   int cnt=0;
   int minindex=0;
   //Selection sort
  for(int i=0;i<ap.size()-1;++i){
       minindex=i;
      for(int j=i+1;j<ap.size();++j){
    // minindex=i;  Never do this as minindex initialised to i every time j loop starts
          if(ap[j]<ap[minindex])
          minindex=j;
      }
       
      if(minindex!=i){
          swap(ap[i],ap[minindex]);
          cnt++;
      }
  }


       
       return cnt;
    }
    
    
};

//A better approach that doesnt need us to build tree 
int minSwapss(vector<int>&nums) //This function is to sort and find minswaps for inorder of binary tree
	{
	    int n=nums.size();
	    vector<pair<int,int>> helper;
	    for(int i=0;i<n;i++)helper.push_back({nums[i],i});
	    sort(helper.begin(),helper.end());
	    int swaps=0;
	    for(int i=0;i<n;i++){
	        if(i==helper[i].second)continue;
	        else{
	            swap(helper[i],helper[helper[i].second]);
	            swaps++;
	            i--;
	        }
	    }
	    return swaps;
	}
	void inorder(vector<int>& v,int i,vector<int>&temp){
	    if(i>=v.size())return;
	    int left=2*i+1;
	    int right=2*i+2;
	    inorder(v,left,temp);
	    temp.push_back(v[i]);
	    inorder(v,right,temp);
	    return;
	}
//This is main function
    int minSwaps(vector<int>&A, int n){
        if(n==0 || n==1)return 0;
        vector<int> temp;
        inorder(A,0,temp);
        return minSwapss(temp);
        
    }
