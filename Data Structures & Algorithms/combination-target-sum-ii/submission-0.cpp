class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> comb;
        rec(candidates, target, res, comb, 0);
        return res;
    }
private:
    void rec(vector<int>& candidates, int target, vector<vector<int>>& res,vector<int>& comb, int i){
        if(target == 0){
            res.push_back(comb);
            return;
        }
        if(target < 0 || i >= candidates.size()){
            return;
        }
        comb.push_back(candidates[i]);
        rec(candidates, target-candidates[i], res, comb, i+1);
        comb.pop_back();
        int j = i+1;
        while(j<candidates.size() &&  candidates[j] == candidates[i]){
            j++;
        }
        rec(candidates, target, res, comb, j);
    }
};
