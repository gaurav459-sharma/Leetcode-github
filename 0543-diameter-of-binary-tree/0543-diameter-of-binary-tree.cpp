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
    pair<int,int>helper(TreeNode*root){
        if(root==NULL){
            pair<int,int>output;
            output.first=0;
            output.second=0;
            return output;
        }
        pair<int,int>lans=helper(root->left);
        pair<int,int>rans=helper(root->right);
        
        pair<int,int>ans;
        ans.first=max(max(lans.first,rans.first),lans.second+rans.second);
        ans.second=1+max(lans.second,rans.second);
        return ans;
        
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).first;
    }
};