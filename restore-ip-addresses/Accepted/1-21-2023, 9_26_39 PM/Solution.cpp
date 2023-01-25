// https://leetcode.com/problems/restore-ip-addresses

class Solution {
public:

    bool isValid(string s){
        int val ;
        if(s[0]=='0') return false;
        val=stoi(s);
        cout<<val<<endl;
        return val<=255;
    }

    void solve(string s, int ind, int k,string ans, vector<string>& res){
        if(k==4){
            if(ind==s.length()){
                ans.pop_back();
                res.push_back(ans);
            }
            return;
        }
        for(int i=1;i<=3;i++){
            if (ind + i > s.length()) {
            break;
        }
        string sub = s.substr(ind, i);
        if (stoi(sub) <= 255 && (i == 1 || sub[0] != '0')) {
            ans += sub + '.';
            solve(s, ind + i, k + 1,ans, res);
            ans.erase(ans.end() - i - 1, ans.end());
        }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        solve(s,0,0,"",res);
        return res;
    }
};