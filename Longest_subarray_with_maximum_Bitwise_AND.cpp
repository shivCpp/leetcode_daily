class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi =  *max_element(nums.begin(), nums.end());
        int longest = 0 , currleng = 0;
        for(int num : nums)
        {
            if(num == maxi)
            {
                currleng++;
                longest = max(longest, currleng);
            }
            else
            {
                currleng = 0;
            }
        }

        return longest;
    }

};
