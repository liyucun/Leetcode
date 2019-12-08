class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> ans;
        int *temp = new int[nums.size()]();
        backtracking(results, ans, nums, temp);
        return results;
    }

    void backtracking(vector<vector<int>>& results, vector<int>& ans, vector<int>& nums, int* temp){
        if(ans.size() == nums.size()){
            results.push_back(ans);
            return;
        }
        for(int j = 0; j < nums.size(); j++){
            if(temp[j]!= 1){
                temp[j] = 1;
                ans.push_back(nums[j]);
                backtracking(results, ans, nums, temp);
                ans.pop_back();
                temp[j] = 0;
            }
        }
    }
};
