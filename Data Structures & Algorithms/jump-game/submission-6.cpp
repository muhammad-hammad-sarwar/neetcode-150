class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i > reach) return false;
            reach = max(reach, i + nums[i]);
        }

        return true;
    }
};

// Why not dp? because i dont need to know where i came from
// i just need to reach the end that is all