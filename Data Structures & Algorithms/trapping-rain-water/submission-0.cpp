class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int l = 0;
        int r = height.size()-1;
        int lMax = height[l];
        int rMax = height[r];
        int ans = 0;    

        while(l<r){
            if(lMax<rMax){
                l++;
                lMax = max(lMax,height[l]);
                ans += lMax - height[l];
            }
            else{
                r--;
                rMax = max(rMax,height[r]);
                ans += rMax - height[r];
            }
        }
        return ans;
    }
};
