// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0, j=n-1;
        int diff=1,area=0, ans=INT_MIN;
        while(i<j){
            int diff=j-i;
            int area=diff*(min(height[i],height[j]));
           // cout<<area<<" ";
            ans=max(ans,area);
            //cout<<ans<<" ";
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};