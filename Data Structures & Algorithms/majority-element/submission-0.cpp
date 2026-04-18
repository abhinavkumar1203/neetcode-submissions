class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto v : nums){
            mp[v]++;
        }
        int ans = 0;
        for(auto e:mp){
            if(e.second > (nums.size()/2)){
                ans = e.first;
            }
        }
        return ans;
    }
};