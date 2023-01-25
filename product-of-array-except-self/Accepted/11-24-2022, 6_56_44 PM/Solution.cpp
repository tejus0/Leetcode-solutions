// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        
        left[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            left[i] = left[i - 1] * nums[i - 1];
        }
        
        int right=1;
        for (int k = n-1; k >=0; k--) {
            left[k]= left[k] * right;
            right=right * nums[k];
        }
        
        return left;
    }
};