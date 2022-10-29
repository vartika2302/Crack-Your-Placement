class Solution {
private:
    static bool compare(pair<int,int>& p1, pair<int,int>& p2) {
        return p1.second>p2.second;
    }
    
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int minDaysToBloom = INT_MIN;
        vector<pair<int,int>>time;
        int n = plantTime.size();
        for(int i=0;i<n;i++) {
            time.push_back({plantTime[i],growTime[i]});
        }
        
        sort(time.begin(),time.end(),compare);
        
        int start=0;
        for(int i=0;i<n;i++) {
            minDaysToBloom = max(minDaysToBloom,start+time[i].first+time[i].second);
            start=start+time[i].first;
        }
        return minDaysToBloom;
    }
};