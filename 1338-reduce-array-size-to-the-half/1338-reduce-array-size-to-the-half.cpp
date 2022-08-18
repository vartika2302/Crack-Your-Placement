class Solution {
public:
    int minSetSize(vector<int>& arr) {
       unordered_map<int,int>ump;
        int n = arr.size();
        for(int i=0;i<n;i++) {
            ump[arr[i]]++;
        }
        vector<pair<int,int>>temp;
        for(auto it=ump.begin();it!=ump.end();it++) {
            temp.push_back({(*it).second,(*it).first});
        }
        sort(temp.begin(),temp.end());
        int ans=0;
        int half = n/2;
        for(int i=temp.size()-1;i>=0;i--){
            if(n>half){
                n=n-temp[i].first;
                ans++;
            }
        }
        return ans;
    }
};