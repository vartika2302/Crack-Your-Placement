class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        vector<pair<int,int>>v;
        for(int i=0;i<s1.size();i++) {
            if(s1[i]!=s2[i]) {
                if(v.size()==2) 
                    return false;
                v.push_back({s1[i],s2[i]});
            }
        }
        if(v.size()==1) return false;
        if(v[0].first==v[1].second && v[0].second==v[1].first) 
            return true;
        return false;
    }
};