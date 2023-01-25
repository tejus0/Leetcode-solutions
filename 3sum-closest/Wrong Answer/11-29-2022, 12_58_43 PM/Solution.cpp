// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int j,k, temp;
        int sum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){ 
            j=i+1;
            k=n-1;
            while(j<k){
                temp=nums[i]+nums[j]+nums[k];
                if((target-temp) < (target-sum) ) 
                    sum=temp;
                if(temp>target)
                    k--;                  
                else if(temp<target)
                    j++;             
                else return target;
            }
        }
        return sum;
    }
};