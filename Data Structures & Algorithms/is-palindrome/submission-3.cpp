class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> v;

        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])) {
                v.push_back(tolower(s[i]));
            }
        }

        int lo = 0;
        int hi = v.size() - 1;

        while(lo < hi){
            if(v[lo] != v[hi]){
                return false;
            }
            lo++;
            hi--;
        }

        return true;
    }
};