class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1="",str2="";
        for(auto &x: word1)
            str1+=x;
        for(auto &x: word2)
            str2+=x;
        return str1==str2;
    }
};