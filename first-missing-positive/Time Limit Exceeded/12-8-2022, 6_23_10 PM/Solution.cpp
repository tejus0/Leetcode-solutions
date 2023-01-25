// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int current=nums[i];
            if(nums[i]>0 && nums[i]<=n){
                if(nums[nums[i]-1]!=nums[i]){
                    swap(nums[nums[i]-1],nums[i]);
                    i--;
                }
            }
            for(auto ut :nums){
            cout<<ut<<" ";
        }
        cout<<endl;
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            int current=nums[i];
            if(current!=i+1){
                ans=i+1;
                //cout<<ans;
                break;
            }
        }
        if(ans==0){
           // cout<<ans;
            ans=n+1;
        }
        return ans;
    }
};