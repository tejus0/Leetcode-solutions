// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            left[i] = left[i - 1] * nums[i - 1];
        }
        
        right[n - 1] = 1;
        for (int j = n - 2; j >= 0; j--) {
            right[j] = right[j + 1] * nums[j + 1];
        }
        
        for (int k = 0; k < n; k++) {
            ans[k]= left[k] * right[k];
        }
        
        return ans;
    }
};