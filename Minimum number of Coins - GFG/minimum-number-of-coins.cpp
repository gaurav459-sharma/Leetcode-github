//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int>ans;
        stack<int>st;
        st.push(1);
        st.push(2);
        st.push(5);
        st.push(10);
        st.push(20);
        st.push(50);
        st.push(100);
        st.push(200);
        st.push(500);
        st.push(2000);
        while(N && !st.empty()){
            if(st.top()>N){
                st.pop();
            }
            else{
                ans.push_back(st.top());
                N-=st.top();
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends