//Similar approach to level order traversal except pnly the elements right after NULL after printed

vector<int> leftView(Node *root)
{
   queue<Node*> q;
   vector<int> ans;
   if(root ==NULL )
   return ans;
   
   ans.push_back(root->data);
   q.push(root);
   q.push(NULL);
   
   
   while(!q.empty()){
       Node * temp=q.front();
       q.pop();
       
       if(temp == NULL){
           
           
           if(!q.empty()){
           if(q.front()!=NULL) 
           ans.push_back(q.front()->data);
           
           
           q.push(NULL);
           }
       }
       
       else{
           if(temp->left)
           q.push(temp->left);
           
           if(temp->right)
           q.push(temp->right);
       }
   }
   return ans;
}
