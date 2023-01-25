// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> answer;
        vector<int> curr=intervals[0];
        for(auto it: intervals){
            if(it[0]<=curr[1]){
                curr[1]=max(it[1],curr[1]);
                
            }
            else{
                answer.push_back(curr);
                curr=it;
            }
        }
        answer.push_back(curr);
        return answer;
    }
};