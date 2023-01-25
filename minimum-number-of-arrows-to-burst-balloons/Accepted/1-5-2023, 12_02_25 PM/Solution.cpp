// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int arrows=1, x1 , max_d=points[0][1];
        int n= points.size();
        for(auto it: points ){
            x1 =it[0];
            x1>max_d ? (arrows++,max_d=it[1]):arrows=arrows;
        }
        return arrows;
    }
};