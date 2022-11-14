//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string s, string w){
        // code here 
        int res=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==w[0]){
                int j=i;
                int k=0;
                while(j<s.length()&&k<w.length()){
                    if(s[j]==w[k]){
                        s[j]='*';
                        k++;
                    }
                    j++;
                }
                if(k==w.length())res++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends