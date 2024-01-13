class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> vals;
        int L = 0, R = 1, len = 1;
        vals.insert(nums[0]); // insert the first value
        int n = nums.size();
        while(R < n)
        {
            int mini = 1000000000, maxi = 0;
            if(L != R)
            {
                mini = *vals.begin();
                maxi = *vals.rbegin();
            }
            if(max(maxi, nums[R]) - min(mini, nums[R]) <= limit)
            {
                vals.insert(nums[R]);
                R++;
            }   
            else
            {
                vals.erase(vals.lower_bound(nums[L]));
                L++;
            }     
            len = max(len, R - L);
        }

        return len;
    }
};
