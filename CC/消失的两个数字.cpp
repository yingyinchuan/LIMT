class Solution 
{
public:
    vector<int> missingTwo(vector<int>& nums) 
    {
        int tmp = 0;
        for(int i = 1; i <= nums.size() + 2; i++)
            tmp ^= i;
        for(auto x : nums)
            tmp ^= x;
        int flag = 0;
        while(true)
        {
            if(tmp >> flag & 1)
                break;
            flag++;
        }
        int a = 0, b = 0;
        for(int i = 1; i <= nums.size() + 2; i++)
            i >> flag & 1 == 1 ? a ^= i : b ^= i;
        for(auto x : nums)
            x >> flag & 1 == 1 ? a ^= x : b ^= x;
        return {a, b};
    }
};