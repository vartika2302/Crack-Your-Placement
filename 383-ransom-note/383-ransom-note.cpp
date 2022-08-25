class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>ump;
        for(auto ch: magazine) {
            ump[ch]++;
        }
        for(auto ch: ransomNote) {
            ump[ch]--;
        }
        for(auto it=ump.begin();it!=ump.end();it++){
            if((*it).second<0) return false;
        }
        return true;
    }
};