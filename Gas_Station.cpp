// author: Ian
// create on: 2017-02-24
// email: stmayue@gmail.com
// description: Gas Station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() != cost.size()) {
            return -1;
        }
        int total = 0;
        int sum = 0;
        int start_pos = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += (gas[i] - cost[i]);
            if (sum < 0) {
                sum = gas[i] - cost[i];
                start_pos = i;
            } else {
                sum += (gas[i] - cost[i]);
            }
        }
        if (total >= 0) {
            return start_pos;
        } else {
            return -1;
        }
    }
};