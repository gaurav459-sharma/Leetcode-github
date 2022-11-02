class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
       unordered_set<string>mp;
        for(int i=0;i<bank.size();i++){
            mp.insert(bank[i]);
        }
        if(mp.find(end)==mp.end())return -1;
        queue<string>q;
        q.push(start);
        int ct=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                string curr=q.front();
                q.pop();
                if(curr==end)return ct;
                mp.erase(curr);
                for(int i=0;i<8;i++){
                string t=curr;
				t[i]='A';
				if(mp.count(t)) q.push(t);
				t[i]='C';
				if(mp.count(t)) q.push(t);
				t[i]='G';
				if(mp.count(t)) q.push(t);
				t[i]='T';
				if(mp.count(t)) q.push(t);
                }
            }
            ct++;
        }
           return -1;    
    }
};