class Solution {
private:
    bool compare(string &s, string &t, unordered_map<char,int> &map) {
        int n = s.size();
        int m = t.size();
        int i=0,j=0;
        
        while(i<n && j<m) {
            int index_i = map[s[i]];
            int index_j = map[t[j]];
            if(index_i>index_j)
                return false;
            else if(index_i<index_j)
                return true;
            else {
                i++;
                j++;
            }
        }
        
        if(i<n)
            return false;
        if(j<m)
            return true;
        
        return true;
        
        
    }
    
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>map;
        for(int i=0;i<order.size();i++) {
            map[order[i]] = i;
        }
        
        int n = words.size();
        
        for(int i=0,j=(i+1);i<(n-1),j<n;i++,j++) {
            if(!compare(words[i],words[j],map))
                return false;
        }
        return true;
    }
};