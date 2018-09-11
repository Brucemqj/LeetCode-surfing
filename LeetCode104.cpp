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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return (left > right) ? left + 1 : right + 1;
    }
	
	// BFS O(N) space with two queue
    int maxDepth(TreeNode* root)
	{
		if (root == NULL) return 0;
		queue<TreeNode*> treeQueue;
		treeQueue.push(root);
		int level = 0;
		while (!treeQueue.empty())
		{
			++level;
			queue<TreeNode*> tmpQueue;
			int treeQueueSize = static_cast<int>(treeQueue.size());
			for (int i = 0; i < treeQueueSize; ++i)
			{
				TreeNode* treeNode = treeQueue.front();
				treeQueue.pop();
				if (treeNode->left != NULL)
					tmpQueue.push(treeNode->left);
				if (treeNode->right != NULL)
					tmpQueue.push(treeNode->right);
			}
			int tmpQueueSize = static_cast<int>(tmpQueue.size());
			for (int i = 0; i < tmpQueueSize; ++i)
			{
				treeQueue.push(tmpQueue.front());
				tmpQueue.pop();
			}
		}
		return level;
	}
    
    // BFS O(N) space with one queue
    int maxDepth(TreeNode* root)
	{
		if (root == NULL) return 0;
		queue<TreeNode*> treeQueue;
		treeQueue.push(root);
		int curLevelNode = 1;
		int nextLevelNode = 0;
		int level = 0;
		while (!treeQueue.empty())
		{
			level++;
			for (int i = 0; i < curLevelNode; ++i)
			{
				TreeNode* node = treeQueue.front();
				treeQueue.pop();
				if (node->left != NULL)
				{
					treeQueue.push(node->left);
					++nextLevelNode;
				}
				if (node->right != NULL)
				{
					treeQueue.push(node->right);
					++nextLevelNode;
				}
			}
			curLevelNode = nextLevelNode;
			nextLevelNode = 0;
		}
		return level;
	}
};