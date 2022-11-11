//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    void sieve(vector<bool>&prime,int n){
        
        for(int i=2;i<=sqrt(n);i++){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=false;
            }
        }
    }
    
    string isSumOfTwo(int n){
        // code here
        vector<bool>arr(n+1,true);
        sieve(arr,n);
        // for(int i=0;i<=n;i++)cout<<arr[i]<<" ";
        int i=2;
        int j=n;
        while(i<=j){
            // cout<<i<<" "<<j<<endl;
            if(!arr[i])i++;
            else if(!arr[j])j--;
            else{
            if(i+j==n)return "Yes";
            else if(i+j<n)i++;
            else j--;
            }
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends