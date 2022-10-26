//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    queue<char>pq;
		    vector<int>freq(26,0);
		    string res="";
		    for(int i=0;i<s.length();i++){
		        freq[s[i]-'a']++;
		        pq.push(s[i]);
		        while(!pq.empty()&&freq[pq.front()-'a']!=1){
		            pq.pop();
		        }
		        if(pq.empty()){
		            res+='#';
		        }
		        else{
		            res+=pq.front();
		        }
		        
		    }
		    return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends