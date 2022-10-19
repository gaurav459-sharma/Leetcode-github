bool comp(pair<int,string>&a,pair<int,string>&b){
    if(a.first==b.first)return a.second>b.second;
    return a.first<b.first;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        int n=words.size();
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        vector<pair<int,string>>tmp;
        for(auto it:mp){
            tmp.push_back({it.second,it.first});
        }
        sort(tmp.rbegin(),tmp.rend(),comp);
        vector<string>res(k);
        for(int i=0;i<k;i++){
            res[i]=tmp[i].second;
        }
        return res;
            
    }
};