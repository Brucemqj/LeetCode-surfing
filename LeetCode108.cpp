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
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		int hi = static_cast<int>(nums.size());
		return buildBST(nums, 0, hi);
	}
	
private:
	TreeNode* buildBST(const vector<int>& nums, int lo, int hi) // hi is not included in nums.
	{
		if(lo >= hi)
			return nullptr;
		int mid = lo + (hi - lo) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = buildBST(nums, lo, mid);
		root->right = buildBST(nums, mid + 1, hi);
		return root;
	}
};