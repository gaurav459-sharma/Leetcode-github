class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        
        string ans=countAndSay(n-1);
        int ct=0;
        int i=0;
        int si=0;
        string res="";
        while(i<ans.length()){
            if(ans[i]==ans[si])ct++;
            else{
                string t=to_string(ct);
                res+=t;
                res+=ans[si];
                ct=1;
                si=i;
            }
            i++;
        }
               string t=to_string(ct);
                res+=t;
                res+=ans[si];
        return res;
    }
};