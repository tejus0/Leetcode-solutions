// https://leetcode.com/problems/rotate-function

class Solution {
public:

    int func(vector<int>& a, int ind){
        if(ind<0) return 0;
        return ind*a[ind] + func(a,ind-1);
    }

    int maxRotateFunction(vector<int>& nums) {
        int sum= 0;
        int n= nums.size();
        int fi = func(nums,n-1);
        int ans=fi;
        cout<<fi<<" ";
        sum=accumulate(nums.begin(),nums.end(),0);
        for(int i=n-1;i>=0;i--){
            fi=fi+sum-n*nums[i];
            ans= max(ans,fi);
        }
        return ans;
    }
};