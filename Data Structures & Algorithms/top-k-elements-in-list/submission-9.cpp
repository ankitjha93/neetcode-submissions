class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        for (int num : nums) {
            count[num]++;
        }

        priority_queue < pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(const auto &p : count){
             minHeap.push({p.second, p.first});
             if(minHeap.size() > k){
                 minHeap.pop();
             }
        }

        vector<int> ans;
        while(!minHeap.empty()){
             ans.push_back(minHeap.top().second);
             minHeap.pop();
        }
        return ans;

    }
};
