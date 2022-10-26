class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
           
            if(sum%k==0&&i>=1)return true;
            
            if(mp.count(sum%k)>0){
                cout<<"f";
                if(i-mp[sum%k]-1>=1)return true;
            }
            else mp[sum%k]=i;
            
        }
        return false;
    }
};