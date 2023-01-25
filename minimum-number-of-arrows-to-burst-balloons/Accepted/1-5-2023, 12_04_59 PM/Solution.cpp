// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int arrows=1, max_d=points[0][1];
        for(auto& it: points ){
            (!(it[0]>max_d)) ? :(arrows++,max_d=it[1]);
        }
        return arrows;
    }
};