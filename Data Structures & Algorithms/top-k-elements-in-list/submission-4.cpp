class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequency
        unordered_map<int, int> count;

        for (int num : nums) {
            count[num]++;
        }

        // Step 2: Create buckets
        vector<vector<int>> bucket(nums.size() + 1);

        // Step 3: Put numbers into frequency buckets
        for (auto& p : count) {
            bucket[p.second].push_back(p.first);
        }

        // Step 4: Extract top K frequent elements
        vector<int> res;

        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (int num : bucket[i]) {
                res.push_back(num);

                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res;
    }
};
