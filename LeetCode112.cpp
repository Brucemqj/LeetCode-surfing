/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        int curSum = 0;
        return curSumHelper(root, curSum, sum);
    }
	
	// Stack method
	bool hasPathSum(TreeNode* root, int sum)
	{
		TreeNode *pre = NULL, *cur = root;
		stack<TreeNode*> treeStack;
		int curSum = 0;
		while(cur != NULL || !treeStack.empty())
		{
			while(cur != NULL)
			{
				curSum += cur->val;
				treeStack.push(cur);
				cur = cur->left;
			}
			cur = treeStack.top();
			if(cur->left == NULL && cur->right == NULL && curSum == sum)
				return true;
			if(cur->right != NULL && pre != cur->right) // hasn't traverse into right branch, then traverse it.
				cur = cur->right;
			else // right branch has been traversed, just pop and return to higher node.
			{
				pre = cur;
				curSum -= cur->val;
				treeStack.pop();
				cur = NULL; // notice that cur must be assigned NULL here, otherwise it will come into a dead loop.
			}
		}
		return false;
	}
    
private:
    bool curSumHelper(TreeNode* root, int curSum, const int& sum)
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(curSum + root->val == sum)
                return true;
            return false;
        }
        bool lfind = false, rfind = false;
        if(root->left != NULL)
            lfind = curSumHelper(root->left, curSum + root->val, sum);
        if(root->right != NULL)
            rfind = curSumHelper(root->right, curSum + root->val, sum);
        return lfind || rfind;
    }
	
}; 