
/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 * 
 * Idea.
 *  1. Find the magnitude of x.
 *  2. Compare the first and final value of x.
 *  3. Go on.
 *  4. Test special cases.
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else if(x >=0 && x < 10)
            return true;

        int magnitude = 10;
        while( (x / magnitude) >= 10)
            magnitude *= 10;

        while( (x / magnitude) == (x % 10) )
        {
            x = ( (x % magnitude) / 10 );
            if(x == 0)
                return true;
            magnitude /= 100;

            unsigned int zero_num = 0;
            while(x / magnitude == 0)
            {
                zero_num++;
                magnitude /= 10;
            }
            for(int i = 0; i < zero_num; i++)
            {
                if(x % 10 != 0)
                    return false;
                x /= 10;
                if(x < 10 && i == zero_num - 1)
                    return true;
                magnitude /= 10;
            }

            if(x < 10)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    bool res1 = s.isPalindrome(121);
    bool res2 = s.isPalindrome(123454321);
    bool res3 = s.isPalindrome(12345321);
    bool res4 = s.isPalindrome(10001);
    bool res5 = s.isPalindrome(-121);
    bool res6 = s.isPalindrome(12355321);
    /** 
     * For the cases below.
     * If we use the code 
            while( (x / magnitude) == (x % 10) )
            {
                x = ( (x % magnitude) / 10 );
                if(x < 10)
                    return true;
                magnitude /= 100;
            }
     * We can only get right answer from the cases before, but not after.
     * Such as 1006001, we will get 600 after the first step in while-loop.
     * So we need to consider the zero-values, which are essential.
     * Idea.
     *  For x = 1006001, magnitude = 1000000
     *  after first step in while-loop, x = 600, magnitude = 10000,
     *  magnitude is greater than x by two magnitude,
     *  so there are two zero value between number 1 and 6.
     */
    bool res7 = s.isPalindrome(1006001);
    bool res8 = s.isPalindrome(1002010001);
    bool res9 = s.isPalindrome(102060201);
    
    bool res10 = s.isPalindrome(1000021);
    bool res11 = s.isPalindrome(1000030001);

    return 0; 
}
