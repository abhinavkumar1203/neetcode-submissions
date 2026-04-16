class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        map<char,int> mp;

        for(char c : s) mp[c]++;
        for(char c : t) mp[c]--;

        for(auto v : mp){
            if(v.second != 0) return false;
        }

        return true;
    }
};