//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
    int findSum(int arr[], int n)
    {
    	//code here.
    	int maxn=INT_MIN;
    	int minn=INT_MAX;
    	for(int i=0;i<n;i++){
    	    minn=min(minn,arr[i]);
    	    maxn=max(maxn,arr[i]);
    	}
    	return minn+maxn;
    }

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends