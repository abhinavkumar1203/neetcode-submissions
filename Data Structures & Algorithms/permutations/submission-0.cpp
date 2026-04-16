class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> pick(nums.size(), false);
        vector<int> perm;

        rec(nums,pick,perm);
        return res;
    }
        void rec(vector<int>& nums,vector<bool>& pick,vector<int> perm){
            if(perm.size() == nums.size()){
                res.push_back(perm);
                return;
            }
            
            for(int i=0;i<nums.size();i++){
                if(!pick[i]){
                perm.push_back(nums[i]);
                pick[i] = true;
                rec(nums,pick,perm);
                perm.pop_back();
                pick[i] = false;
                }
            }
        }
};
