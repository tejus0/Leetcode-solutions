// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int temp;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }
            else{
            temp=nums[i-count];
            nums[i-count]=nums[i];
            nums[i]=temp;
            }
        }
    }
};