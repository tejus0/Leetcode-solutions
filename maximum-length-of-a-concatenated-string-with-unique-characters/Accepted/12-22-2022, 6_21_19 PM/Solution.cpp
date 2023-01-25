// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters

class Solution {
public:
    
    int maxi = 0;
    
    // function for checking uniqueness of the string
    
    bool is_unique(string& str, vector<int>& prev)
    {
        int n = str.size();
        
        // mp will store the count of all the characters in string
        
        vector<int> mp(26, 0);
        for(int i = 0; i < n; i++)
        {
            // if we found duplicates return false
            if(mp[str[i] - 'a'] > 0)
                return false;
            mp[str[i] - 'a']++;
        }
        for(int i=0;i<n;i++){
            if(prev[str[i]-'a']) return false;
        }
        return true;
    }
    
    int helper(vector<string>& arr, vector<int>& prev, int i, int n)
    {
        if(arr.size()==i){
            return n;
        }
        // if we have got duplicate int our result then simply return
        string current=arr[i];
        if(is_unique(current,prev) == false)
            return helper(arr,prev,i+1,n);
        
        
        // we have two options either include the curr string or exclude
        
        // include the curr string
        else{
            for(int i=0;i<current.size();i++){
                prev[current[i]-'a']++;
            }
        n += current.size();
        int acc=helper(arr,prev, i + 1, n);
        
        // exclude the curr string
        for(int i=0;i<current.size();i++){
                prev[current[i]-'a']--;
            }
        n -= current.size();
        int rjct=helper(arr,prev, i + 1, n);
        return max(acc,rjct);
        }
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> current(26,0);
        return helper(arr,current, 0, 0);
    }
};