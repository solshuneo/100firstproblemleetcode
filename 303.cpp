class NumArray {
    public:
        vector<int> nums;
        NumArray(vector<int>& nums) {
            this->nums = nums;
        }
        
        int sumRange(int left, int right) {
            int res = 0;
            for (; left <= right; ++left) res += this->nums[left];
            return res;
        }
    };
    
    /**
     * Your NumArray object will be instantiated and called as such:
     * NumArray* obj = new NumArray(nums);
     * int param_1 = obj->sumRange(left,right);
     */