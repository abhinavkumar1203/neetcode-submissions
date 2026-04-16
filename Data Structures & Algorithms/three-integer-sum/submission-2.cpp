class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;

            int lo = i+1;
            int hi = n-1;

            while(lo<hi){
            int sum = nums[lo]+nums[hi]+nums[i];
                if(sum == 0){
                    ans.push_back({nums[lo],nums[hi],nums[i]});
                    lo++;
                    hi--;
                    while(lo<hi && nums[lo]==nums[lo-1]) lo++;
                }
                else if(sum>0){
                    hi--;
                }
                else{
                    lo++;
                }
            }
        }
        return ans;
    }
};
