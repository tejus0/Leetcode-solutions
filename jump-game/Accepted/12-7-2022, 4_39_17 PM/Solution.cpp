// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        int reached=0;
        for(int i=0;i<n;i++){
            int check_btw=i+nums[i];
            if(reached<i)
                return false;
            reached=max(reached,check_btw);
        }
        return true;
    }
};