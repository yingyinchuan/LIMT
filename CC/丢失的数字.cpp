class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        vector<int> nums2(nums.size() + 1);
        for(int i = 0; i < nums2.size(); i++)
            nums2[i] = i;
        int ret = 0;
        for(auto a : nums)
            ret ^= a;
        for(auto a : nums2)
            ret ^= a;
        return ret;
    }
};