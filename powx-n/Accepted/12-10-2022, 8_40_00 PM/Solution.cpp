// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long n_copy=n;
        if(n_copy<0)   n_copy = -1* n_copy;
        while(n_copy>0){
            if(n_copy%2){
                ans=ans*x;
                n_copy--;
            }
            else{
                x *= x;
                n_copy /=2;
            }
        }
        if(n<0) ans= (1.0) / (ans);
        return ans;
    }
};