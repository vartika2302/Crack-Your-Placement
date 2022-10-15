class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n==1) return 1;
        int temp_cnt=1;
        vector<char> out_chars;
        for(int i=1;i<chars.size();i++) {
            if(chars[i-1]==chars[i]) 
                temp_cnt++;
            else {
                out_chars.push_back(chars[i-1]);
                if(temp_cnt>1 && temp_cnt<10)
                    out_chars.push_back(char(temp_cnt+'0'));
                else if(temp_cnt>=10) {
                    vector<char>temp;
                    while(temp_cnt) {
                        temp.push_back(char((temp_cnt%10)+'0'));
                        temp_cnt/=10;
                    }
                    for(int i=temp.size()-1;i>=0;i--) {
                        out_chars.push_back(temp[i]);
                    }
                }
                temp_cnt=1;
            }
        }
        out_chars.push_back(chars[n-1]);
        if(temp_cnt>1 && temp_cnt<10)
            out_chars.push_back(char(temp_cnt+'0'));
        else if(temp_cnt>=10) {
                    vector<char>temp;
                    while(temp_cnt) {
                        temp.push_back(char((temp_cnt%10)+'0'));
                        temp_cnt/=10;
                    }
                    for(int i=temp.size()-1;i>=0;i--) {
                        out_chars.push_back(temp[i]);
                    }
                }
        chars = out_chars;
        return chars.size();
    }
};