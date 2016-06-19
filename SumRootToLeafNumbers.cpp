/* 
 * Given a binary tree containing digits from0-9only, each root-to-leaf 
 * path could represent a number.
 * An example is the root-to-leaf path1->2->3which represents the 
 * number123.
 * Find the total sum of all root-to-leaf numbers. 
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        s = 0;
        if (NULL == root)
            return 0;
        return sum(root, 0);
    }
    
    int sum(TreeNode *root, int path)
    {	
        path = 10 * path + root->val;
		
        if (NULL == root->left && NULL == root->right)
            s += path;
        
        if (NULL != root->left)
            sum(root->left, path);
        
        if (NULL != root->right)
            sum(root->right, path);
        
        return s;
    }
    int s;
};
