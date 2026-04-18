// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> ans;
//         vector<pair<string,string>> sString;
//         for(int i=0;i<strs.size();i++){
//             string temp = sort(strs[i].begin(), strs[i].end());
//             sString.push_back({strs[i],temp});
//         }
//         sort(sString.begin(), sString.end(), [](const pair<string,string>& a, const pair<string,string>& b) {
//         return a.second < b.second;
//         }
//     );
//     for(int i=0;i<sString.size();i++){
//         while(sString[i].second == sString[i+1].second){
//             ans[i].push_back(sString[i].first);
//         }
//     }
//     return ans;
//     }
// };


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,string>> sString;

        // Step 1: store original + sorted
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            sString.push_back({strs[i], temp});
        }

        // Step 2: sort by sorted string
        sort(sString.begin(), sString.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<vector<string>> ans;

        // Step 3: group
        for (int i = 0; i < sString.size(); ) {
            vector<string> group;
            string key = sString[i].second;

            while (i < sString.size() && sString[i].second == key) {
                group.push_back(sString[i].first);
                i++;
            }

            ans.push_back(group);
        }

        return ans;
    }
};