class Solution {
public:
    int reverseBits(int n) {
        unsigned int num = (unsigned int)n;
        unsigned int ans =0;
 for (int i = 0; i < 32; i++)
    {
        ans = (ans << 1) | (n&1);
        n>>=1;
    }
     return (int)ans;
    }
};