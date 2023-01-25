// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        int k=1;
        int ans=0;
        while(n>=pow(5,k)){
           ans += n/pow(5,k);
           k++;

        }
        return ans;
    }
};