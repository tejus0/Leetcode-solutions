// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int first=0,second=0;
        int i=0,j=0;
        for( i=0;i<nums.size();i++){
            int temp=target-nums[i];
             first=i;
            for( j=i;j<nums.size();j++){
                if(nums[j]==temp){
                    second=j;
                    break;
                }
            }
            if(second!=0){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
        
        return ans;
    }
};