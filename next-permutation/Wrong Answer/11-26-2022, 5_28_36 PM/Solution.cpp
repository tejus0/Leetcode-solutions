// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int peak=-1;
        int n=nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                peak=i;
                break;
            }
        }
        if(peak==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            int swappy=peak;
            for(int i=peak;i<n;i++){
                if(nums[peak-1]<nums[i] and nums[i]<nums[swappy]){
                    swappy=i;
                    //cout<<swappy<<" ";
                }
            }
            //cout<<peak-1<<" ";
            swap(nums[peak-1],nums[swappy]);
            reverse(nums.begin()+peak,nums.end());
        }
    }
};