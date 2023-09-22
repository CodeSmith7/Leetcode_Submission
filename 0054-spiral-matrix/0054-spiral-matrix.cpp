class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int minr = 0, minc = 0;
        int  maxr = matrix.size() -1;
        int maxc = matrix[0].size() -1;
        int tne = matrix.size() * matrix[0].size();
        int count = 0;
        vector<int> ans;
        while(count < tne ){
            //top 
            for (int i = minr,j=minc;j <= maxc && count < tne ;j++){
                ans.push_back(matrix[i][j]);
                count++;
            }
            minr++;
            //right
            for (int i = minr,j=maxc;i <= maxr && count < tne ;i++){
                ans.push_back(matrix[i][j]);
                count++;
            }
            maxc--;
            //down 
            
            for (int i = maxr,j=maxc ;j >= minc && count < tne ;j--){
                ans.push_back(matrix[i][j]);
                count++;
            }
            maxr--;
            //left
            
            for (int i = maxr,j=minc;i >= minr && count < tne ;i--){
                ans.push_back(matrix[i][j]);
                count++;
            }

            minc++;
        }
        return ans ;
    }
};