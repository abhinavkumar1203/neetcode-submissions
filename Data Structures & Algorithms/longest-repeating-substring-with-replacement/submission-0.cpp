class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0;
        unordered_set<char> charSet;
        for(auto v:s){
            charSet.insert(v);
        }
        for(auto c:charSet){
            int l = 0;
            int gCount = 0;
            for(int r=0;r<s.length();r++){
                if(s[r]==c){
                    gCount++;
                }
                while((r-l+1)-gCount>k){
                    if(s[l]==c){
                        gCount--;
                    }
                    l++;
                }
                res = max(res,r-l+1);
            }
        }
        return res;
    }
};
