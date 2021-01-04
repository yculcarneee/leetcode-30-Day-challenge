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
    
    /*void traverseTree(TreeNode* original, TreeNode *cloned, TreeNode *target, TreeNode **res) {
        if(original == NULL) {
            return;
        }
        traverseTree(original->left, cloned->left, target, res);
        if(original == target) {
            *res = cloned;
        }
        traverseTree(original->right, cloned->right, target, res);
    } */
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == NULL) {
            return NULL;
        }
        if(original == target) {
            return cloned;
        }
        TreeNode *left = getTargetCopy(original->left, cloned->left, target);   
        if(left != NULL) {
            return left;
        }
        return getTargetCopy(original->right, cloned->right, target);
    }
};