class Solution {
public:
    bool helper(vector<vector<int>>& matrix,int i,int j){
        int m=matrix.size();
        int n=matrix[0].size();
        int num=matrix[i][j];
        while(i<m &&j<n){
            if(matrix[i][j]!=num)return false;
            i++;
            j++;
        }
        return true;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<n;i++){
            bool ans=helper(matrix,0,i);
            if(!ans)return false;
        }
        for(int i=0;i<m;i++){
            bool ans=helper(matrix,i,0);
            if(!ans)return false;
        }
        return true;
    }
};