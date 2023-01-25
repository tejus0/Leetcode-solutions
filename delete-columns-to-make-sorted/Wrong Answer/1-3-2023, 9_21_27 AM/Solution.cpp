// https://leetcode.com/problems/delete-columns-to-make-sorted

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs[0].length();
        string col=strs[0];
        int ans=0;
        for(int i=1;i<strs.size();i++){
            //cout<<"Here10";
                if(strs[i].compare(col)>0){
                    cout<<"here";
                    ans++;
                    n--;
                }
            col=strs[i];
        }
        return strs[0].length()-ans;
    }
};