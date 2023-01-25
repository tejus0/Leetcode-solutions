// https://leetcode.com/problems/divisor-game

class Solution {
public:

    bool solve(int n){
        if(n==1) return false;
        for(int i=1;i<n;i++){
            if(n%i==0){
                if(!solve(n-i)) return true;
            }
        }
        return 0;
    }

    bool divisorGame(int n) {
        return solve(n);
    }
};