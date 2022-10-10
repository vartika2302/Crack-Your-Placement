class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0, prod=1;
        while(n) {
            int digit = n%10;
            sum+=digit;
            prod*=digit;
            n/=10;
        }
        return prod-sum;
    }
};