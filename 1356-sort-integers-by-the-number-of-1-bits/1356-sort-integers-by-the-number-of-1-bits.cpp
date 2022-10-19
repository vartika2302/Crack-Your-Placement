class Solution {
private:
    static bool compare(int a, int b) {
        int bits_a = 0, bits_b = 0;
        int temp_a = a, temp_b = b;
        while(temp_a) {
            int bit = temp_a&1;
            if(bit)
                bits_a++;
            temp_a = temp_a>>1;
        }
        while(temp_b) {
            int bit = temp_b&1;
            if(bit)
                bits_b++;
            temp_b = temp_b>>1;
        }
        if(bits_a==bits_b)
            return a<b;
        return bits_a<bits_b;
        
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};