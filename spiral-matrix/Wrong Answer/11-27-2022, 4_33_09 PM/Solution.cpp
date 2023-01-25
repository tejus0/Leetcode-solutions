// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        int n= matrix[0].size();
        int start_col=0, end_col=n-1, start_row=0, end_row=m-1;
        while(start_col <=end_col and start_row<=end_row){
            for(int i=start_col;i<=end_col;i++){
                ans.push_back(matrix[start_row][i]);
            }
            start_row++;
            for(int i=start_row;i<=end_row;i++){
                ans.push_back(matrix[i][end_col]);
            }
            end_col--;
            if(end_row>start_row){
            for(int i=end_col;i>=start_col;i--){
                ans.push_back(matrix[end_row][i]);
            }
            end_row--;
            }
            if(end_col>start_col){
            for(int i=end_row;i>=start_row;i--){
                ans.push_back(matrix[i][start_col]);
            }
            start_col++;
            }
        }
        return ans;
    }
};