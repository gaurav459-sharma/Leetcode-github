class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int>freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]==0)return false;
        }
        return true;
    }
};