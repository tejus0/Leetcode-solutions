// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int arrows=1 , max_d=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>max_d){
                arrows++;
                max_d=points[i][1];
            }
        }
        return arrows;
    }
};