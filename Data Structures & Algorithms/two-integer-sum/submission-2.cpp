class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int,int>> v;

        for(int i = 0; i < nums.size(); i++){
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.first < b.first;
        });

        int lo = 0;
        int hi = v.size() - 1;

        while(lo < hi){
            int sum = v[lo].first + v[hi].first;

            if(sum == target){
                return {min(v[lo].second, v[hi].second),
                        max(v[lo].second, v[hi].second)};
            }
            else if(sum > target){
                hi--;
            }
            else{
                lo++;
            }
        }

        return {};
    }
};