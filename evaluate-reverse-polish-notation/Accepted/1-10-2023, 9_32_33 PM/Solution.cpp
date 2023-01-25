// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==1) return stoi(tokens[0]);
        stack<int> numbers;
        int a, b;
        for(int i=0;i<tokens.size();i++){
            string curr=tokens[i];
            if(curr=="*"){
                b= numbers.top();
                numbers.pop();
                a = numbers.top();
                numbers.pop();
                numbers.push(a*b);
            }
            else if(curr == "-") {
                b= numbers.top();
                numbers.pop();
                a = numbers.top();
                numbers.pop();
                numbers.push(a-b);
                }
            else if (curr=="+") {
                b= numbers.top();
                numbers.pop();
                a = numbers.top();
                numbers.pop();
                numbers.push(a+b);}
            else if ( curr=="/") {
                b= numbers.top();
                numbers.pop();
                a = numbers.top();
                numbers.pop();
                numbers.push(a/b);}
            else{ 
                numbers.push(stoi(curr));
            }
        }
        int ans= numbers.top();
        numbers.pop();
        return ans;
    }
};