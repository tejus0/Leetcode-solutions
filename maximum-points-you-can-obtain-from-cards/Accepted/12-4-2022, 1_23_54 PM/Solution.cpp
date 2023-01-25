// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int ans = 0;
        int curr = 0;
        int a = n-k;
        for (int i = a; i < n; i++)
        {
            curr = curr + cardPoints[i];
        }
        ans = max(ans,curr);
        for(int i = 0 ; i<k ; i++)
        {
            curr = curr + cardPoints[i] - cardPoints[a+i];
            ans = max(ans,curr);
        }
        return ans;
    }
};