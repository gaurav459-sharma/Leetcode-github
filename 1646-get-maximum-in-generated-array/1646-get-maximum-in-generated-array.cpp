class Solution {
public:
    int getMaximumGenerated(int n) {
     
        vector<int>res(n+1);
        if(n==0)return 0;
        res[0]=0;
        res[1]=1;
        int m=1;
        for(int i=2;i<n+1;i++){
            if(i%2==0){
                res[i]=res[i/2];
            }
            else{
                int p=i-1;
                p=p/2;
                res[i]=res[p]+res[p+1];
            }
            m=max(m,res[i]);
        }
        return m;
    }
};