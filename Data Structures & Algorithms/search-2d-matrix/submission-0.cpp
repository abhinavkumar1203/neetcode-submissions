class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> arr;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                arr.push_back(matrix[i][j]);
            }
        }

        int lo=0;
        int hi=arr.size()-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(arr[mid]==target){
                return true;
            }
            else if(arr[mid]>target){
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return false;
    }
};
