//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
         stack<string>chars;
        stack<int>nums;
        int num=0;
        string res="";
        
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                num=num*10 +(s[i]-'0');
            }
            else if(isalpha(s[i])){
                res+=s[i];
            }
            else if(s[i]=='['){
                chars.push(res);
                nums.push(num);
                res="";
                num=0;
            }
            else if(s[i]==']'){
                string tmp=res;
                for(int j=0;j<nums.top()-1;j++){
                    res+=tmp;
                }
                res=chars.top()+res;
                chars.pop();
                nums.pop();
            }
                
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends