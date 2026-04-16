class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> temp;
        for (int i = 0; i < nums.size(); i++) {
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end());
        int lo = 0, hi = temp.size() - 1;
        while (lo < hi) {
            int sum = temp[lo].first + temp[hi].first;
            if (sum == target) {
                return {min(temp[lo].second, temp[hi].second),
                        max(temp[lo].second, temp[hi].second)};
            } else if (sum > target) {
                hi--;
            } else
                lo++;
        }
        return {};
    }
};
