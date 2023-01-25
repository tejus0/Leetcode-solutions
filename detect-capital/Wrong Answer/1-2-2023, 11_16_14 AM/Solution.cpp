// https://leetcode.com/problems/detect-capital

class Solution {
public:
    bool detectCapitalUse(string word) {
        int low=0 , up=0;
        int flag=1;
        int first=int(word[0]);
        int second=word[1];
        if(first>90 and second>90)  low=1;
        else if(first<=90 and second>90)  low=1;
        else if(first<=90 and second<=90) up=1;
        else  {
            flag=0;
            return flag;
        }
        for(int i=2;i<word.length();i++){
            if((low and word[i]<=90) or (up and word[i]>90)){
                flag=0;
                break;
            } 
        }
        return flag;
    }
};