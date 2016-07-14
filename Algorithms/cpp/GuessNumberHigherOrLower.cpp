// Source : https://leetcode.com/problems/guess-number-higher-or-lower/
// Author : Ke Li
// Date   : 2016-07-14

/*************************************************************************************** 
 *
 * We are playing the Guess Game. The game is as follows: 
 * 
 * I pick a number from 1 to n. You have to guess which number I picked.
 * 
 * Every time you guess wrong, I'll tell you whether the number is higher or lower.
 * 
 * You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, 
 * or 0):
 * 
 * -1 : My number is lower
 *  1 : My number is higher
 *  0 : Congrats! You got it!
 * 
 * Example:
 * 
 * n = 10, I pick 6.
 * 
 * Return 6.
 ***************************************************************************************/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    // solve this problem by binarysearch
    int guessNumber(int n) {
        long long int l = 1, r = n;
        while (l <= r) {
            long long int m = (l + r) / 2;
            int answer = guess(m);
            if (answer == -1) {
                r = m - 1;
            } else if (answer == 0) {
                return m;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};
