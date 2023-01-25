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
        for(int i=1;i<n;i++){
            x1 =points[i][0];
            if(x1>max_d){
                arrows++;
                max_d=points[i][1];
            }
        }
        return arrows;
    }
};