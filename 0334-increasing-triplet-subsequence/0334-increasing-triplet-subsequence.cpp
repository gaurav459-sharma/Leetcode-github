class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)return false;
      
        int fmax=INT_MAX;
        int smax=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=fmax)fmax=nums[i];
            else if(nums[i]<=smax)smax=nums[i];
            else return true;
        }
        return false;
      
    }
};