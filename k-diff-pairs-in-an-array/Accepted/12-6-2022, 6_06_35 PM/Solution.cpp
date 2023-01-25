// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;
        for (int n: nums) ++cnts[n];
        int total = 0;
        for (auto p: cnts) if ((k > 0 && cnts.find(p.first + k) != cnts.end()) || (k == 0 && p.second > 1)) ++total;
        return total;
    }
};