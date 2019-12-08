class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int maxState = 0;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            maxState = max(nums[i], maxState);
            map[nums[i]] += nums[i];
        }
        vector<int> state(maxState+1, 0);
        state[1] = map[1];
        for(int i = 2; i <= maxState; i++){
            state[i] = max(state[i-1], state[i-2] + map[i]);
        }
        return state[maxState];
    }
};
