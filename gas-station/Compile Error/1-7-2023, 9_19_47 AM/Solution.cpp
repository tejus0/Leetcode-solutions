// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot_gas=accumulate(gas.begin(),gas.end(),0);
        int tot_cost=acumulate(cost.begin(),cost.end(),0);
        if(tot_cost<tot_gas) return -1;
        int total=0;
        int n=cost.size();
        for(int i=0;i<n;i++){
            int gain=gas-cost;
            total +=gain;
            if(total<0){
                ans=i+1;
                total=0;
            }
        }
        return ans;
    }
};