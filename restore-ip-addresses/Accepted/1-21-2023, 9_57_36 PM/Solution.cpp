// https://leetcode.com/problems/restore-ip-addresses

class Solution {
public:

     bool isValid(string str) {
        if (str[0] == '0') return false;
        return stoi(str) <= 255;
    }

    void solve(string& s, int ind, int k,string ans, vector<string>& res){
        if(k==4 ){
            if(ind==s.length()){
                ans.pop_back();
                res.push_back(ans);
            }
            return;
        }
        solve(s,ind+1,k+1,ans+s[ind]+".",res);
        for(int i=2;i<=3;i++){
            if(ind+i<=s.length() and isValid(s.substr(ind,i)))
                solve(s,ind+i,k+1,ans+s.substr(ind,i)+".",res);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        solve(s,0,0,"",res);
        return res;
    }
};
