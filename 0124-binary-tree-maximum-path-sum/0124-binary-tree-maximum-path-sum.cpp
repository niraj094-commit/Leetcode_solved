/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int helper(TreeNode* root,int &max_sum){
        if(!root) return 0;

        int leftSum=max(helper(root->left,max_sum),0);
        int rightSum=max(helper(root->right,max_sum),0);

        int curr_path_sum=root->val+leftSum+rightSum;

        max_sum=max(max_sum,curr_path_sum);

        return root->val+max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int max_sum=INT_MIN;

        helper(root,max_sum);

        return max_sum;
        
    }
};