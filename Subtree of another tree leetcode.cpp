//solution video Neetcode :https://www.youtube.com/watch?v=E36O5SWp-LE

class Solution {
public:

        bool sametree(TreeNode* root, TreeNode* subRoot){
            if(!root && !subRoot)
            return true;

            //  if (!root || !subRoot) return false;

            // if(!root || !subRoot)
            // return false;



            if( root && subRoot && root->val==subRoot->val)
            return sametree(root->left,subRoot->left) && sametree(root->right,subRoot->right);

            return false;

       
        }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(!subRoot)
        return true;

        if(!root)
        return false;

        // if (!root || !subRoot)
        //     return false;

        if(sametree(root,subRoot))
        return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        // return true;

        // return false;
       

        
    }

    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     if (!p && !q) return true;
    //     if (!p || !q) return false;
    //     if (p->val != q->val) return false;

    //     return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 
    // }
    // bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    //     if (!root || !subRoot)
    //         return false;
        
    //     if (isSameTree(root, subRoot))
    //         return true;
        
    //     return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    // }
};
