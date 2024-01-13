class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> mini, maxi;
        mini.push_back(0);
        maxi.push_back(0);
        int L = 0, R = 1, len = 1;
        int n = nums.size();
        while(R < n)
        {
            int min_val = 1000000000, max_val = 0;
            if(L != R)
            {
                min_val = nums[mini[0]];
                max_val = nums[maxi[0]];
            }
            if(max(max_val, nums[R]) - min(min_val, nums[R]) <= limit)
            {
                while(!mini.empty() && nums[R] < nums[mini.back()])
                    mini.pop_back();
                while(!maxi.empty() && nums[R] > nums[maxi.back()])
                    maxi.pop_back();
                mini.push_back(R);
                maxi.push_back(R);
                R++;
            }   
            else
            {
                if(mini.front() == L)
                    mini.pop_front();
                if(maxi.front() == L)
                    maxi.pop_front();
                L++;
            }     
            len = max(len, R - L);
        }

        return len;
    }
};
