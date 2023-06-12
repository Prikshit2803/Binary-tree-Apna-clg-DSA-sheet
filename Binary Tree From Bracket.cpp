BinaryTreeNode<int>* constructtree(string s , int &start) {
    if (s.size() == 0 || start >= s.size())
        return NULL;
 
    // constructing a number from the continuous digits
    int num = 0;
    while (start < s.size() && s[start] != '('
           && s[start] != ')') {
        int num_here = (int)(s[start] - '0');
        num = num * 10 + num_here;
        start = start + 1;
    }
 
    // creating a node from the constructed number from
    // above loop
      BinaryTreeNode<int>* root = NULL;
      if(num > 0)
          root = new BinaryTreeNode<int>(num);
 
    // As soon as we see first right parenthesis from the
    // current node we start to construct the tree in the
    // left
    if (start < s.size() && s[start] == '(') {
        start = start + 1;
        root->left = constructtree(s, start);
    }
    if (start < s.size() && s[start] == ')')
    {
      start = start + 1;
      return root;
    }
 
    // As soon as we see second right parenthesis from the
    // current node we start to construct the tree in the
    // right
    if (start < s.size() && s[start] == '(') {
        start = start + 1;
        root->right = constructtree(s, start);
    }
    if (start < s.size() && s[start] == ')')
        start = start + 1;
    return root;
}

void preorder(BinaryTreeNode<int>* root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

BinaryTreeNode<int>* treeFromBracket(string &str)
{
    int start = 0;
    BinaryTreeNode<int>* root = constructtree(str,start);
    preorder(root);
}
