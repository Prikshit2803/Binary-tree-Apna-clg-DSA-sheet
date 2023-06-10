//Both solns are similar and work : Both solutions are modified versions of height function
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
  
  int dia = 1;
int height (Node* root){
        if(root == NULL) return 0;
        int l = height(root->left);
        int r = height(root->right);
        
        dia = max(dia, l+r+1);
        return max(l, r) + 1;
    }
    
  int diameter(Node* root) {
  int h = height (root);
        return dia;
    }

// int height(Node* root, int& diameter) {
//     if (root == NULL) return 0;

//     int leftHeight = height(root->left, diameter);
//     int rightHeight = height(root->right, diameter);

//     int currentDiameter = leftHeight + rightHeight + 1;
//     diameter = max(diameter, currentDiameter);

//     return 1 + max(leftHeight, rightHeight);
// }

// int diameter(Node* root) {
//     if (root == NULL) return 0;

//     int diameter = 0;
//     height(root, diameter);

//     return diameter;
// }
};
