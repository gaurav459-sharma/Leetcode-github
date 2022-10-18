//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>>arr)
	{
		// Your code goes herevect
		vector<int>res;
		for(int i=0;i<n;i++){
		    int r=0;
		    int c=i;
		    while(r<n&&c>=0){
		        res.push_back(arr[r][c]);
		        r++;
		        c--;
		    }
		}
		
		for(int i=1;i<n;i++){
		    int r=i;
		    int c=n-1;
		    while(r<n&&c>=0){
		        res.push_back(arr[r][c]);
		        r++;
		        c--;
		    }
		}
		return res;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends