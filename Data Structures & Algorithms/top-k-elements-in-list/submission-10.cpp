class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        for (int num : nums) {
            count[num]++;
        }

        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        for (const auto& p : count) {
            bucket[p.second].push_back(p.first);
        }

        vector<int> ans;
        for (int i = n; i >= 0; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
