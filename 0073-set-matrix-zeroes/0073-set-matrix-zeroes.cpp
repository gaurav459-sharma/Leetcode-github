class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>tmp=mat;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    for(int k=0;k<n;k++){
                        tmp[i][k]=0;
                    }
                    for(int k=0;k<m;k++){
                        tmp[k][j]=0;
                    }
                }
            }
        }
        mat=tmp;
    }
};