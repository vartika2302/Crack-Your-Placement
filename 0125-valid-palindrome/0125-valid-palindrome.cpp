class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(auto &el: s) {
            if((el>='a' && el<='z')||(el>='A' && el<='Z')||(el>='0' && el<='9')) 
                str+=el;
        }
        int i=0;
        int j=str.size()-1;
        transform(str.begin(),str.end(),str.begin(),::tolower);
        while(i<j) {
            if(str[i]!=str[j]) 
                return false;
            i++;
            j--;
        }
        return true;
    }
};