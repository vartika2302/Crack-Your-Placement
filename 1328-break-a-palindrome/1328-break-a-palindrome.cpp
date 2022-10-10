class Solution {
private:
    bool isPalindrome(string str) {
        int n = str.size();
        if(n<=1) return true;
        int i=0;
        int j=n-1;
        while(i<j) {
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n<=1) return "";
        for(int i=0;i<n;i++) {
            if(palindrome[i]!='a') {
                char temp_char = palindrome[i];
                palindrome[i]='a';
                if(isPalindrome(palindrome)) {
                    palindrome[i] = temp_char;
                    break;
                }else {
                    return palindrome;
                }
            }
        }
        char ch='b';
        while(ch<='z') {
            if(palindrome[n-1]!=ch) {
                palindrome[n-1] = ch;
                break;
            }
            ch++;
        }
        return palindrome;
    }
};