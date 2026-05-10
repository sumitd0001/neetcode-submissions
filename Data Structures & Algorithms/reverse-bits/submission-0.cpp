class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int newn = 0;
        int i = 0;
        while (n) {
            if (n & 1) newn += 1 << (31 - i);
            else newn += 0 << (31-i);
            i++;
            n = n >> 1;
        }
        return newn;
    }
};
