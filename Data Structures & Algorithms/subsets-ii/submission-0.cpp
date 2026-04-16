class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> res;
        vector<int> sub;
        rec(nums,res,sub,0);
        return vector<vector<int>>(res.begin(), res.end());
    }
private:
    void rec(const vector<int>& nums, set<vector<int>>& res, vector<int>& sub, int i){
        if(i == nums.size()){
            res.insert(sub);
            return;
        }
        sub.push_back(nums[i]);
        rec(nums, res, sub, i+1);
        sub.pop_back();
        rec(nums, res, sub, i+1);
    }
};
