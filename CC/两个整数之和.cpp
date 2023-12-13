class Solution 
{
public:
    int getSum(int a, int b) 
    {
        int c = 0;
        
        do
        {
            c = (a & b) << 1;
            a ^= b;
            b = c;
        }while(c);

        return a;
    }
};