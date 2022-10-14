//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int arr[], int n) 
    {
        // Complete the function
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int sum=0;
        for(int i=n-1;i>=0;i--){
            if(mp.count(arr[i])){
                sum+=arr[i];
                mp[arr[i]]--;
                if(mp[arr[i]]==0)mp.erase(arr[i]);
                if(mp.count(arr[i]-1)){
                    mp[arr[i]-1]--;
                     if(mp[arr[i]-1]==0)mp.erase(arr[i]-1);
                }
            }
        }
        return sum;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends