class Solution {
    private:
    static bool compare(pair<char,int>p1,pair<char,int>p2) {
        return p1.second > p2.second;
    }
public:
    string frequencySort(string s) {
       map<char,int>mpp;
       for(auto it:s)
           mpp[it]++;
        vector<pair<char,int>>freq;
        for(auto it=mpp.begin();it!=mpp.end();it++) {
            freq.push_back({it->first,it->second});
        }
        sort(freq.begin(),freq.end(),compare);
        string res = "";
        for(int i=0;i<freq.size();i++) {
            while(freq[i].second>0) {
                res+=freq[i].first;
                freq[i].second--;
            }
        }
        return res;
    }
};