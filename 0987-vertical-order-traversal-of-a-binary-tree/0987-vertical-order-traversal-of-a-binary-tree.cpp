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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>pq;
        pq.push({root,{0,0}});
        while(!pq.empty()){
            auto front=pq.front();
            pq.pop();
            pair<int,int>pos=front.second;
            TreeNode*node=front.first;
            mp[pos.first][pos.second].insert(node->val);
            if(node->left){
                pq.push({node->left,{pos.first-1,pos.second+1}});
            }
            if(node->right){
                pq.push({node->right,{pos.first+1,pos.second+1}});
            }
        }
        
        vector<vector<int>>res;
        for(auto it:mp){
            vector<int>tmp;
            for(auto p:it.second){
                tmp.insert(tmp.end(),p.second.begin(),p.second.end());
            }
            res.push_back(tmp);
        }
        return res;
    }
};