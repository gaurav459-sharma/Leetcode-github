class Solution {
public:
    int trap(vector<int>& height) {
//         int n=height.size();
//         vector<int>leftmax(n);
//         vector<int>rightmax(n);
//         leftmax[0]=height[0];
//         rightmax[n-1]=height[n-1];
//         for(int i=1;i<n;i++){
//             leftmax[i]=max(leftmax[i-1],height[i]);
//         }
//          for(int i=n-2;i>=0;i--){
//             rightmax[i]=max(rightmax[i+1],height[i]);
//         }
        
//         int ans=0;
//         for(int i=0;i<n;i++){
//             ans+=min(leftmax[i],rightmax[i])-height[i];
//         }
//         return ans;
        
        //second method space complexity=0(1)
        int n=height.size();
        int l=0,r=n-1;
        int lmax=0,rmax=0;
        int ans=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>lmax)lmax=height[l];
                else ans+=lmax-height[l];
                l++;
            }
            else{
                if(height[r]>rmax)rmax=height[r];
                else ans+=rmax-height[r];
                r--;
            }
        }
        return ans;
    }
};