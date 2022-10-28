//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
		int NthTerm(int n){
		    // Code  here
		    int mod=1e9+7;
		  //  if(n==1)return 2;
		  //  long long ans=NthTerm(n-1)%mod;
		  
		  //  long long p=(long long)(ans*n+1ll)%mod;
		  //  return p;
		  int ans=2;
		  for(int i=2;i<=n;i++){
		      ans=((long long)ans*i+1ll)%mod;
		  }
		  return ans;
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends