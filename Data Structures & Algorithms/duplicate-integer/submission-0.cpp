class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();

        map<int,int> mp;
        for(auto v:nums){
            mp[v]++;
            if(mp[v]>1)return true;
        }
        return false;
    }
};