class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(),piles.end());
        int ans = 1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;

            int totalTime = 0;
            for(auto p:piles){
                totalTime += ceil(static_cast<double>(p)/mid);
            }
            if(totalTime<=h){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};
