//Solution link : https://leetcode.com/problems/maximum-depth-of-binary-tree/solutions/1770060/c-recursive-dfs-example-dry-run-well-explained/
//Video:https://youtu.be/hTM3phVI6YQ

class Solution {
public:


    int maxDepth(TreeNode* root) {

        if(root==NULL)
        return 0;

        int maxdepthleft=maxDepth(root->left);
        int maxdepthright=maxDepth(root->right);

        return max(maxdepthleft,maxdepthright)+1;
        
    }
};
