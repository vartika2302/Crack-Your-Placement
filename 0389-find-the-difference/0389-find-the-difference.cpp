class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>map;
        int ns = s.size();
        int nt = t.size();
        for(int i=0;i<ns;i++) {
            map[s[i]]++;
        }
        for(int i=0;i<nt;i++) {
            if(!map[t[i]]) return t[i];
            map[t[i]]--;
        }
        return 'a';
    }
};