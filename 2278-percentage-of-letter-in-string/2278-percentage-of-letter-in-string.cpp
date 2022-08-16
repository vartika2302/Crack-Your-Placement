class Solution {
public:
    int percentageLetter(string s, char letter) {
        int freq=0;
        for(auto it: s){
            if(it==letter) freq++;
        }
        int ans = (double)(freq*100)/s.size();
        int floor_ans = floor(ans);
        int ceil_ans = ceil(ans);
        cout<<ans<<" "<<floor_ans<<" "<<ceil_ans<<endl;
        if(abs(floor_ans-ans)>abs(ceil_ans-ans)) {
            return ceil_ans;
        }
        return floor_ans;
    }
};