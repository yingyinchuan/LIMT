class Solution 
{
public:
    bool isUnique(string astr) 
    {
        if(astr.length() > 26)
            return false;
        int bitMap = 0;
        for(auto ch : astr)
        {
            int i = ch - 'a';
            if(bitMap >> i & 1)
                return false;
            bitMap |= 1 << i;
        }
        return true;
    }
};