class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int ret = 0;
        for(int i = 0; i < 32; i++)
        {
            int sum = 0;
            for(auto x : nums)
                sum += (x >> i) & 1;
            ret ^= (sum % 3) << i;
        }
        return ret;
    }
};