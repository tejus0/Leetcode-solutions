// https://leetcode.com/problems/flip-string-to-monotone-increasing

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones=0, zeroes=0, firstz , flag=0;
        for(char& c : s ){
            if(c=='1' and !flag){ 
                firstz=zeroes;
                flag=1;
            }
            else if(c=='1') ones++;
            else zeroes++;
        }
        return min(zeroes-firstz, ones+1);
    }
};