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
    void helper(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode* &result){
        if(original == nullptr || cloned == nullptr){
            return;
        }
        if(result != nullptr){
            return;
        }
        if(original == target){
            result = cloned;
            return;
        }
        if(original->left){
            helper(original->left, cloned->left,target,result);
        }
        if(original->right){
            helper(original->right, cloned->right,target,result);
        }
        return ;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        //check every Node if orginal == target then return the corrosponding cloned value.
        
        TreeNode* result = nullptr;
        helper(original, cloned, target, result);
        return result;
    }
};
