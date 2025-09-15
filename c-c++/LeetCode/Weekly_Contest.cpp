#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<bool> ans(n, false);
        bitset<10001> dp; // Stores sums of "small" numbers
        dp[0] = 1;
        
        int small_idx = 0; // Tracks numbers processed into dp

        // Precomputing prefix sums helps optimize the max_possible check
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        for (int cap = 1; cap <= n; cap++) {
            // Step 1: Update dp with any new "small" numbers
            while (small_idx < n && nums[small_idx] <= cap) {
                dp |= dp << nums[small_idx];
                small_idx++;
            }

            // Optional: Early exit if k is impossible
            int count_large = n - small_idx;
            long long max_possible = prefix[small_idx] + (long long)count_large * cap;
            if (k > max_possible) {
                ans[cap - 1] = false;
                continue;
            }

            // Step 2: Check if k is possible with the current dp and cap
            bool possible = false;
            // Check if k = (sum_from_small) + m * cap
            for (int m = 0; m <= count_large; m++) {
                int needed_sum_from_small = k - m * cap;
                if (needed_sum_from_small < 0) {
                    break;
                }
                if (needed_sum_from_small < dp.size() && dp[needed_sum_from_small]) {
                    possible = true;
                    break;
                }
            }
            ans[cap - 1] = possible;
        }

        return ans;
    }
};



int main(){

    return 0;
}