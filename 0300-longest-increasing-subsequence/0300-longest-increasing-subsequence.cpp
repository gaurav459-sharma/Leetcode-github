class Solution {
public:
//     vector<vector<int>>memo;
//     int helper(vector<int>& nums,int i,int previ){
        
//         if(i==nums.size())return 0;
        
//         if(nums[i]>tar){
//             return max(1+helper(nums,i+1,i),helper(nums,i+1,previ));
//         }
//         else{
//             return helper(nums,i+1,tar);
//         }
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         memo.resize(nums.size(),vector<int>(nums.size()));
//         return helper(nums,0,-1);
//     }
    int lengthOfLIS(vector<int>& nums){
        vector<int>ans;
        ans.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans[ans.size()-1]){
                ans.push_back(nums[i]);
            }
            else{
                auto lb=lower_bound(ans.begin(),ans.end(),nums[i]);
                int index=lb-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
};