class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mp;

        for (auto it : nums) {
            pq.push(it);
            mp[it]++;
        }

        int ans = 0;

        while (!pq.empty()) {
            auto num = pq.top();
            pq.pop();

            int len = 0;

            while (mp.find(num) != mp.end() && mp[num] != 0) {
                mp[num]--;
                num++;
                len++;
            }

            ans = max(ans, len);
        }
        return ans;
    }
};
