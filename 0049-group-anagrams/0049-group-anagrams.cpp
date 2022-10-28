class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>>mp;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(i);
        }
        vector<vector<string>>res;
        for(auto it:mp){
            vector<string>tmp;
            for(int i=0;i<it.second.size();i++){
                tmp.push_back(strs[it.second[i]]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};