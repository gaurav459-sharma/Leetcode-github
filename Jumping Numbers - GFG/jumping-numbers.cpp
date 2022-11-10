//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

    long long jumpingNums(long long X) {
        // code here
        queue<long long>q;
        int t=X;
        while(t>10)t/=10;
        for(int i=1;i<=t;i++)q.push(i);
        long long ans=0;
        while(!q.empty()){
            long long num=q.front();
            q.pop();
            if(num>X)break;
            ans=max(ans,num);
            
            int ld=num%10;
            if(ld!=0){
                q.push(num*10+ld-1);
            }
            if(ld!=9){
                q.push(num*10+ld+1);
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends