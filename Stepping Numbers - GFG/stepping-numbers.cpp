//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    int steppingNumbers(int n, int m)
    {
        // Code Here
        queue<int>pq;
        for(int i=1;i<=9;i++){
            pq.push(i);
        }
        int ct=0;
        while(!pq.empty()){
            int num=pq.front();
            pq.pop();
            // cout<<num<<" ";
            if(num>=n &&num<=m)ct++;
            
            if(num%10==0&&num*10+1<=m){
                pq.push(num*10+1);
                //  cout<<"e "<<num*10+8<<endl;
            }
            else if(num%10==9 &&num*10+8<=m){
                pq.push(num*10+8);
                // cout<<"f "<<num*10+8<<endl;
            }
            else if(num%10!=0&&num%10!=9){
                int p=num*10;
                int rem=num%10;
                //  cout<<"g "<<p+rem<<endl;
                if(p+rem-1<=m)pq.push(p+rem-1);
                if(p+rem+1<=m)pq.push(p+rem+1);
            }
        }
        if(n==0)ct++;
        return ct;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends