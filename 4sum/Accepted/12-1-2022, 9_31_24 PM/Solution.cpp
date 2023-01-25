// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long target) {
        vector<vector<int>> ans;
        if(nums.empty()) return ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
    
        for(int i=0;i<n;i++){
            //cout<<'here'<<endl
               // first=nums[i];
               // int rem1=target-first;
                
                for(int j=i+1;j<n;j++){
                    long long int second=target-nums[i]-nums[j];
                      //  int rem2=second;
                        int k=j+1;
                        int l=n-1;
                        while(k<l){
                            if(nums[k]+nums[l]==second){
                                vector<int> quad(4,0);
                                    quad[0]=nums[i];
                                    quad[1]=nums[j];
                                    quad[2]=nums[k];
                                    quad[3]=nums[l];
                                ans.push_back(quad);
                                while(k<l and nums[k]==quad[2]) k++;
                                while(k<l and nums[l]==quad[3]) l--;
                            }
                            else if(nums[k]+nums[l]>second){
                                l--;
                            }
                            else{
                                k++;
                            }
                        }
                    while(j+1<n and nums[j+1]==nums[j]) j++;
                    }
                 while(i+1<n and nums[i+1]==nums[i]) i++;
        }
        return ans;
    }
};