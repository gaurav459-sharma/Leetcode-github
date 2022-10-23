class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>res;
        vector<int>tmp=nums;
        for(int i=0;i<tmp.size();i++){
            if(tmp[abs(tmp[i])-1]<0){
                res.push_back(abs(tmp[i]));
                break;
            }
            
              tmp[abs(tmp[i])-1]=-tmp[abs(tmp[i])-1];
            
        }
        int sum=0;
        for(auto&t:nums)sum+=t;
        sum-=res[0];
        int n=nums.size();
        int ss=(n*(n+1))/2; 
        res.push_back(ss-sum);
        return res;
    }
};