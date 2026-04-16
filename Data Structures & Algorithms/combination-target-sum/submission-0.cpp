class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        rec(nums,res,comb,target,0);
        return res;
    }
private:
    void rec(vector<int>& nums,vector<vector<int>>& res, vector<int>& comb, int target, int i){
        //basecase
        if(target == 0){
            res.push_back(comb);
            return;
        }
        if(target<0 || i>=nums.size()){
            return;
        }
        
        comb.push_back(nums[i]);
        rec(nums,res, comb, target-nums[i], i);
        comb.pop_back();
        rec(nums,res, comb, target, i+1);
    }
};
