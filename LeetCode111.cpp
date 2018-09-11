class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int minDepth = INT_MAX;
        minDepthHelper(root, 1, minDepth);
        return minDepth;
    }
	
	// BFS method
	int minDepth(TreeNode* root)
	{
		if(root == NULL) return 0;
		queue<TreeNode*> treeQueue;
		treeQueue.push(root);
		int depth = 0;
		while(!treeQueue.empty())
		{
			++depth;
			int size = static_cast<int>(treeQueue.size());
			for(int i=0; i<size; ++i)
			{
				TreeNode* node = treeQueue.front();
				treeQueue.pop();
				if(node->left == NULL && node->right == NULL) return depth;
				if(node->left != NULL)
					treeQueue.push(node->left);
				if(node->right != NULL)
					treeQueue.push(node->right);
			}
		}
		return depth;
	}
    
private:
    void minDepthHelper(TreeNode* root, int curDepth, int& minDepth)
    {
        if(root->left == NULL && root->right == NULL) // Reach leaf node, update curDepth and minDepth
        {
            minDepth = curDepth < minDepth ? curDepth:minDepth;
            return;
        }
        if(root->left == NULL && root->right != NULL)
            minDepthHelper(root->right, curDepth+1, minDepth);
        if(root->left != NULL && root->right == NULL)
            minDepthHelper(root->left, curDepth+1, minDepth);
        if(root->left != NULL && root->right != NULL)
        {
            minDepthHelper(root->left, curDepth+1, minDepth);
            minDepthHelper(root->right, curDepth+1, minDepth);
        }
    }
};