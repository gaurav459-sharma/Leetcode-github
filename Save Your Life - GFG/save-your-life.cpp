//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here
          unordered_map<char,int>mp;
          for(int i=0;i<n;i++){
              mp[x[i]]=b[i];
          }
          string mres="";
          int mv=INT_MIN;
          string tmp="";
          int mt=0;
          for(int i=0;i<w.size();i++){
              int val;
              if(mp.count(w[i])>0)val=mp[w[i]];
              else val=w[i];
              tmp+=w[i];
              mt+=val;
             
              if(val>mt){
                //   cout<<val<<endl;
                  mt=val;
                  tmp=w[i];
                //   cout<<tmp<<endl;
              }
              
             if(mt>mv){
                  mres=tmp;
                  mv=mt;
                //   cout<<tmp<<endl;
              }
              
          }
          return mres;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends