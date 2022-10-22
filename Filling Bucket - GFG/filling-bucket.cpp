//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int memo[100001];
  int mod=1e8;
  int helper(int N){
      if(N==1||N==2)return N;
        if(N<=0)return 0;
        if(memo[N]!=-1)return memo[N];
        int a=helper(N-1)%mod;
        int b=helper(N-2)%mod;
        return memo[N]=(a+b)%mod;
  }
    int fillingBucket(int N) {
        // code here
        memset(memo,-1,sizeof(memo));
        return helper(N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends