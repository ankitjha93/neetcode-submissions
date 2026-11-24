class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        int zeroCount = 0;

        for (int num : nums) {
            if (num != 0) {
                prod *= num;
            } else {
                zeroCount++;
            }
        }

        if (zeroCount > 1) {
            return vector<int>(n, 0);
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (zeroCount == 1) {
                if (nums[i] == 0) {
                    ans[i] = prod;
                }
                
            }else{
                 ans[i] = prod/nums[i];
            }
        }
        return ans;
    }
};
