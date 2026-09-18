class Solution {
public:

    int accumulate(vector<int>& nums) {
        int sum = 0;
        for(int n: nums) sum += n;

        return sum;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas) < accumulate(cost)) {
            return -1;
        }

        int n = gas.size(), res = 0, total = 0;

        for(int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            if(total < 0) {
                total = 0;
                res = i + 1;
            }
        }

        return res;
    }
};