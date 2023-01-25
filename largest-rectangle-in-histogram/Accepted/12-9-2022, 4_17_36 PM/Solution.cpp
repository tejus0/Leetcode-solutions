// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:

    vector<int> nsr(vector<int>& heights, int n){
        vector<int> next_s;
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) {
                next_s.push_back(n);
            }
            else{
                next_s.push_back(st.top());
            }
            st.push(i);
        }
        reverse(next_s.begin(),next_s.end());
        return next_s;
    }

    vector<int> nsl(vector<int>& heights, int n){
        vector<int > prev_s;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) {
                prev_s.push_back(-1);
            }
            else{
                prev_s.push_back(st.top());
            }
            st.push(i);
        }
        return prev_s;
}
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> v_nsl=nsl(heights,n);
        vector<int> v_nsr=nsr(heights,n);
        //for(auto it: v_nsr) cout<<it<<' ';
        int max_area=INT_MIN;
        for(int i=0;i<n;i++){
            max_area=  max((v_nsr[i]-v_nsl[i]-1)* heights[i],max_area) ;   
            //cout<<max_area<<" ";
        }
        return max_area;
    }
};