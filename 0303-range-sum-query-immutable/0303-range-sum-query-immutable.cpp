class NumArray {
private:
    vector<int>v;
    
public:
    NumArray(vector<int>& nums) {
        v = nums;
    }
    
    int sumRange(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++) {
            ans+=v[i];
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */