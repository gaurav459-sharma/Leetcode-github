//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        vector<int>frq(26,0);
        for(auto it:s)frq[it-'a']++;
        int ct=INT_MAX;
        for(int i=0;i<26;i++){
            if(i==0||i==1||'a'+i=='n')ct=min(ct,frq[i]);
            else if('a'+i=='l'||'a'+i=='o')ct=min(ct,frq[i]/2);
        }
        return ct;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends