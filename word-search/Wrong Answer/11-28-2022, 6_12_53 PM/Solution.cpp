// https://leetcode.com/problems/word-search

class Solution {
public:
    bool search(vector<vector<char>>& board,int index,int i, int j,string word){
        if(index==word.size()){
            return true;
        }
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size()) return false;
        bool up,down,right,left;
        if(word[index]==board[i][j]){
            up=search(board,index,i-1,j,word);
            down=search(board,index,i+1,j,word);
            left=search(board,index,i,j-1,word);
            right=search(board,index,i,j+1,word);
        }
        
        if(up||right||left||down) return true;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int index=0;
        int m= board.size();
        int n= board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;i++){
                 if(board[i][j]==word[index]){
                     if(search(board,index,i,j,word)){
                         return true;
                     }
                 }
            }
        }
        return false;
    }
};