class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l =0;
        int r = nums.size()-1;
        int pivot;
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid]>nums[r]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        pivot = l;
        int result = binarySearch(nums,target,0,pivot-1);
        if(result!=-1) return result;
        return binarySearch(nums,target,pivot,nums.size()-1);
    }
        int binarySearch(vector<int>&nums,int target, int left, int right){
            while(left<=right){
                int mid = left+(right-left)/2;
                if(nums[mid]==target){
                    return mid;
                }
                else if(nums[mid]<target){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
            return -1;
        }
    };
