// https://leetcode.com/problems/bulls-and-cows

class Solution {
public:
    string getHint(string secret, string guess) {
        int n= secret.length();
        int secFreq[10]={0};
        int guessFreq[10]={0};
        int bulls=0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]) bulls++;
            else{
                secFreq[secret[i]-'0']++;
                guessFreq[guess[i]-'0']++;
            }
        }
        int cows=0;
        for(int i=0;i<10;i++){
          cows += min(secFreq[i],guessFreq[i]);
        }
        string ans= to_string(bulls)+'A'+to_string(cows)+'B';
        return ans;
    }
};