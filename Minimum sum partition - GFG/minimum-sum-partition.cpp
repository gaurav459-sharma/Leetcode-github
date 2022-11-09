//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  vector<vector<int>>memo;
  int helper(int arr[],int i,int n,int sum,int tsum){
      if(i==n){
          return abs((tsum-sum)-sum);
      }
      if(memo[i][sum]!=-1)return memo[i][sum];
      
      int a=helper(arr,i+1,n,sum+arr[i],tsum);
      int b=helper(arr,i+1,n,sum,tsum);
      
      return memo[i][sum]= min(a,b);
      
      
  }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int tsum=0;
	    for(int i=0;i<n;i++)tsum+=arr[i];
	    memo.resize(n,vector<int>(tsum+1,-1));
	    return helper(arr,0,n,0,tsum);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends