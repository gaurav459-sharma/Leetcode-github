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
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>pq;
        pq.push({root,{0,0}});
        int node=root->val;
        int ml=0;
        int md=0;
        while(!pq.empty()){
            auto front=pq.front();
            pq.pop();
            TreeNode*data=front.first;
            int d=front.second.first;
            int l=front.second.second;
            if(d>md||(d==md &&l<ml)){
                md=d;
                ml=l;
                node=data->val;
            }
            if(data->left){
                pq.push({data->left,{d+1,l-1}});
            }
            if(data->right){
                pq.push({data->right,{d+1,l+1}});
            }
            
          
        }
        return node;
    }
};