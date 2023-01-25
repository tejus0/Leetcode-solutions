// https://leetcode.com/problems/two-sum

class Solution {
public:
    /* This function returns (true, index) if element is found otherwise
       it returns (false, -1)
    */
    int binary_search(std::vector<std::pair<int,int>>& a, int ind, int key) {
        int i = 0, j = a.size();
        while (i <= j) {
            int m = (i + j) / 2;
            if (a[m].first == key and m!=ind) {
                return a[m].second;
            } else if (a[m].first < key) {
                i = m + 1;
            } else {
                j = m - 1;
            }
        }
        return -1;
    }
    
    
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Making the nested list
        std::vector<std::pair<int,int>> a {};
        for (int i = 0; i < n; i++) {
            a.push_back(std::make_pair(nums[i], i));
        }
        
        // Sorting the array so that binary search can be used
        std::sort(a.begin(), a.end());
        
        // Finding the pair using binary search
        for (int i = 0; i < n; i++) {
            int key = target - a[i].first;
            int res = binary_search(a, i, key);
            
            // found the pair
            if (res !=-1) {
                return {a[i].second, res};
            }
        }
        
        /* This is written to avoid the compiler warning of not returning 
           anything from the function which has a return type of vector<int>
        */
        return {};
    }
};