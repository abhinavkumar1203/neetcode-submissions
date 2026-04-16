class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans=0;
        int lo = 0;
        int hi = heights.size()-1;
        while(lo<hi){
            int vol = min(heights[lo],heights[hi])*(hi-lo);
            ans = max(ans,vol);
            if(heights[lo]<=heights[hi])lo++;
            else hi--;
        }
        return ans;
    }
};
