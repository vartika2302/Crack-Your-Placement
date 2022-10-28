class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>map;
        for(auto &el: strs) {
            string temp = el;
            sort(temp.begin(),temp.end());
            map[temp].push_back(el);
        }
        
        for(auto &it: map)
            ans.push_back(it.second);
        
        return ans;
    }
};