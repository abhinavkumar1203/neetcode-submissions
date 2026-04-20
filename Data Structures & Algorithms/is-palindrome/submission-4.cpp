class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> temp;
        for(auto v:s){
            if(isalnum(v)){
                temp.push_back(tolower(v));
            }
        }
        int lo = 0;
        int hi = temp.size()-1;
        while(lo<=hi){
            if(temp[lo] == temp[hi]){
                lo++;
                hi--;
            }
            else{
                return false;
                break;
            }
        }
        return true;
    }
};







