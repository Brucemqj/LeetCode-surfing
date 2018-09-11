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
	// Recursive method
    bool isSame(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL) return true;
        if(left != NULL && right != NULL)
            return (left->val == right->val) & isSame(left->left, right->right) & isSame(left->right, right->left);
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSame(root->left, root->right);
    }
	
	// Iterative method
	bool isSame(TreeNode* left, TreeNode* right)
	{
		if(left == NULL && right == NULL) return true;
		// next two lines can be compressed to on line casue above line is first ocasion.
		// if( left == NULL || right == NULL ) return false;
		if(left == NULL && right != NULL) return false;
		if(left != NULL && right == NULL) return false;
		stack<TreeNode*> leftS;
		stack<TreeNode*> rightS;
		leftS.push_back(left);
		rightS.push_back(right);
		while( !leftS.empty() && !rightS.empty() )
		{
			TreeNode* L = leftS.top();
			TreeNode* R = rightS.top();
			if(L->val != R->val) return false;
			if(L->left == NULL && R->right != NULL) return false;
			if(L->left != NULL && R->right == NULL) return false;
			if(leftS.size() != rightS.size()) return false;
			leftS.pop();
			rightS.pop();
			if(L->left != NULL && R->right != NULL)
			{
				leftS.push_back(L->left);
				rightS.push_back(R->right);
			}	
			if(L->right == NULL && R->left != NULL) return false;
			if(L->right != NULL && R->left == NULL) return false;
			if(L->right != NULL && R->left != NULL)
			{	
				leftS.push_back(L->right);
				rightS.push_back(R->left);
			}
		}
		return leftS.empty() & rightS.empty();
	}
	
	// More concise solution
	bool isSymmetric(TreeNode* root) {
    Queue<TreeNode*> q = new LinkedList<>();
    q.add(root);
    q.add(root);
    while (!q.isEmpty()) {
        TreeNode t1 = q.poll();
        TreeNode t2 = q.poll();
        if (t1 == NULL && t2 == NULL) continue;
        if (t1 == NULL || t2 == NULL) return false;
        if (t1->val != t2->val) return false;
        q.add(t1->left);
        q.add(t2->right);
        q.add(t1->right);
        q.add(t2->left);
    }
    return true;
}
};
