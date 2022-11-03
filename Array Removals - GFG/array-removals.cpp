//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int memo[101][101];
    int helper(vector<int>&arr,int i,int j,int k){
        if(i>=j){
            return 0;
        }
        if(arr[j]-arr[i]<=k)return 0;
        if(memo[i][j]!=-1)return memo[i][j];
        int a=helper(arr,i+1,j,k);
        int b=helper(arr,i,j-1,k);
        return memo[i][j]= 1+min(a,b);
    }
    
    int removals(vector<int>& arr, int k){
        //Code here
        memset(memo,-1,sizeof(memo));
        sort(arr.begin(),arr.end());
        return helper(arr,0,arr.size()-1,k);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends