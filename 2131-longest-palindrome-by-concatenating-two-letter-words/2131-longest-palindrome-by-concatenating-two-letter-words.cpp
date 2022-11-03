class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int len=0;
        int n=words.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        bool take=false;
        for(int i=0;i<n;i++){
            string t=words[i];
            reverse(t.begin(),t.end());
            // cout<<mp.size()<<" ";
            if(t[0]==t[1] && mp.find(t)!=mp.end()){
                if(mp[t]>=2){
                    len+=4;
                    mp[t]-=2;
                }
                else if(mp[t]>0&&!take){
                    len+=2;
                    // cout<<mp[t];
                    mp[t]--;
                    take=true;
                }
                
                if(mp[t]==0){
                    mp.erase(t);
                }
            
            }
            else if(mp.count(words[i])>0 &&mp.count(t)>0){
                len+=4;
                mp[words[i]]--;
                mp[t]--;
                if(mp[words[i]]==0)mp.erase(words[i]);
                if(mp[t]==0)mp.erase(t);
            }
        }
        return len;
    }
};