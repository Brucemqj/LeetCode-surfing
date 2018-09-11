class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        bool isBalanced = true;
        int d = depth(root, isBalanced);
        return isBalanced;
    }
    
private:
    int depth(TreeNode* root, bool& isBalanced)
    {
        if(root == NULL) return 0;
        int leftDepth = depth(root->left, isBalanced);
        int rightDepth = depth(root->right, isBalanced);
        if(leftDepth > rightDepth)
        {
            if(leftDepth > rightDepth + 1)
                isBalanced = false;
            return leftDepth + 1;
        }
        if(leftDepth < rightDepth)
        {
            if(leftDepth + 1 < rightDepth)
                isBalanced = false;
            return rightDepth + 1;
        }
        return leftDepth + 1;
    }
};