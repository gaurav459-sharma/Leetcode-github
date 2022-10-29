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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL)return {};
        queue<TreeNode*>pq;
        vector<vector<int>>res;
        pq.push(root);
        
        
        while(!pq.empty()){ 
            int size=pq.size();
            vector<int>ans;
            for(int i=0;i<size;i++){
                TreeNode*front=pq.front();
                pq.pop();
                ans.push_back(front->val);
                if(front->left)pq.push(front->left);
                if(front->right)pq.push(front->right);
                
            }
            res.push_back(ans);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};