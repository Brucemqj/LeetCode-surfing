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
	// DFS
    void search(TreeNode* root, int level, vector<vector<int>>& rst)
    {
        if(root == NULL) return;
        if(level > static_cast<int>(rst.size()))
        {
            vector<int> curLevel;
            rst.insert(rst.begin(), curLevel);
        }
        int size = static_cast<int>(rst.size());
        rst[size-level].push_back(root->val);
        search(root->left, level+1, rst);
        search(root->right, level+1, rst);
    }
	
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> rst;
        if(root == NULL) return rst;
        search(root, 1, rst);
        return rst;
    }
};